#pragma once
#include "Telegram.hpp"

namespace Tg
{
	namespace Utils {
		void Init(Telegram& start)
		{
			//HWND hWnd = GetConsoleWindow();

			//if (!ShowWindow(hWnd, SW_HIDE)) {
				//MessageBoxA(0, "Error to hide window!", MB_OK, 0);
			//}

			start.Send_Message("Your busya has been started!");
		}
	}

	std::string Get_Sys_Process()
	{

	}
}