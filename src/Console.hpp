#ifndef __CONSOLE_HPP__
#define __CONSOLE_HPP__

#include <iostream>
#include <mutex>

class Console {
private:
  static std::mutex s_mutex;

public:
  static void log(const std::string &message);
};

#endif