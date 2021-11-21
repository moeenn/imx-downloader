#include "./Downloader.hpp"

void Downloader::download(std::string filename, std::string url) {
  CURL *hnd;
  FILE *fptr;

  if ((fptr = std::fopen(filename.c_str(), "wb")) == NULL) {
    throw std::runtime_error{"Failed to open write destination"};
  }

  hnd = curl_easy_init();
  curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
  curl_easy_setopt(hnd, CURLOPT_URL, url.c_str());
  curl_easy_setopt(hnd, CURLOPT_USERAGENT, "curl/7.74.0");
  curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
  curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
  curl_easy_setopt(hnd, CURLOPT_FTP_SKIP_PASV_IP, 1L);
  curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
  curl_easy_setopt(hnd, CURLOPT_WRITEDATA, fptr);
  curl_easy_setopt(hnd, CURLOPT_VERBOSE, 0);
  curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1);

  curl_easy_perform(hnd);
  curl_easy_cleanup(hnd);
  hnd = NULL;

  fclose(fptr);
}