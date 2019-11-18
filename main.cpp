/**
 * @file main.cpp
 * @author PerminovDV (swaga.ituman4ik@gmail.com)
 * @brief Программа печати условного ip адреса
 * @version 0.1
 * @date 2019-10-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "include.h"
#include "lib.h"
#include <iostream>
/**
 * @brief Функцию печати условного ip-адреса 
 * 
 * @tparam T 
 * @param val 
 */
template <class T> void print(T &&val) {
  std::cout << print_ip<T>(val) << std::endl;
}
/**
 * @brief Функцию печати условного ip-адреса
 * 
 * @tparam T 
 * @param val 
 */
template <class T> void print(T &val) {
  std::cout << print_ip<T>(val) << std::endl;
}
/**
 * @brief 
 * 
 * @return int 
 */
int main(int, char **) {
  std::cout << "Version: " << version() << std::endl;
  print(char(-1));
  print(short(0));
  print(int(2130706433));
  print(long(8875824491850138409));
  print(std::string("127.0.0.1"));
  print(std::list<int>{2130706433, 2130706433});
  print(std::list<short>{0, 0});
  print(std::vector<int>{2130706433, 2130706433});
  print(std::vector<short>{0, 0});

  return 0;
}
