#include <bot.hpp>
#include <http.hpp>

std::string Bot::GetMe(void)
{
    return http->Get(GetRequestString("GetMe"));
}
