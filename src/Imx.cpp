#include "./Imx.hpp"
#include "./Base36.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string Imx::s_url_base = "https://i002.imx.to/i/2021/01/";
std::string Imx::s_ext = ".jpg";

Imx::Imx(std::string start, std::string end, std::string year)
    : m_start(start), m_end(end), m_year(year) {
  m_start_dec = Base36::decode(m_start);
  m_end_dec = Base36::decode(m_end);
}

std::string Imx::generateURL(std::string id) {
  return s_url_base + m_year + "/" + id + s_ext;
}

std::map<std::string, std::string> Imx::urlRange() {
  std::map<std::string, std::string> urls;

  for (uint32_t i = m_start_dec; i <= m_end_dec; i++) {
    std::string id = Base36::encode(i);
    std::string url = generateURL(id);

    std::pair<std::string, std::string> record = std::make_pair(id, url);
    urls.insert(record);
  }

  return urls;
}