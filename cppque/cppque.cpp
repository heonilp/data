// cppque.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "CQue.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CQue<int> g_Que;
	int i;

	while (1)
	{
		cout << "1.Put ";
		cout << "2.Get ";
		cout << "3.Peek ";
		cin >> i;

		if (i == 1){
			int *Data = new int;
			cin >> *Data;
			g_Que.Put(Data);

		}

		if (i == 2){
			g_Que.Get();

		}

		if (i == 3){

			g_Que.Peek();
		}
	}
	return 0;
}




