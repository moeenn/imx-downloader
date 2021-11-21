#ifndef __ARGSPARSER_HPP__
#define __ARGSPARSER_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

struct Flag {
  std::string flag;
  std::string desc;
  std::string *target;
};

class ArgsParser {
private:
  uint m_count;
  std::vector<std::string> m_args;
  std::string m_bin_name;
  std::vector<Flag> m_flags;
  int getFlagIndex(std::string flag);

public:
  ArgsParser(int argc, char *argv[]);
  void flag(std::string flagName, std::string desc, std::string *target);
  void parse();
  void printHelp();
};

#endif