#include "Telegram.hpp"

void Telegram::Send_Message(const char* message) const
{
	Log write_log;

	std::string content = "bot" + std::string(bot_api) + "/sendMessage?text=" + message + "&chat_id=" + chat_id;

	write_log << content;

	try {
		std::string get_request = Requests::Send_Request("GET", content.c_str(), nullptr);

		if (get_request == "") {
			throw std::runtime_error("Error to send get request! Check your internet connection! ");
		}

		nlohmann::json parse_request = nlohmann::json::parse(get_request);

		if (parse_request["ok"] == false) {
			throw std::runtime_error("Bad request: " + parse_request["ok"]["result"]);
			//Посмотреть какие бывают ошибки и обработать их
		}
	}
	catch(const std::runtime_error& ex){
		std::string error_message = ex.what() + std::to_string(++error_counts);
		MessageBoxA(0, error_message.c_str(), MB_OK, 0);
	}
}

std::string Telegram::Get_Last_Message() const
{
	std::string content = "bot" + std::string(bot_api) + "/getUpdates";
	std::string text;

	try {
		std::string get_request = Requests::Send_Request("GET", content.c_str(), nullptr);

		if (get_request == "") {
			throw std::runtime_error("Error to send get request! Check your internet connection! ");
		}

		nlohmann::json json_result = nlohmann::json::parse(get_request);

		for (int i = 0; i < json_result["result"].size(); i++) {
			if (json_result["result"][i]["message"]["from"]["id"] == atoi(chat_id)) {
				text = json_result["result"][i]["message"]["text"];
			}
		}
	}
	catch(const std::runtime_error& ex) {
		std::string error_message = ex.what() + std::to_string(++error_counts);
		MessageBoxA(0, error_message.c_str(), MB_OK, 0);
	}

	return text;
}
