#include <bot.hpp>
#include <message.hpp>

void Bot::sendMessage(Message &message, std::string text) {
    std::vector<std::string> args;
    args.push_back("chat_id=" + std::to_string(message.GetChatId()));
    args.push_back("text=" + text);

	Request(GetRequestString("sendMessage", args));
}

