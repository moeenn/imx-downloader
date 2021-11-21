#ifndef __IMX_HPP__
#define __IMX_HPP__

#include <iostream>
#include <map>

class Imx {
private:
  std::string m_start;
  uint32_t m_start_dec;

  std::string m_end;
  uint32_t m_end_dec;

  std::string m_year;
  static std::string s_url_base;
  static std::string s_ext;

  /** get full url using the image id */
  std::string generateURL(std::string id);

public:
  Imx(std::string start, std::string end, std::string year);

  /** get total number of images in range */
  uint imageCount() { return m_end_dec - m_start_dec + 1; }

  /** generate all urls in provided range */
  std::map<std::string, std::string> urlRange();
};

#endif