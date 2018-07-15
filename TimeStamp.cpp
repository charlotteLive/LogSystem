#include "stdafx.h"
#include "TimeStamp.h"
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>

#ifdef WIN32
#pragma warning(disable:4996)
#endif

TimeStamp::TimeStamp() :
	m_currentTime(std::chrono::system_clock::now())
{

}

TimeStamp::TimeStamp(TimePoint & time_) :
	m_currentTime(time_)
{
}


TimeStamp::~TimeStamp()
{
}

std::string TimeStamp::ToString()
{
	auto ms = m_currentTime.time_since_epoch();
	auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(ms).count();
	auto const msecs = diff % 1000;

	std::time_t t = std::chrono::system_clock::to_time_t(m_currentTime);
	std::stringstream ss;
	ss << std::put_time(std::localtime(&t), "%Y-%m-%d %X") << "." << msecs;
	return ss.str();
}
