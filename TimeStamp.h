#pragma once

#include <string>
#include <chrono>
using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
class TimeStamp
{
public:
	TimeStamp();
	TimeStamp(TimePoint& time_);
	~TimeStamp();
	std::string ToString();

private:
	//std::string m_currentTime;
	TimePoint m_currentTime;
};

