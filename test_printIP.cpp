#include "include.h"
#include <gtest/gtest.h>

TEST(printIP,typeChar){
    EXPECT_EQ(print_ip<char>(char(-1)),"255");
    EXPECT_EQ(print_ip<char>(char(-2)),"254");
}
TEST(printIP,typeShor){
    EXPECT_EQ(print_ip<short>(short(0)),"0.0");
}
TEST(printIP,typeInt){
    EXPECT_EQ(print_ip<int>(int(2130706433)),"127.0.0.1");
}
TEST(printIP,typeLong){
    EXPECT_EQ(print_ip<long>(long(8875824491850138409)),"123.45.67.89.101.112.131.41");
}
TEST(printIP,typeString){
    EXPECT_EQ(print_ip<std::string>(std::string("127.0.0.1")),"127.0.0.1");
}
TEST(printIP,typeList){
    std::list<int> li{2130706433,2130706433};
    EXPECT_EQ(print_ip<std::list<int>>(li),"127.0.0.1..127.0.0.1");
    std::list<short> ls{0,0};    
    EXPECT_EQ(print_ip<std::list<short>>(ls),"0.0..0.0");
}
TEST(printIP,typeVector){
    std::vector<int> li{2130706433,2130706433};
    EXPECT_EQ(print_ip<std::vector<int>>(li),"127.0.0.1..127.0.0.1");
    std::vector<short> ls{0,0};    
    EXPECT_EQ(print_ip<std::vector<short>>(ls),"0.0..0.0");
}
