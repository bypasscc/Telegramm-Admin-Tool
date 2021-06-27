#include "Telegram.hpp"

bool Telegram::Send_Message(const char* message)
{
	std::string content = "bot" + std::string(bot_api) + "/sendMessage?text=" + message + "&chat_id=" + chat_id;
	std::string request = Requests::Get_Request("GET", content.c_str(), nullptr);
	json_result = nlohmann::json::parse(request);

	if (request == "" || json_result["ok"] == false) {
		return false;
	} 
	return true;
}

std::string Telegram::Get_Last_Message()
{
	std::string content = "bot" + std::string(bot_api) + "/getUpdates";
	std::string messages = Requests::Get_Request("GET", content.c_str(), nullptr);
	std::string text;

	int message_id_present;
	int id = atoi(chat_id);

	json_result = nlohmann::json::parse(messages);

	for (int i = 0; i < json_result["result"].size(); i++) {
		try {
			if (json_result["result"][i]["message"]["from"]["id"] == id) {
				text = json_result["result"][i]["message"]["text"];
				message_id_present = json_result["result"][i]["update_id"];
			}
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
			break;
		}
	}

	return text;
	//if (text!= и тд){}
	//подумать над тем чтобы функция не возвращала одну и ту же последнюю строку юзера тг/
}
