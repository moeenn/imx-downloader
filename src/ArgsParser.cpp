#include "./ArgsParser.hpp"
#include <cstdlib>

ArgsParser::ArgsParser(int argc, char *argv[]) : m_count(argc) {
  for (int i = 0; i < argc; i++)
    m_args.push_back(std::string(argv[i]));

  m_bin_name = m_args[0];
}

/** register a flag with useful information */
void ArgsParser::flag(std::string flagName, std::string desc,
                      std::string *target) {

  Flag flag{flagName, desc, target};
  m_flags.push_back(flag);
}

void ArgsParser::parse() {
  for (const Flag &flag : m_flags) {
    const int flagIndex = this->getFlagIndex(flag.flag);

    if (flagIndex == -1 || (uint)flagIndex + 1 >= m_count) {
      this->printHelp();
      std::exit(EXIT_FAILURE);
    }

    *(flag.target) = m_args[flagIndex + 1];
  }
}

/** find provided flag in the list of all flags */
int ArgsParser::getFlagIndex(std::string flag) {
  for (uint i = 0; i < m_count; i++) {
    if (m_args[i] == flag)
      return i;
  }

  return -1;
}

/** print the usage infomation in case of any problem with arguments */
void ArgsParser::printHelp() {
  std::cout << "\nUsage: " << m_bin_name << " [flags]\n\n";

  for (const Flag &flag : m_flags)
    std::cout << flag.flag << "\t\t" << flag.desc << '\n';
}