#pragma once
#include "Requests.hpp"

class Telegram : Requests
{
    const char* bot_api;
    const char* chat_id;
    mutable int error_counts; 
public:
    explicit Telegram(const char* bot_api = nullptr, const char* chat_id = nullptr) :
             Requests("TgHelper", "api.telegram.org"),
                bot_api(bot_api), chat_id(chat_id), error_counts(0)
                    {   }

    void Send_Message(const char* message) const;

    std::string Get_Last_Message() const;
};