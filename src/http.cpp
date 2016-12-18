#include "http.hpp"
#include <string.h>
#include <cassert>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <resolv.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>
#include <curl/curl.h>

#include "tools.hpp"

using namespace std;

Http::Http(void) {
	curl_global_init(CURL_GLOBAL_DEFAULT);
}

Http::~Http(void) {
	curl_global_cleanup();
}

static int writer(char *data, size_t size, size_t nmemb, string *buffer) {
	int result = 0;
	if (buffer == NULL)
		goto out;

	result = nmemb * size;
	buffer->append(data, result);

out:
	return result;
}

static void check_error(CURLcode code) {
	if (code == CURLE_OK)
		return;

	fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(code));
}

static CURL *curl_base(string url, string *buffer) {
	CURL *curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

	return curl;
}

string Http::Get(string url) {
	this->buffer.clear();

	CURL *curl = curl_base(url, &this->buffer);
	CURLcode res;

	res = curl_easy_perform(curl);

	check_error(res);

	curl_easy_cleanup(curl);

	return this->buffer;
}

string Http::Post(string url, vector<string> params) {
	this->buffer.clear();

	CURL *curl = curl_base(url, &this->buffer);
	CURLcode res;

	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, StringJoin(params, ",").c_str());

	res = curl_easy_perform(curl);

	check_error(res);

	curl_easy_cleanup(curl);

	return this->buffer;
}
