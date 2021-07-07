#pragma once
#include "Requests.hpp"

class Telegram : public Requests
{
    const char* bot_api;
    const char* chat_id;
    int error_counts; 
public:
    std::string message_update;
public:
    explicit Telegram(const char* bot_api = nullptr, const char* chat_id = nullptr) :
             Requests("TgHelper", "api.telegram.org"),
                bot_api(bot_api), chat_id(chat_id), 
                    error_counts(0) {   }

    void Send_Message(const char* message);

    std::string Get_Last_Message();
};