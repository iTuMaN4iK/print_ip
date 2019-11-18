/**
 * @file include.h
 * @author PerminovDV (swaga.ituman4ik@gmail.com)
 * @brief Шаблоные функции печати условного ip адресса
 * @version 0.1
 * @date 2019-10-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once
#include <iostream>
#include <list>
#include <string>
#include <type_traits>
#include <vector>

/**
 * @brief Функция печати числовых типов
 * 
 * @tparam T 
 * @param val 
 * @return std::enable_if<std::is_integral<T>::value, std::string>::type 
 */
template <class T>
typename std::enable_if<std::is_integral<T>::value, std::string>::type
print_ip(T val) {
  std::string result{""};
  int countByte = sizeof(val) - 1;
  for (int i = countByte; i >= 0; i--) {
    result += std::to_string(
        static_cast<uint>(static_cast<unsigned char>(val >> (8 * i))));
    if (i > 0)
      result += ".";
  }
  return result;
}
/**
 * @brief Функция печати контейнеров
 * 
 * @tparam T 
 * @param val 
 * @return std::enable_if<std::is_same<T, std::string>::value, std::string>::type 
 */
template <class T>
typename std::enable_if<std::is_same<T, std::string>::value, std::string>::type
print_ip(T val) {
  return val;
}
/**
 * @brief Печать 
 * 
 * @tparam T 
 * @param val 
 * @return std::enable_if<(!std::is_same<T, std::string>::value) &&
(!std::is_integral<T>::value),
std::string>::type 
 */
template <class T>
typename std::enable_if<(!std::is_same<T, std::string>::value) &&
                            (!std::is_integral<T>::value),
                        std::string>::type
print_ip(T &val) {
  std::string result{""};
  size_t size = val.size();
  if (size == 0) {
    return result;
  }
  for (const auto &i : val) {
    result += print_ip<
        typename std::iterator_traits<decltype(val.begin())>::value_type>(i);
    if (--size != 0) {
      result += "..";
    }
  }
  return result;
}