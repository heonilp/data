// DoublestreamQue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "DoublestreamQue.h"


char buf[81] = { "1234567890 eowp32 wpeowe asdfg eiwodw 2038102 219fmeiw 392039qpq 320293019 eifjw" };
int iTotalLen = 0;
DoublestreamQue douque(20);
int i;
void push(int a_iLen);
void pop(int a_iLen);
void peek(int a_iLen);
int irandPush, irandPop;

int _tmain(int argc, _TCHAR* argv[])
{

	srand(time(0));

	while (1)
	{

		irandPush = 200;
		irandPop = rand() % 4+1;
		
		push(irandPush);
		
		pop(irandPop);



		douque.FlipQue();
		//Sleep(10);
	}
	return 0;
}
void push(int a_iLen)
{
	if (iTotalLen + irandPush >= sizeof(buf) - 1)
	{
		a_iLen = sizeof(buf) - 1 - iTotalLen;
	}

	iTotalLen += douque.StreamQue[INPUT]->Put(&buf[iTotalLen], a_iLen);

	if (iTotalLen == sizeof(buf) - 1)
		iTotalLen = 0;
}

void pop(int a_iLen)
{
	int iLen = 0;
	char szBuf[900];
	memset(szBuf, 0, sizeof(szBuf));
	iLen = douque.StreamQue[INPUT]->Get(szBuf, a_iLen);
	
	printf("%s", szBuf);
}

void peek(int a_iLen)
{
	char szBuf[900];
	memset(szBuf, 0, sizeof(szBuf));
	int iLen = douque.StreamQue[INPUT]->Peek(szBuf, a_iLen);
	//streamQue.Remove(iLen);
	printf("%s", szBuf);
}
