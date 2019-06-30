#ifndef __SQUE_H__
#define __SQUE_H__

//Read와 Write때문에 빈사이즈 5 둠
#define EMPTYSIZE 5

class SQue
{
protected://멤버변수
	char *m_Buffer;
	int m_Read;      //읽는 position
	int m_Write;     // 쓰는 position
	int m_UseSize;   // 사용한 size
	int m_Total;    // 큐의 총 size

public://멤버함수
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

