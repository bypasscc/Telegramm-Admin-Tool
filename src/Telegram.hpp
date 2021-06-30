#pragma once
#include "Requests.hpp"

class Telegram : Requests
{
    const char* bot_api;
    const char* chat_id;
    int error_counts; //понадобится когда напишу свой свобственный класс для обработки ошибок
    Log write_log;
public:
    Telegram() : bot_api(nullptr), chat_id(nullptr), error_counts(0)
    {   }

    Telegram(const char* bot_key, const char* id) : Requests("TgHelper", "api.telegram.org"),
             bot_api(bot_key), chat_id(id), error_counts(0)
    {   }

    void Send_Message(const char* message);

    std::string Get_Last_Message();
};