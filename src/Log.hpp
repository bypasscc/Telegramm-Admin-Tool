#pragma once
#include "Headers.h"

class Log
{
	std::ofstream write_log;
	int str_count;
public:
	Log(): str_count(0)
	{	}

	~Log() 
	{
		write_log.close();
	}

	void operator<<(std::string log_message);
};