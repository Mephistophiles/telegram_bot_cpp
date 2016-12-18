#ifndef CHAT_H

#define CHAT_H

#include <jansson.h>
#include <string>

class Chat {
	private:
		size_t id;
		std::string type;
		std::string title;
		std::string username;
		std::string first_name;
		std::string last_name;

	public:
		Chat(json_t *chat);
		std::string GetType(void);
		std::string GetUsername(void);
		std::string GetTitle(void);
		bool IsPrivate(void);
		bool IsGroup(void);
		bool IsSuperGroup(void);
		bool IsChannel(void);
		size_t GetId(void);
};

#endif /* end of include guard: CHAT_H */
