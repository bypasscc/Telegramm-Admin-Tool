#pragma once
#include "Headers.h"

class Log
{
	std::ofstream write_log;

public:
	Log()
	{	}

	~Log() 
	{
		write_log.close();
	}

	void operator<<(std::string log_message);
};