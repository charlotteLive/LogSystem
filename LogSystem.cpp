#include "stdafx.h"
#include "LogSystem.h"
#include <functional>

#ifdef WIN32
#pragma warning(disable:4996)
#endif

void OutputFile(const char * msg, unsigned int len, FILE* fd)
{
	fwrite(msg, 1, len, fd);
}

LogSystem::LogSystem()
{
}


LogSystem::~LogSystem()
{
	fclose(m_fd);
}

void LogSystem::InitLogSystem()
{

	m_fd = fopen("log.txt", "a+");
	auto f = std::bind(OutputFile, std::placeholders::_1, std::placeholders::_2, m_fd);
	Logger::SetOutputFunc(f);
}
