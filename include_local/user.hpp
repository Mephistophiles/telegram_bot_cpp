#ifndef USER_H

#define USER_H

#include <cstdlib>
#include <string>
#include <jansson.h>

class User {
	private:
		size_t id;
		std::string first_name;
		std::string last_name;
		std::string username;

	public:
		User(size_t id, std::string username);
		User(size_t id, std::string username, std::string first_name, std::string last_name);
		User(json_t *from);
		void setFirstName(std::string first_name);
		void setLastName(std::string last_name);
		std::string getUsername(void);
		std::string getFirstName(void);
		std::string getLastName(void);
		size_t getId(void);
};

#endif /* end of include guard: USER_H */
