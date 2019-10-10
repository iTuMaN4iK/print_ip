#include "lib.h"
#include "include.h"
#include <iostream>

template <class T>
void print(T && val){
    std::cout<<print_ip<T>(val)<<std::endl;
}
template <class T>
void print(T & val){
    std::cout<<print_ip<T>(val)<<std::endl;
}
int main (int, char **)
{
    std::cout << "Version: " << version() << std::endl;
    print(char(-1));
    print(short(0));
    print(int(2130706433));
    print(long(8875824491850138409));
    print(std::string("127.0.0.1"));
    print(std::list<int>{2130706433,2130706433});
    print(std::list<short>{0,0});
    print(std::vector<int>{2130706433,2130706433});
    print(std::vector<short>{0,0});

    return 0;

}
