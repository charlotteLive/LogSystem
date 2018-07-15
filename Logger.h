#pragma once

#include "LogStream.h"
#include <string>
#include "TimeStamp.h"
#include <functional>

using std::string;

class Logger
{
public:
	//��־�ȼ�
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
	static LogLevel m_sFilterLogLevel;    //���ڹ�����־��������������޹ص�
	LogLevel m_logLevel;

	static OutPutFunc m_sOutput;  //��־���Ŀ�꣬����������ļ���Ҳ�����������Ļ

	LogStream m_stream;  //IO��������ʽ�����룬�����m_sOutput����д�����

	TimeStamp m_timeStamp;

	string m_fileName;
};

