#include "stdafx.h"
#include "Logger.h"
#include <assert.h>
#include <stdio.h>

string GetBaseName(const char* filename)
{
	string str(filename);
#ifdef WIN32
	char token = '\\';
#else
	char token = '/';
#endif //  _WIN32__
	auto pos = str.find_last_of(token);
	return str.substr(pos+1);
}

void DefaultOutput(const char* msg, unsigned int len)
{
	size_t n = fwrite(msg, 1, len, stdout);
	//FIXME check n
	(void)n;
	//assert(len == n);
}

static const char* logLevelName[Logger::NUM_LOG_LEVELS] = {
	"DEBUG",
	"INFO",
	"WARN",
	"ERROR",
	"FATAL",
};

Logger::LogLevel Logger::m_sFilterLogLevel = Logger::DEBUG;
Logger::OutPutFunc Logger::m_sOutput = DefaultOutput;


Logger::Logger(const char* filename, int line, LogLevel level)
{
	m_stream << m_timeStamp.ToString();
	m_stream << " ";
	m_stream << "[" << logLevelName[level] << "] ";
	m_stream << GetBaseName(filename);
	m_stream << ": ";
}

Logger::~Logger()
{
	m_stream << "\n";
	m_sOutput(m_stream.GetDataStr(), m_stream.GetDataLen());
	//flush();
}
