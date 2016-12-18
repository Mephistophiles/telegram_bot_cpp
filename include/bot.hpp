#ifndef BOT_H

#define BOT_H

#include <string>
#include <vector>
#include <jansson.h>
class Http;
class Update;
class Message;

class Bot {
	public:
		Bot(void);
		Bot(std::string token);
		void SetToken(std::string token);

		std::string GetMe(void);
		bool GetUpdates(void);
		void sendMessage(Message &message, std::string text);

		bool UpdatesIsEmpty(void);
		~Bot(void);
		Update GetUpdate(void);

	private:
		json_t *last_request;
		json_t *Request(std::string url);
		std::vector<Update> updates;
		std::string GetRequestString(std::string method);
		std::string GetRequestString(std::string method, std::string params);
		std::string GetRequestString(std::string method, std::vector<std::string> params);
		std::string token;
		Http *http;
		/* data */
};

#endif /* end of include guard: BOT_H */
