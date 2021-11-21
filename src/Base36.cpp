#include "./Base36.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

int Base36::s_base = 36;
std::string Base36::s_charset = "0123456789abcdefghijklmnopqrstuvwxyz";

uint32_t Base36::decode(std::string encoding) {
  std::reverse(encoding.begin(), encoding.end());
  std::vector<uint16_t> encodingInts;

  for (uint index = 0; index < encoding.length(); index++) {
    size_t f_index = s_charset.find(encoding[index]);
    encodingInts.push_back(f_index);
  }

  uint32_t sum = 0;

  for (uint i = 0; i < encodingInts.size(); i++) {
    uint32_t raised = encodingInts[i] * std::pow(s_base, i);
    sum += raised;
  }

  return sum;
}

/** convert uint32 to base36 encoding */
std::string Base36::encode(uint32_t decoded) {
  std::string result = "";

  uint32_t quot, rem, decr;
  quot = decoded;

  while (quot > 0) {
    decr = quot;
    quot = std::floor(decr / s_base);
    rem = decr % s_base;

    result = s_charset[rem] + result;
  }

  return result;
}