#include "./ArgsParser.hpp"
#include "./Console.hpp"
#include "./Downloader.hpp"
#include "./Imx.hpp"
#include "./WorkerPool.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define MAX_THREADS 2

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
  WorkerPool pool{MAX_THREADS};

  uint count = imx.imageCount();
  uint i = 1;

  for (const auto &url : imx.urlRange()) {
    pool.add([&]() {
      std::stringstream msg;
      msg << '[' << i << " of " << count << "] " << url.second;
      Console::log(msg.str());

      Downloader::download(url.first, url.second);
    });

    i++;
  }

  pool.start();
}