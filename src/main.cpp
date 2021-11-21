#include "./ArgsParser.hpp"
#include "./Downloader.hpp"
#include "./Imx.hpp"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  ArgsParser parser{argc, argv};

  std::string start;
  std::string end;
  std::string year;
  {
    parser.flag("--start", "ID of the first image in gallery", &start);
    parser.flag("--end", "ID of the last image in gallery", &end);
    parser.flag("--year", "Year the gallery was uploaded. Format: YY", &year);
    parser.parse();
  }

  Imx imx{start, end, year};

  uint count = imx.imageCount();
  uint i = 1;

  for (const auto &url : imx.urlRange()) {
    std::cout << '[' << i << " of " << count << "] " << url.second << std::endl;
    Downloader::download(url.first, url.second);
    i++;
  }
}