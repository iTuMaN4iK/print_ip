#pragma once
#include <string>
#include <type_traits>
#include <list>
#include <vector>
// #include <algorithm>
#include <iostream>


template <class T>
typename std::enable_if<std::is_integral<T>::value, std::string>::type
print_ip(T val){
   std::string result{""};
   int countByte=sizeof(val)-1;
   for (int i=countByte;i>=0;i--){
      result+=std::to_string(static_cast<uint>(static_cast<unsigned char>(val>>(8*i))));
      // print_char(static_cast<char>(val>>(8*i)));
      if (i>0)
         result+=".";
   }
   return result;
}
template <class T>
typename std::enable_if<std::is_same<T,std::string>::value, std::string>::type
print_ip(T val){
   return val;
}
template <class T>
typename std::enable_if<(!std::is_same<T,std::string>::value)&&(!std::is_integral<T>::value),std::string>::type
print_ip(T & val){
   std::string result{""};
   size_t size=val.size();
   if (size==0){
      return result;
   }
   for (const auto & i:val){
      result+=print_ip<typename std::iterator_traits<decltype(val.begin())>::value_type>(i);
      if (--size!=0){
         result+="..";
      }
   }
   return result;
}