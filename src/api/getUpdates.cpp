#include <bot.hpp>
#include <http.hpp>
#include <update.hpp>

bool Bot::GetUpdates(void)
{
    this->updates.clear();
    json_t *result = Request(GetRequestString("GetUpdates"));
    json_t *update;
    size_t index;

    json_array_foreach(result, index, update) {
        this->updates.push_back(Update(update));
    }

    return this->updates.size() > 0;
}

Update Bot::GetUpdate(void) {
    Update update = this->updates.back();
    this->updates.pop_back();
    return update;
}
