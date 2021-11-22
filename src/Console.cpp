#include "./Console.hpp"

std::mutex Console::s_mutex;

void Console::log(const std::string &message) {
  std::lock_guard<std::mutex> guard(s_mutex);
  std::cout << message << std::endl;
}