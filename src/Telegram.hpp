#pragma once
#include "Requests.hpp"

class Telegram : public Requests
{
    nlohmann::json json_result;
    const char* bot_api;
    const char* chat_id;
public:
    Telegram() {}

    Telegram(const char* bot_key, const char* id) : Requests("TgHelper", "api.telegram.org"),
        bot_api(bot_key), chat_id(id)
    {   }

    bool Send_Message(const char* message);

    std::string Get_Last_Message();
};