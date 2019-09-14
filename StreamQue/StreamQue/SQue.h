#ifndef __SQUE_H__
#define __SQUE_H__

//Read�� Write������ ������� 5 ��
#define EMPTYSIZE 5

class SQue
{
protected://�������
	char *m_Buffer;
	int m_Read;      //�д� position
	int m_Write;     // ���� position
	int m_UseSize;   // ����� size
	int m_Total;    // ť�� �� size

public://����Լ�
	bool Peek(char *pData, int Size);
	bool Get(char *pData, int Size);
	bool Put(char *pData, int Size);

	SQue(int Size);
	virtual ~SQue();

	int GetEmptySize();
	int GetTotolSize();
	int GetUseSize();
	void EmptyBuffer();

};



#endif 

