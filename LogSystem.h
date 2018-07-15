#pragma once

#include "Logger.h"
#include <stdio.h>

//TODO: µ¥ÀýÀà
class LogSystem
{
public:
	LogSystem();
	~LogSystem();

	void InitLogSystem();
	void SetFilterLogLevel(Logger::LogLevel lv)
	{
		Logger::SetFilterLogLevel(lv);
	}

private:
	//void OutputFile(const char* msg, unsigned int len);
	FILE* m_fd;
};


// eg. LOGDEBUG << "hello logger";
// format: time, file, line, debugLevel, string
#define LOG_DEBUG if(Logger::FilterLogLevel() <= Logger::DEBUG) \
	Logger(__FILE__, __LINE__, Logger::DEBUG).Stream()
#define LOG_INFO if(Logger::FilterLogLevel() <= Logger::INFO) \
	Logger(__FILE__, __LINE__, Logger::INFO).Stream()
#define LOG_WARN if(Logger::FilterLogLevel() <= Logger::WARN) \
	Logger(__FILE__, __LINE__, Logger::WARN).Stream()
#define LOG_ERROR if(Logger::FilterLogLevel() <= Logger::ERROR) \
	Logger(__FILE__, __LINE__, Logger::ERROR).Stream()
#define LOG_FATAL if(Logger::FilterLogLevel() <= Logger::FATAL) \
	Logger(__FILE__, __LINE__, Logger::FATAL).Stream()