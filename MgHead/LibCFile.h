/*-------------------------------------------------------------------
LibCFile.h: Library for C-style File Operations
Author: ictplusud@gmail.com (Department of Game SW Engineering, Mokwon University)

Copyright �� 2023-Forever Mokwon Game, Korea.
All Rights Reserved. Personal and non-commercial purpose only.
-------------------------------------------------------------------*/

#pragma once

#include <stdio.h>
#include <stdbool.h>

/*-------------------------------------------------------------------
Definition of Data or Types
-------------------------------------------------------------------*/
enum FILE_RW_MODE // ���� �б�, ����, �߰� ���
{
	FM_READ, FM_WRITE, FM_APPEND
};

typedef FILE* cfileptr; // C-style file pointer
typedef enum FILE_RW_MODE filemode;

/*-------------------------------------------------------------------
Basic File Functions
-------------------------------------------------------------------*/
// ���� �ݱ�
inline void closefile(cfileptr fp)
{
	fclose(fp);
}

// ���� ch�� ������ ��(EOF: end of file)�ΰ�?
inline bool iseof(int ch)
{
	return ch == EOF;
}

// ���� �����Ͱ� �������� Ȯ��
inline bool isvalidfile(cfileptr fp)
{
	return fp != NULL;
}

// �ؽ�Ʈ ���Ϸ� ����
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

// ����(binary) ���Ϸ� ����
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
// ���Ͽ��� ���� �ϳ� �б�
inline int cfgetc(cfileptr fp)
{
	return fgetc(fp);
}

/*-------------------------------------------------------------------
Read Binary File Functions
-------------------------------------------------------------------*/
// ���� ���Ͽ��� �Ǽ� �б�
inline double cfreaddbl(cfileptr fp)
{
	double x;
	fread(&x, sizeof(double), 1, fp);
	return x;
}

// ���� ���Ͽ��� ���� �б�
inline int cfreadint(cfileptr fp)
{
	int n;
	fread(&n, sizeof(int), 1, fp);
	return n;
}

/*-------------------------------------------------------------------
Write Text File Functions
-------------------------------------------------------------------*/
// �� ���ڸ� ���Ͽ� ����
inline void cfputc(cfileptr fp, int c)
{
	fputc(c, fp);
}

// �� ���ڸ� ���Ͽ� ����; �������� \n�� ��
inline void cfputcln(cfileptr fp, int c)
{
	cfputc(fp, c);
	cfputc(fp, '\n');
}

// �Ǽ��� �ؽ�Ʈ�� ����
inline void cfputdbl(cfileptr fp, double x)
{
	fprintf(fp, "%g", x);
}

// �Ǽ��� �ؽ�Ʈ�� ����; �������� \n�� ��
inline void cfputdblln(cfileptr fp, double x)
{
	cfputdbl(fp, x);
	cfputc(fp, '\n');
}

// ������ �ؽ�Ʈ�� ����
inline void cfputint(cfileptr fp, int n)
{
	fprintf(fp, "%d", n);
}

// ������ �ؽ�Ʈ�� ����; �������� \n�� ��
inline void cfputintln(cfileptr fp, int n)
{
	cfputint(fp, n);
	cfputc(fp, '\n');
}

// ���ڿ��� ���Ͽ� ����; �������� \n�� ���� ����
inline void cfputs(cfileptr fp, const char* str)
{
	fputs(str, fp);
}

// ���ڿ��� ���Ͽ� ����; �������� \n�� ��
inline void cfputsln(cfileptr fp, const char* str)
{
	fputs(str, fp);
	cfputc(fp, '\n');
}

/*-------------------------------------------------------------------
Write Binary File Functions
-------------------------------------------------------------------*/
// ���� ���Ͽ� �Ǽ� ����
inline void cfwritedbl(cfileptr fp, double x)
{
	fwrite(&x, sizeof(double), 1, fp);
}

// ���� ���Ͽ� ���� ����
inline void cfwriteint(cfileptr fp, int n)
{
	fwrite(&n, sizeof(int), 1, fp);
}

/*-------------------------------------------------------------------
Revision Records
---------------------------------------------------------------------
C(2023-03-24): create for simple file operations
-------------------------------------------------------------------*/