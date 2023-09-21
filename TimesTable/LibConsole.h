/*-------------------------------------------------------------------
LibConsole.h: Library for Console Applications
Author: ictplusud@gmail.com (Department of Game SW Engineering, Mokwon University)

Copyright ⓒ 2023-Forever Mokwon Game, Korea.
All Rights Reserved. Personal and non-commercial purpose only.
-------------------------------------------------------------------*/

#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h>

/*-------------------------------------------------------------------
Definition of Data or Types
-------------------------------------------------------------------*/
// 열거형: 콘솔 색깔
enum CON_COLOR {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

/*-------------------------------------------------------------------
Input Functions
-------------------------------------------------------------------*/
// 실수 입력 얻기
inline double getdbl()
{
	double x;
	scanf_s("%lg", &x);
	return x;
}

// 정수 입력 얻기
inline int getint()
{
	int i;
	scanf_s("%d", &i);
	return i;
}

// 키보드에 있는 모든 키를 입력 받음: 단순 알파벳이나 숫자는 _getch()를 이용
inline int getkey()
{
	char key = _getch();
	if (key > 0) return (int)key;
	else
	{
		int key1 = key;
		if (key1 < 0) key1 += 256;
		int key2 = _getch();
		return (key2 << 8) + key1;
	}
}

// 현재 키가 눌러진 상태를 비동기(asynchronous)로 점검: 키 입력을 기다리지 않고 바로 반환; 키는 가상 키(virtual key); 가상 키는 WinUser.h에 정의됨
inline bool iskeydown(int key)
{
	return GetAsyncKeyState(key) & 0x8000;
}

// 키 입력까지 기다리기
inline void waitkey()
{
	while (!_kbhit());
}

/*-------------------------------------------------------------------
Output Functions
-------------------------------------------------------------------*/
// double 출력
inline void putdbl(double x)
{
	printf("%g", x);
}

// double 출력 + 줄 삽입
inline void putdblln(double x)
{
	printf("%g\n", x);
}

// int 출력
inline void putint(int n)
{
	printf("%d", n);
}

// int 출력 + 줄 삽입
inline void putintln(int n)
{
	printf("%d\n", n);
}

// 줄 삽입
inline void putln()
{
	printf("\n");
}

/*-------------------------------------------------------------------
Console Functions
-------------------------------------------------------------------*/
// 커서 크기 얻기: 1~100 사이 값(%로 이해)
inline int getcursorsize()
{
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(handle, &info);
	return (int)info.dwSize;
}

// 커서 가시성 얻기: 보이면 true, 안 보이면 false
inline bool getcursorview()
{
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(handle, &info);
	return (bool)info.bVisible;
}

// 콘솔의 현재 배경색과 글자색 얻기: 출력은 색깔 코드(0~255 = backcol << 4 + textcol)
inline int getconbacktextcol()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return (int)(csbi.wAttributes % 256);
}

// 콘솔의 현재 배경색 얻기: 출력은 색깔 코드(0~15)
inline int getconbackcol()
{
	int backtextcol = getconbacktextcol();
	return backtextcol >> 4;
}

// 콘솔의 현재 글자색 얻기: 출력은 색깔 코드(0~15)
inline int getcontextcol()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return (int)(csbi.wAttributes % 16);
}

// 커서 크기 조정: 기본은 25; 1~100까지 가능(%로 이해)
inline void setcursorsize(int size)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = (BOOL)getcursorview();
	info.dwSize = (DWORD)size;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// 배경색 바꾸기: 기본은 BLACK
inline void setbackcol(int color)
{
	int textcol = getcontextcol();
	WORD backtextcol = (color << 4) | textcol;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backtextcol);
}

// 배경색과 글자색 바꾸기
inline void setbacktextcol(int backcol, int textcol)
{
	WORD backtextcol = (backcol << 4) | textcol;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backtextcol);
}

// 글자색 바꾸기: 기본은 GRAY
inline void settextcol(int color)
{
	int backcol = getconbackcol();
	WORD backtextcol = (backcol << 4) | color;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backtextcol);
}

// 콘솔 전체 배경색과 글자색 변경
inline void setconcol(int backcol, int textcol)
{
	char cmd[] = "color 00";
	char back[2], text[2];
	sprintf_s(back, 2, "%X", backcol);
	sprintf_s(text, 2, "%X", textcol);
	cmd[6] = back[0];
	cmd[7] = text[0];
	system(cmd);
}

// clear screen: 화면 지우기
inline void clrscr()
{
	system("cls");
}

// 콘솔 잠시 멈춤
inline void pausecon()
{
	system("pause");
}

// 콘솔을 sleeptime(단위: 초) 동안 잠 재우기
inline void sleepcon(double sleeptime)
{
	int timems = (int)(sleeptime * 1000 + 0.5); // 반올림
	Sleep(timems);
}

// (x, y) 위치로 커서 이동: x, y는 0부터 시작
inline void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = (SHORT)x, pos.Y = (SHORT)y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 커서 감추기
inline void hidecursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = FALSE;
	info.dwSize = (DWORD)getcursorsize();
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// 커서 보이기
inline void showcursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = TRUE;
	info.dwSize = (DWORD)getcursorsize();
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// (x, y) 위치의 attribute 얻기: 실패하면 -1을 반환
inline int readconattr(int x, int y)
{
	WORD attr;
	COORD pos;
	DWORD read;
	pos.X = (SHORT)x, pos.Y = (SHORT)y;
	ReadConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), &attr, 1, pos, &read);
	return (read == 1) ? (int)attr : -1;
}

// (x, y) 위치의 배경색을 color로 바꾸기: 실패하면 false를 반환
inline bool writebackcol(int x, int y, int color)
{
	WORD attr = readconattr(x, y);
	WORD textcol = attr % 16;
	WORD backtextcol = (color << 4) + textcol;
	attr = ((attr >> 8) << 8) + backtextcol;
	COORD pos;
	DWORD written;
	pos.X = (SHORT)x, pos.Y = (SHORT)y;
	WriteConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), &attr, 1, pos, &written);
	return (written == 1) ? true : false;
}

// (x, y) 위치의 배경색과 글자색 바꾸기: 실패하면 false를 반환
inline bool writebacktextcol(int x, int y, int backcol, int textcol)
{
	WORD attr = readconattr(x, y);
	WORD backtextcol = (backcol << 4) | textcol;
	attr = ((attr >> 8) << 8) + backtextcol;
	COORD pos;
	DWORD written;
	pos.X = (SHORT)x, pos.Y = (SHORT)y;
	WriteConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), &attr, 1, pos, &written);
	return (written == 1) ? true : false;
}

// (x, y) 위치의 글자색을 color로 바꾸기: 실패하면 false를 반환
inline bool writetextcol(int x, int y, int color)
{
	WORD attr = readconattr(x, y);
	attr = ((attr >> 4) << 4) | color;
	COORD pos;
	DWORD written;
	pos.X = (SHORT)x, pos.Y = (SHORT)y;
	WriteConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), &attr, 1, pos, &written);
	return (written == 1) ? true : false;
}

/*-------------------------------------------------------------------
Console Output Functions
-------------------------------------------------------------------*/
// (x, y)로 이동해서 문자열 s 출력
inline void putsxy(int x, int y, const char* s)
{
	gotoxy(x, y);
	puts(s);
}

/*-------------------------------------------------------------------
Revision Records
---------------------------------------------------------------------
C(2023-02-05): create for C compiler
-------------------------------------------------------------------*/