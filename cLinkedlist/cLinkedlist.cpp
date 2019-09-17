
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
	strcpy_s(pData->szName, "�Ϲ�");
	ListData.InsertHead(pData);

	pData = new st_DATA;
	memset(pData, 0, sizeof(st_DATA));
	pData->iPosX = 2;
	pData->iPosY = 2;
	strcpy_s(pData->szName, "�̹�");
	ListData.InsertHead(pData);

	pData = new st_DATA;
	memset(pData, 0, sizeof(st_DATA));
	pData->iPosX = 3;
	pData->iPosY = 3;
	strcpy_s(pData->szName, "���");
	ListData.InsertHead(pData);

	pData = new st_DATA;
	memset(pData, 0, sizeof(st_DATA));
	pData->iPosX = 4;
	pData->iPosY = 4;
	strcpy_s(pData->szName, "���");
	ListData.InsertHead(pData);

	pData = new st_DATA;
	memset(pData, 0, sizeof(st_DATA));
	pData->iPosX = 5;
	pData->iPosY = 5;
	strcpy_s(pData->szName, "����");
	ListData.InsertHead(pData);


//���
	ListData.MoveHead();

	while (ListData.MoveNext())
	{
		pData = ListData.GetAt();
		printf("Linkedlist : ( X : %d, Y : %d) %s \n", pData->iPosX, pData->iPosY, pData->szName);
	}

//�˻�

	ListData.MoveHead();

	while (ListData.MoveNext())
	{
		pData = ListData.GetAt();
		if (pData->iPosX == 5 && pData->iPosY == 5)
		{
			printf("\nSerach Linkedlist : ( X : %d, Y : %d) %s \n\n", pData->iPosX, pData->iPosY, pData->szName);
		}
	}
//����
	ListData.MoveHead();
	while (ListData.MoveNext())
	{
		pData = ListData.GetAt();
		printf("Delete Linkedlist : ( X : %d, Y : %d) %s \n", pData->iPosX, pData->iPosY, pData->szName);
		delete pData;
	}
	return 0;
}

