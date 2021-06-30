#include "Requests.hpp"

std::string Requests::Send_Request(const char* metod, const char* path, const char* content)
{
	HINTERNET hRequest;
	std::string result;

	DWORD bytes_read = 0;
	char data[buffer_size];

	hRequest = HttpOpenRequestA(hConnection, metod, path, 
		NULL, NULL, 0, INTERNET_FLAG_RELOAD | INTERNET_FLAG_SECURE, 1);

	if (!hRequest) {
		std::cout << "Error to open request! Error: " << GetLastError() << std::endl;
		exit(1);
	}

	if (content == "") {
		HttpSendRequestA(hRequest, NULL, 0, NULL, 0);
	} else {
		HttpSendRequestA(hRequest, content, sizeof(content), NULL, NULL);
	}

	while (InternetReadFile(hRequest, data, 1024, &bytes_read) && bytes_read > 0) {
		result.append(static_cast<char*>(data), bytes_read);
	} 

	InternetCloseHandle(hRequest);

	return result;
}