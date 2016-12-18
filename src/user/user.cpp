#include <user.hpp>
#include <jansson.h>

User::User(size_t id, std::string username) {
	this->id = id;
	this->username = username;
}

User::User(json_t *from) {
	int id;
	const char *username, *last_name, *first_name;

	json_unpack(from, "{s ? i, s ? s, s ? s, s ? s}", "id", &id, "username", &username,
			"last_name", &last_name, "first_name", &first_name);

	this->id = id;
	this->username = username ?:"";
	this->last_name = last_name ?:"";
	this->first_name = first_name ?:"";
}

User::User(size_t id, std::string username, std::string first_name, std::string last_name) {
	this->id = id;
	this->username = username;
	this->first_name = first_name;
	this->last_name = last_name;
}

void User::setFirstName(std::string first_name) {
	this->first_name = first_name;
}

void User::setLastName(std::string last_name) {
	this->last_name = last_name;
}

std::string User::getUsername(void) {
	return this->username;
}

std::string User::getFirstName(void) {
	return this->first_name;
}

std::string User::getLastName(void) {
	return this->last_name;
}

size_t User::getId(void) {
	return this->id;
}
