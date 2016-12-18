#include <bot.hpp>
#include <update.hpp>
#include <iostream>
#include <unistd.h>

int main(void)
{
	Bot *bot = new Bot("208580260:AAFv2-WViGswxlPiJ4cTlPi5VL1UBBj-ZCM");

	while (bot->GetUpdates()) {
		while (!bot->UpdatesIsEmpty()) {
			auto update = bot->GetUpdate();
			std::cout << "Update id " << update.GetId() << " Text: " << update.GetTextMessage() << std::endl;
			bot->sendMessage(update.GetMessage(), "Hey");
		}
	}

	delete bot;
	return 0;
}
