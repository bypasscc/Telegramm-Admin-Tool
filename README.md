# Telegramm-Admin-Tool
## Main function
```cpp
#include "TGBotFunc.hpp"

using namespace Tg;

int main()
{
	std::string result;

	Telegram req("1877711278:AAHgew3S6jli682MDU2Vh6B0GVmf3g4J5kI", "1426945525");

	if (!Utils::On_Start(req)) {
		MessageBoxA(0, "Erorr to start bot!", MB_OK, 0);
		exit(1);
	}

	while (true) {
		Sleep(1000);

		result = req.Get_Last_Message();

		std::cout << result << std::endl;

		if (req.Get_Last_Message() == "/lol") {
			std::cout << "Command run" << std::endl;
		}
	}
}
```
