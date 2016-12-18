#include <jansson.h>
#include <chat.hpp>

Chat::Chat(json_t *chat) {
	int id = 0;
	const char *type = NULL, *username = NULL, *title = NULL, *first_name = NULL, *last_name = NULL;

	json_unpack(chat, "{s ? i, s ? s, s ? s, s ? s, s ? s, s ? s}",
			"id", &id, "type", &type, "username", &username, "title", &title,
			"first_name", &first_name, "last_name", &last_name);

	this->id = id;
	this->type = type ?:"";
	this->title = title ?:"";
	this->last_name = last_name ?:"";
	this->first_name = first_name ?:"";
	this->username = username ?:"";
}

std::string Chat::GetType(void) {
	return this->type;
}

std::string Chat::GetUsername(void) {
	return this->username;
}

std::string Chat::GetTitle(void) {
	return this->title;
}

size_t Chat::GetId(void) {
	return this->id;
}

bool Chat::IsPrivate(void) {
	return this->type == "private";
}

bool Chat::IsGroup(void) {
	return this->type == "group";
}

bool Chat::IsSuperGroup(void) {
	return this->type == "supergroup";
}

bool Chat::IsChannel(void) {
	return this->type == "channel";
}
