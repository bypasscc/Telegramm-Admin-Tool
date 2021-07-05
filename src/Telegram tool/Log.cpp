#include "Log.hpp"

void Log::operator<<(std::string log_message)
{
	write_log.open("log.txt");

	if (write_log.is_open()) {
		write_log << "LOG_MESSAGE[" + log_message + "]";
		write_log << "\n---------------------" << std::endl;
	}//сделать дозапись в файл
}