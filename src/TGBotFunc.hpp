#pragma once
#include "Telegram.hpp"

namespace Tg 
{
	namespace Utils {
		bool On_Start(Telegram& start)
		{
			if (start.Send_Message("The computer turned on!")) {
				return true;
			}
			return false;
		}
	}
}