#include "http.hpp"
#include "bot.hpp"
#include <iostream>
#include <unistd.h>

int main(void)
{
	Bot *bot = new Bot("208580260:AAFv2-WViGswxlPiJ4cTlPi5VL1UBBj-ZCM");

	while (1) {
		std::cout << bot->GetUpdates() << std::endl;
		sleep(1);
	}

	delete bot;
	return 0;
}
