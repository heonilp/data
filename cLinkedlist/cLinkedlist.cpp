// cLinkedlist.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CLinkedlist.h"

struct st_DATA
{
	char szName[100];
	int iPosX;
	int iPosY;

};

int _tmain(int argc, _TCHAR* argv[])
{
	CLinkedlist<st_DATA> ListData;
	st_DATA *pData;

	pData = new st_DATA;
	memset(pData, 0, sizeof(st_DATA));
	pData->iPosX = 1;
	pData->iPosY = 1;
	strcpy_s(pData->szName, "일번");
	ListData.InsertHead(pData);

	pData = new st_DATA;
	memset(pData, 0, sizeof(st_DATA));
	pData->iPosX = 2;
	pData->iPosY = 2;
	strcpy_s(pData->szName, "이번");
	ListData.InsertHead(pData);

	pData = new st_DATA;
	memset(pData, 0, sizeof(st_DATA));
	pData->iPosX = 3;
	pData->iPosY = 3;
	strcpy_s(pData->szName, "삼번");
	ListData.InsertHead(pData);

	pData = new st_DATA;
	memset(pData, 0, sizeof(st_DATA));
	pData->iPosX = 4;
	pData->iPosY = 4;
	strcpy_s(pData->szName, "사번");
	ListData.InsertHead(pData);

	pData = new st_DATA;
	memset(pData, 0, sizeof(st_DATA));
	pData->iPosX = 5;
	pData->iPosY = 5;
	strcpy_s(pData->szName, "오번");
	ListData.InsertHead(pData);


//출력
	ListData.MoveHead();

	while (ListData.MoveNext())
	{
		pData = ListData.GetAt();
		printf("Linkedlist : ( X : %d, Y : %d) %s \n", pData->iPosX, pData->iPosY, pData->szName);
	}

//검색

	ListData.MoveHead();

	while (ListData.MoveNext())
	{
		pData = ListData.GetAt();
		if (pData->iPosX == 5 && pData->iPosY == 5)
		{
			printf("\nSerach Linkedlist : ( X : %d, Y : %d) %s \n\n", pData->iPosX, pData->iPosY, pData->szName);
		}
	}
//삭제
	ListData.MoveHead();
	while (ListData.MoveNext())
	{
		pData = ListData.GetAt();
		printf("Delete Linkedlist : ( X : %d, Y : %d) %s \n", pData->iPosX, pData->iPosY, pData->szName);
		delete pData;
	}
	return 0;
}

