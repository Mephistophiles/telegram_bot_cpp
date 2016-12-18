#include "bot.hpp"
#include "http.hpp"
#include "tools.hpp"

using namespace std;

Bot::Bot(void)
{
	http = new Http();
}

Bot::Bot(string token)
{
	this->token = token;
	http = new Http();
}

void Bot::SetToken(string token)
{
	this->token = token;
}

Bot::~Bot(void)
{
	delete http;
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

std::string Bot::GetMe(void)
{
	return http->Get(GetRequestString("GetMe"));
}

std::string Bot::GetUpdates(void)
{
	return http->Get(GetRequestString("GetUpdates"));
}

