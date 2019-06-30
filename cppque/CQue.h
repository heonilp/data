#ifndef __CQue_H__
#define __CQue_H__

#define MAX 10
template <typename DATA>
class CQue
{
private:
	DATA* Que[MAX];
	int write;
	int read;

public:
	CQue()
	{
		read = 0;
		write = 0;
	}
	bool Put(DATA *Data);
	bool Get(void);
	bool Peek(void);
};

template <typename DATA>
bool  CQue<DATA>::Put(DATA *Data){

	if (read == (write + 1) % MAX)
	{
		cout << " 값이 꽉찼습니다" << endl;
		return false;
	}
	Que[write] = Data;
	write = (write + 1) % MAX;
	cout << write << "번째 들어간 값은 : " << *Data << endl;
	return true;
}

template <typename DATA>
bool CQue<DATA>::Get(void){
	if (read == write){
		cout << " 값이 없습니다." << endl;
		return false;
	}
	DATA *a = (DATA *)Que[read];
	read = (read + 1) % MAX;
	cout << read << "번째 들어간 값 나옴 : " << *a << endl;

	return true;
}

template <typename DATA>
bool CQue<DATA>::Peek(void){
	if (read == write){
		cout << " 값이 없습니다." << endl;
		return false;
	}

	int a = 0;
	a = (DATA)Que[read];
	cout << " write : " << write << " read : " << read << endl;
	return true;
}
#endif