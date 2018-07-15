#include "stdafx.h"
#include "LogStream.h"

const char digits[] = "9876543210123456789";
const char* zero = digits + 9;
static_assert(sizeof(digits) == 20, "wrong number of digits");

// Efficient Integer to String Conversions, by Matthew Wilson.
template<typename T>
size_t convert(char buf[], T value)
{
	T i = value;
	char* p = buf;

	do
	{
		int lsd = static_cast<int>(i % 10);
		i /= 10;
		*p++ = zero[lsd];
	} while (i != 0);

	if (value < 0)
	{
		*p++ = '-';
	}
	*p = '\0';
	std::reverse(buf, p);

	return p - buf;
}


LogStream::LogStream()
{
}


LogStream::~LogStream()
{
}

LogStream & LogStream::operator<<(short var)
{
	*this << static_cast<int>(var);
	return *this;
}

LogStream & LogStream::operator<<(unsigned short var)
{
	*this << static_cast<int>(var);
	return *this;
}

LogStream& LogStream::operator<<(int var)
{
	FormatFromInt(var);
	return *this;
}

LogStream & LogStream::operator<<(unsigned int var)
{
	FormatFromInt(var);
	return *this;
}

LogStream & LogStream::operator<<(long var)
{
	FormatFromInt(var);
	return *this;
}

LogStream & LogStream::operator<<(unsigned long var)
{
	FormatFromInt(var);
	return *this;
}

LogStream & LogStream::operator<<(long long var)
{
	FormatFromInt(var);
	return *this;
}

LogStream & LogStream::operator<<(unsigned long long var)
{
	FormatFromInt(var);
	return *this;
}

LogStream & LogStream::operator<<(double var)
{
	m_buffer.append(std::to_string(var));
	return *this;
}

LogStream & LogStream::operator<<(float var)
{
	m_buffer.append(std::to_string(var));
	return *this;
}

template<typename T>
void LogStream::FormatFromInt(T var)
{
	if (m_buffer.avail() >= kMaxNumericSize)
	{
		char tmp[kMaxNumericSize];
		size_t len = convert(tmp, var);
		m_buffer.append(tmp, len);
	}
}
