#ifndef BOT_H

#define BOT_H

#include <string>
#include <vector>
class Http;

class Bot {
	public:
		Bot(void);
		Bot(std::string token);
		void SetToken(std::string token);
		std::string GetMe(void);
		std::string GetUpdates(void);
		~Bot(void);

	private:
		std::string GetRequestString(std::string method);
		std::string GetRequestString(std::string method, std::string params);
		std::string GetRequestString(std::string method, std::vector<std::string> params);
		std::string token;
		Http *http;
		/* data */
};

#endif /* end of include guard: BOT_H */
