#include <message.hpp>
#include <jansson.h>
#include <chat.hpp>
#include <user.hpp>
#include <http.hpp>

Message::Message(json_t *message) {
    int message_id = 0, date = 0;
    json_t *from = NULL, *chat = NULL;
    const char *text = NULL;

    json_unpack(message, "{s ? i, s ? i, s ? o, s ? o, s ? s}",
            "message_id", &message_id, "date", &date,
            "from", &from, "chat", &chat,
            "text", &text);

    this->message_id = message_id;
    this->date = date;
    this->chat = new Chat(chat);
    this->from = new User(from);
    this->text = text ?:"";
}

std::string Message::GetText(void) {
    return this->text;
}

size_t Message::GetChatId(void) {
    return this->chat->GetId();
}

Message::~Message(void) {
    delete this->chat;
    delete this->from;
}
