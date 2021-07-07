#pragma once
#include "Telegram.hpp"

namespace Tg
{
	void Delay(double seconds)
	{
		Sleep(seconds * 1000);
	}

	void Init(Telegram& start)
	{
		std::string on_start_message =
			"The computer is on! Example commands:  /cmd  /exit  /shutdown";

		HWND hWnd = GetConsoleWindow();

		//if (!ShowWindow(hWnd, SW_HIDE)) {
			//MessageBoxA(0, "Error to hide window!", MB_OK, 0);
		//}

		start.Send_Message(on_start_message.c_str());
	}
}