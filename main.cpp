// main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LogSystem.h"

int main()
{
	unsigned int s = 90;
	bool b = true;
	LOG_DEBUG<< "hello logger "<<s<<" "<<b;
	LogSystem sys;
	sys.InitLogSystem();
	LOG_DEBUG << "hello logger to file" << s << " " << b;
    return 0;
}

