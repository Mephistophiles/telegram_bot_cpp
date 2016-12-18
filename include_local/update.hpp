#ifndef UPDATE_H

#define UPDATE_H

#include <jansson.h>
#include <cstdlib>
#include <string>

class Message;

class Update {
	private:
		size_t update_id;
		Message *message;
	public:
		Update(json_t *update);
		Message &GetMessage(void);
		size_t GetId(void);
		std::string GetTextMessage(void);
};

#endif /* end of include guard: UPDATE_H */

