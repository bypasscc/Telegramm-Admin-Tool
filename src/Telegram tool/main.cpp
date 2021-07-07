#include "TGBotFunc.hpp"

using namespace Tg;

int main()
{
	Telegram tg("", "");
	
	Init(tg);

	while(true) 
	{
		Delay(0.5);

		std::string last_message = tg.Get_Last_Message();

		if (last_message == "/cmd") {
			system("start cmd");
		}

		else if (last_message == "/shutdown") {
			system("shutdown -p");
		}

		else if (last_message == "/reboot") {
			system("shutdown -r");
		}

		else if (last_message == "/exit") {
			break;
		}

		else if (last_message == "/pwd") {
			char buffer[MAX_PATH];

			GetCurrentDirectoryA(MAX_PATH, buffer);
			tg.Send_Message(buffer);
		}
	}
}