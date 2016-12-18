#include <bot.hpp>
#include <tools.hpp>
#include <http.hpp>
#include <jansson.h>
#include <update.hpp>

using namespace std;

Bot::Bot(void)
{
	http = new Http();
	this->last_request = NULL;
}

Bot::Bot(string token)
{
	this->token = token;
	this->last_request = NULL;
	http = new Http();
}

void Bot::SetToken(string token)
{
	this->token = token;
}

Bot::~Bot(void)
{
	json_decref(last_request);
	delete http;
}

bool Bot::UpdatesIsEmpty(void) {
	return this->updates.empty();
}

json_t *Bot::Request(string url)
{
	json_decref(last_request);
	string result = http->Get(url);
	last_request = json_loads(result.c_str(), 0, NULL);

	if (!json_is_true(json_object_get(last_request, "ok"))) {
		/* TODO сделать вывод ошибки */
		return NULL;
	}

	return json_object_get(last_request, "result");
}

string Bot::GetRequestString(string method)
{
	return "https://api.telegram.org/bot" + this->token + "/" + method;
}

string Bot::GetRequestString(string method, string params)
{
	return "https://api.telegram.org/bot" + this->token + "/" + method + "?" + params;
}

string Bot::GetRequestString(string method, vector<string> params)
{
	return "https://api.telegram.org/bot" + this->token + "/" + method + "?" + StringJoin(params, "&");
}

