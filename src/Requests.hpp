#pragma once
#include "Headers.h"

class Requests
{
	HINTERNET hSocket;
	HINTERNET hConnection;
	HINTERNET hRequest = nullptr;
public:
	Requests() {}

	Requests(const char* useragent, const char* url)
	{
		try {
			hSocket = InternetOpenA(useragent, INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);

			if (!hSocket) {
				throw std::exception("Error to open connection! Error: ");
			}

			hConnection = InternetConnectA(hSocket, url, INTERNET_DEFAULT_HTTPS_PORT, 0, 0, INTERNET_SERVICE_HTTP, 0, 0);

			if (!hConnection) {
				throw std::exception("Error to connect url! Error: ");
			}

		} catch (const std::exception& ex) {
			std::cout << ex.what() << GetLastError() << std::endl;
			exit(1);
		}
	}

	~Requests()
	{
		InternetCloseHandle(hSocket);
		InternetCloseHandle(hConnection);
	}

	std::string Get_Request(const char* metod, const char* path, const char* content);
};