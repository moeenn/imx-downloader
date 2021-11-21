#ifndef __BASE36_HPP__
#define __BASE36_HPP__

#include <iostream>
#include <string>

class Base36 {
private:
  static int s_base;
  static std::string s_charset;

public:
  static uint32_t decode(std::string encoding);
  static std::string encode(uint32_t decoded);
};

#endif