#ifndef __CSTACK_H__
#define __CSTACK_H__
#define MAX 10
template <typename DATA>
class CStack
{
private:
	DATA* stack[MAX];
	int Top;
	int temp[MAX];

public:
	CStack(){
		Top = 0;
		for (int icnt = 0; icnt < MAX; icnt++)
		{
			temp[icnt] = 0;
		}
	}
	bool Push(DATA* p);
	bool Pop(DATA *p);
	void Print(void);
};


template <typename DATA>
bool CStack<DATA>::Push(DATA* p)
{
	if (Top >= MAX){
		return false;
	}
		stack[Top] = p;
		
		Top++;
		return true;
	
}


template <typename DATA>
bool CStack<DATA>::Pop(DATA *p){
	if (Top <= 0){
		return false;
	}
	
		p = stack[Top];
		Top--;
		
	return true;
}


template <typename DATA>
void CStack<DATA>::Print(void)
{
	int icnt = 0;
	//포인터의 값
	for (icnt = Top - 1; icnt >= 0; icnt--){
		//printf("[%d] %d \n", icnt,  *(int*)stack[icnt]);
		cout << "[" << icnt + 1 << "]" << *(DATA*)stack[icnt] << endl;
	}
	cout << endl;
}

#endif
