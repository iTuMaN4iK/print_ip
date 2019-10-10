cmake_minimum_required(VERSION 3.2)

project(print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
# project(print_ip VERSION 0.0.1)

configure_file(version.h.in version.h)

find_package(GTest REQUIRED)

add_executable(print_ip_cli main.cpp)
add_executable(test_printIP test_printIP.cpp)

add_library(helloworld lib.cpp)


set_target_properties(print_ip_cli helloworld test_printIP PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)
target_link_libraries(
    test_printIP ${GTEST_LIBRARIES} gtest_main Threads::Threads
)
target_link_libraries(print_ip_cli PRIVATE
    helloworld
)

if (MSVC)
    target_compile_options(print_ip_cli PRIVATE
        /W4
    )
    target_compile_options(helloworld PRIVATE
        /W4
    )
    target_compile_options(test_printIP PRIVATE
        /W4
    )
else ()
    target_compile_options(print_ip_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(helloworld PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_printIP PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS print_ip_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_printIP test_printIP)
