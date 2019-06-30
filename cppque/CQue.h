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
		cout << " ���� ��á���ϴ�" << endl;
		return false;
	}
	Que[write] = Data;
	write = (write + 1) % MAX;
	cout << write << "��° �� ���� : " << *Data << endl;
	return true;
}

template <typename DATA>
bool CQue<DATA>::Get(void){
	if (read == write){
		cout << " ���� �����ϴ�." << endl;
		return false;
	}
	DATA *a = (DATA *)Que[read];
	read = (read + 1) % MAX;
	cout << read << "��° �� �� ���� : " << *a << endl;

	return true;
}

template <typename DATA>
bool CQue<DATA>::Peek(void){
	if (read == write){
		cout << " ���� �����ϴ�." << endl;
		return false;
	}

	int a = 0;
	a = (DATA)Que[read];
	cout << " write : " << write << " read : " << read << endl;
	return true;
}
#endif