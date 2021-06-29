#include "Telegram.hpp"

void Telegram::Send_Message(const char* message)
{
	std::string content = "bot" + std::string(bot_api) + "/sendMessage?text=" + message + "&chat_id=" + chat_id;
	nlohmann::json parse_request;

	try {
		std::string get_request = Requests::Get_Request("GET", content.c_str(), nullptr);

		std::string request = get_request == "" ?
			throw std::exception("Error to send get request! Check your internet connection!") :
				get_request;

		parse_request = nlohmann::json::parse(request);

		if (parse_request["ok"] == false) {
			throw std::exception("Bad request: " + parse_request["ok"]["result"]);
			//Посмотреть какие бывают ошибки и обработать их
		}
	}
	catch(const std::exception& ex){
		MessageBoxA(0, ex.what(), MB_OK, 0);
	}
}

std::string Telegram::Get_Last_Message()
{
	std::string content = "bot" + std::string(bot_api) + "/getUpdates";
	int id = atoi(chat_id);
	std::string text;

	try {
		std::string get_request = Requests::Get_Request("GET", content.c_str(), nullptr);

		std::string messages = get_request == "" ?
			throw std::exception("Error to send get request! Check your internet connection!") :
				get_request;

		nlohmann::json json_result = nlohmann::json::parse(messages);

		for (int i = 0; i < json_result["result"].size(); i++) {
			if (json_result["result"][i]["message"]["from"]["id"] == id) {
				text = json_result["result"][i]["message"]["text"];
			}
		}
	}
	catch(const std::exception& ex) {
		MessageBoxA(0, ex.what(), MB_OK, 0);
	}

	return text;
}
	//if (text!= и тд){}
	//подумать над тем чтобы функция не возвращала одну и ту же последнюю строку юзера тг/

