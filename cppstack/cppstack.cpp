// cppstack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CStack.h"

using namespace std;
void Print();

int _tmain(int argc, _TCHAR* argv[])
{

	CStack<int> g_stack;
	int choice;

	while (1){

		cout << "1. Push " << endl;
		cout << "2. Pop " << endl;
		cin >> choice;

		if (choice == 1){
			cout << "[DATA] : " << endl;
			int *p = new int;
			//*p = 10;
			cin >> *p;
			g_stack.Push(p);
		}

		if (choice == 2){
			int *p = new int;
			g_stack.Pop(p);
			if (p != NULL){
				delete p;
			}
		}
		g_stack.Print();
	}
	return 0;
}


