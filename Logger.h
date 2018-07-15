#pragma once

#include "LogStream.h"
#include <string>
#include "TimeStamp.h"
#include <functional>

using std::string;

class Logger
{
public:
	//日志等级
	enum LogLevel
	{
		DEBUG,
		INFO,
		WARN,
		ERROR,
		FATAL,
		NUM_LOG_LEVELS
	};
	using OutPutFunc = std::function<void(const char*, unsigned int)>;

	Logger(const char* filename, int line, LogLevel level);
	~Logger();

public:
	static void SetFilterLogLevel(LogLevel level_)
	{
		if (level_ >= 0 && level_ < NUM_LOG_LEVELS)
		{
			m_sFilterLogLevel = level_;
		} 
		else
		{
			printf("error log level\n");
		}
	}
	static LogLevel FilterLogLevel()
	{
		return m_sFilterLogLevel;
	}

	static void SetOutputFunc(OutPutFunc out)
	{
		m_sOutput = out;
	}

	LogStream& Stream()
	{
		return m_stream;
	}

private:
	static LogLevel m_sFilterLogLevel;    //用于过滤日志，所以是与对象无关的
	LogLevel m_logLevel;

	static OutPutFunc m_sOutput;  //日志输出目标，可以输出到文件，也可以输出到屏幕

	LogStream m_stream;  //IO变量，格式化输入，最后由m_sOutput进行写入操作

	TimeStamp m_timeStamp;

	string m_fileName;
};

