/*-------------------------------------------------------------------
LibCFile.h: Library for C-style File Operations
Author: ictplusud@gmail.com (Department of Game SW Engineering, Mokwon University)

Copyright ⓒ 2023-Forever Mokwon Game, Korea.
All Rights Reserved. Personal and non-commercial purpose only.
-------------------------------------------------------------------*/

#pragma once

#include <stdio.h>
#include <stdbool.h>

/*-------------------------------------------------------------------
Definition of Data or Types
-------------------------------------------------------------------*/
enum FILE_RW_MODE // 파일 읽기, 쓰기, 추가 모드
{
	FM_READ, FM_WRITE, FM_APPEND
};

typedef FILE* cfileptr; // C-style file pointer
typedef enum FILE_RW_MODE filemode;

/*-------------------------------------------------------------------
Basic File Functions
-------------------------------------------------------------------*/
// 파일 닫기
inline void closefile(cfileptr fp)
{
	fclose(fp);
}

// 문자 ch가 파일의 끝(EOF: end of file)인가?
inline bool iseof(int ch)
{
	return ch == EOF;
}

// 파일 포인터가 정상인지 확인
inline bool isvalidfile(cfileptr fp)
{
	return fp != NULL;
}

// 텍스트 파일로 열기
inline cfileptr openfile(const char* filename, filemode fm)
{
	cfileptr fp = NULL;
	char modestr[] = " ";
	switch (fm)
	{
	case FM_READ:  modestr[0] = 'r'; break;
	case FM_WRITE: modestr[0] = 'w'; break;
	case FM_APPEND: modestr[0] = 'a'; break;
	}
	fopen_s(&fp, filename, modestr);
	return fp;
}

// 이진(binary) 파일로 열기
inline cfileptr openbinfile(const char* filename, filemode fm)
{
	cfileptr fp = NULL;
	char modestr[] = " b";
	switch (fm)
	{
	case FM_READ:  modestr[0] = 'r'; break;
	case FM_WRITE: modestr[0] = 'w'; break;
	case FM_APPEND: modestr[0] = 'a'; break;
	}
	fopen_s(&fp, filename, modestr);
	return fp;
}

/*-------------------------------------------------------------------
Read Text File Functions
-------------------------------------------------------------------*/
// 파일에서 문자 하나 읽기
inline int cfgetc(cfileptr fp)
{
	return fgetc(fp);
}

/*-------------------------------------------------------------------
Read Binary File Functions
-------------------------------------------------------------------*/
// 이진 파일에서 실수 읽기
inline double cfreaddbl(cfileptr fp)
{
	double x;
	fread(&x, sizeof(double), 1, fp);
	return x;
}

// 이진 파일에서 정수 읽기
inline int cfreadint(cfileptr fp)
{
	int n;
	fread(&n, sizeof(int), 1, fp);
	return n;
}

/*-------------------------------------------------------------------
Write Text File Functions
-------------------------------------------------------------------*/
// 한 글자를 파일에 쓰기
inline void cfputc(cfileptr fp, int c)
{
	fputc(c, fp);
}

// 한 글자를 파일에 쓰기; 마지막에 \n을 씀
inline void cfputcln(cfileptr fp, int c)
{
	cfputc(fp, c);
	cfputc(fp, '\n');
}

// 실수를 텍스트로 쓰기
inline void cfputdbl(cfileptr fp, double x)
{
	fprintf(fp, "%g", x);
}

// 실수를 텍스트로 쓰기; 마지막에 \n을 씀
inline void cfputdblln(cfileptr fp, double x)
{
	cfputdbl(fp, x);
	cfputc(fp, '\n');
}

// 정수를 텍스트로 쓰기
inline void cfputint(cfileptr fp, int n)
{
	fprintf(fp, "%d", n);
}

// 정수를 텍스트로 쓰기; 마지막에 \n을 씀
inline void cfputintln(cfileptr fp, int n)
{
	cfputint(fp, n);
	cfputc(fp, '\n');
}

// 문자열을 파일에 쓰기; 마지막에 \n을 쓰지 않음
inline void cfputs(cfileptr fp, const char* str)
{
	fputs(str, fp);
}

// 문자열을 파일에 쓰기; 마지막에 \n을 씀
inline void cfputsln(cfileptr fp, const char* str)
{
	fputs(str, fp);
	cfputc(fp, '\n');
}

/*-------------------------------------------------------------------
Write Binary File Functions
-------------------------------------------------------------------*/
// 이진 파일에 실수 쓰기
inline void cfwritedbl(cfileptr fp, double x)
{
	fwrite(&x, sizeof(double), 1, fp);
}

// 이진 파일에 정수 쓰기
inline void cfwriteint(cfileptr fp, int n)
{
	fwrite(&n, sizeof(int), 1, fp);
}

/*-------------------------------------------------------------------
Revision Records
---------------------------------------------------------------------
C(2023-03-24): create for simple file operations
-------------------------------------------------------------------*/