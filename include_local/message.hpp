#ifndef TELEGRAMBOT_MESSAGE_HPP
#define TELEGRAMBOT_MESSAGE_HPP

#include <string>
#include <cstdlib>
#include <jansson.h>
#include <chat.hpp>
#include <user.hpp>


class Message {
    private:
        size_t message_id;
        User *from;
        int date;
        Chat *chat;
        std::string text;

    public:
        Message(json_t *message);
        void Reply(std::string text);
        std::string GetText(void);
        size_t GetChatId(void);
        ~Message(void);
};


#endif //TELEGRAMBOT_MESSAGE_HPP
