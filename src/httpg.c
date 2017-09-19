#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
  return size *nmemb;
}

int main(void)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    res = curl_easy_perform(curl);
    if (CURLE_OK == res) {
      printf("Pagina encontrada com sucesso !!!\n");
      char *ct;
      res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
      if ((CURLE_OK == res) && ct)
        printf("\tO Content-Type da pagina é :%s\n", ct);
    }

    curl_easy_cleanup(curl);
  }

  return 0;
}
