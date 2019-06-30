// StreamQue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <assert.h>
#include "SQue.h"



int _tmain(int argc, _TCHAR* argv[])
{

	char *inData = "heonilparkabcdedfgdddddddddxxxxxxxxxxdddddddddeeeeeeeeeeessssssssssdddddddddds";
	const int arrsize = strlen(inData);
	char OutData[128];

	SQue m_StreamQue(256);    

	while (1)
	{
		m_StreamQue.Put(inData, arrsize);
		m_StreamQue.Peek(OutData, arrsize);
		m_StreamQue.Get(OutData, m_StreamQue.GetUseSize());
		OutData[arrsize] = '\0';
		printf("%s \n", OutData);
		m_StreamQue.GetEmptySize();


		//	if (!memcmp(inData, OutData, 20))
		//	{
		//assert(false);
		//	}
	}




	return 0;
}



	/*
	char InData[82];
	char QueData[300];
	char PeekData[300];

	int Indatapos = 0;
	const int arrsize = strlen(InData);
	int iRand;
	srand(time(NULL));

	while (1)
	{
		iRand = rand() % (arrsize - Indatapos) + 1;

		Indatapos = +m_StreamQue.Put(InData + Indatapos, iRand);

		if (Indatapos == arrsize)
		{
			Indatapos = 0;
		}
		else if (Indatapos > arrsize)
		{
			assert(false);
		}


		iRand = rand() % (m_StreamQue.GetEmptySize(), iRand);


		//if (iRetGet>0)
		//{
			printf("%s", QueData);

		//}


	}

	*/





