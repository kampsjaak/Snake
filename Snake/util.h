#pragma once
#include <stdint.h>

#ifdef _WIN32
#include "windows.h"
#elif defined(__linux__)
#include <sys/ioctl.h>
#endif


struct consoleSize
{
	uint32_t w, h;
};

consoleSize GetConsoleSize()
{
#ifdef _WIN32
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	uint32_t w = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	uint32_t h = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return { w, h };
#elif defined(__linux__)
	struct winsize w;
	ioctl(fileno(stdout), TIOCGWINSZ, &w);
	return { (uint32_t)w.ws_col,(uint32_t)w.ws_row };
#endif
}


