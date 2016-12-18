#include <update.hpp>
#include <message.hpp>

Update::Update(json_t *update) {
	this->update_id = json_integer_value(json_object_get(update, "update_id"));
	this->message = new Message(json_object_get(update, "message"));
}

Message &Update::GetMessage(void) {
	return *this->message;
}

size_t Update::GetId(void) {
	return this->update_id;
}

std::string Update::GetTextMessage(void) {
	return this->message->GetText();
}
