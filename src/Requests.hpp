#pragma once
#include "Headers.h"

const int buffer_size = 1024;

class Requests
{
	HINTERNET hSocket;
	HINTERNET hConnection;
public:
	Requests(): hSocket(nullptr), hConnection(nullptr)
	{}

	Requests(const char* useragent, const char* url)
	{
		hSocket = InternetOpenA(useragent, INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);

		if (!hSocket) {
			std::cout << "Error to open connection! Error: " << GetLastError() << std::endl;
			exit(1);
		}

		hConnection = InternetConnectA(hSocket, url, INTERNET_DEFAULT_HTTPS_PORT, 0, 0, INTERNET_SERVICE_HTTP, 0, 0);

		if (!hConnection) {
			std::cout << "Error to connect url! Error: " << GetLastError() << std::endl;
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