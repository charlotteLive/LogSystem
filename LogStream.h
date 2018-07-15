#pragma once
#include <string>
using std::string;

const int kSmallBuffer = 4000;
const int kLargeBuffer = 4000 * 1000;

template <int SIZE>
class FixBuffer
{
public:
	FixBuffer() : cur(m_data){}
	~FixBuffer() {};
	void append(const char* str, int len)
	{
		if (len < avail())
		{
			memcpy(cur, str, len);
			cur += len;
		}
	}
	void append(const string& str)
	{
		append(str.c_str(), str.length());
	}

	char* end() { return m_data + sizeof(m_data); }
	int avail() { return static_cast<int>(end() - cur); }
	int lenght() { return static_cast<int>(cur - m_data); }
	const char* data() const { return m_data; }

private:
	char m_data[SIZE];
	char* cur;
};


class LogStream
{
	typedef FixBuffer<kSmallBuffer> Buffer;
public:
	LogStream();
	~LogStream();

	void append(const char* data, int len) { m_buffer.append(data, len); }
	const char* GetDataStr() { return m_buffer.data(); }
	const int GetDataLen() { return m_buffer.lenght(); }

	LogStream& operator<<(const string& str)
	{
		m_buffer.append(str.c_str(), str.length());
		return *this;
	}

	LogStream& operator<<(const char* str)
	{
		if (str != nullptr)
		{
			m_buffer.append(str, strlen(str));
		}
		return *this;
	}

	LogStream& operator<<(char ch)
	{
		m_buffer.append(&ch, 1);
		return *this;
	}

	LogStream& operator<<(bool var)
	{
		*this << (var ? "True" : "False");
		return *this;
	}

	LogStream& operator<<(short var);
	LogStream& operator<<(unsigned short var);
	LogStream& operator<<(int var);
	LogStream& operator<<(unsigned int var);
	LogStream& operator<<(long var);
	LogStream& operator<<(unsigned long var);
	LogStream& operator<<(long long var);
	LogStream& operator<<(unsigned long long var);

	LogStream& operator<<(double var);
	LogStream& operator<<(float var);

	template<typename T>
	void FormatFromInt(T var);

private:
	Buffer m_buffer;
	static const int kMaxNumericSize = 32;
};

