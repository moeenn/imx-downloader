#ifndef __DOWNLOADER_HPP__
#define __DOWNLOADER_HPP__

#include <iostream>
#include <curl/curl.h>
#include <curl/easy.h>

class Downloader {
public:
  static void download(std::string filename, std::string url);
};

#endif