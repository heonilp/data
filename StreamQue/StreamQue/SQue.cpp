#include "stdafx.h"
#include "SQue.h"
#include <string.h>

SQue::SQue(int Size) :m_Read(0), m_Write(0), m_UseSize(0)
{
	//Size만큼 동적할당
	m_Buffer = new char[Size];
	m_Total = Size;
}

SQue::~SQue()
{
	//동적할당 해제
	delete m_Buffer;
}


bool SQue::Put(char *pData, int Size)
{
	//빈공간보다 size가 크면
	if (GetEmptySize() < Size)   
	{
		return false;
	}

	//총 사이즈 보다 write+size가 크면(큐가 넘어가면)
	if ((m_Write + Size) > m_Total)   
	{
		int iSize = m_Total - m_Write - EMPTYSIZE;
		//memcpy(m_Buffer + m_Write, pData, Size);
		//memcpy(m_Buffer, pData + nSize, Size - nSize);
		m_Write = Size - iSize;
	}
	else
	{
		//버퍼+write 만큼 pData를 복사하고 Write에 size를 더함
		memcpy(m_Buffer + m_Write, pData, Size);
		m_Write += Size;
	}

	//넣은 바이트 만큼 멤버변수 m_UseSize에 더한다.
	m_UseSize = m_UseSize + Size;

	return true;
}

bool SQue::Get(char *pData, int Size)
{
	// 빼는 데이타가 클경우 리턴
	if (Size > m_UseSize)                 
	{
		pData = NULL;
		return false;
	}

	// 큐가 넘어간 경우
	if ((m_Read + Size) > m_Total)
	{
		int iSize = m_Total - m_Read - EMPTYSIZE; //총사용용량에서 빼는 양을 뺀다.
		//	memcpy(pData, m_Buffer + m_Read, iSize);
		//	memcpy(pData + iSize, m_Buffer, Size - iSize);
		m_Read = m_Read+ Size + iSize;
	}

	else
	{
		memcpy(pData, m_Buffer + m_Read, Size);
		m_Read = m_Read+ Size; //사이즈 만큼 Read이동
	}

	m_UseSize -= Size;                   

	return true;
}

bool SQue::Peek(char *pData, int Size)
{
	// 빼는 데이타가 클경우 리턴
	if (Size > m_UseSize)                
	{
		pData = NULL;
		return false;
	}

	if ((m_Read + Size) > m_Total)
	{
		return false;
	}

	else
	{
		memcpy(pData, m_Buffer + m_Read, Size);
	}

	return true;
}


// 총 용량 얻기
int SQue::GetTotolSize()
{
	return m_Total;
}


//사용 용량
int SQue::GetUseSize()
{
	return m_UseSize;
}

//버퍼를 비우는 함수 memset으로 초기화
void SQue::EmptyBuffer()
{
	memset(m_Buffer, 0, m_Total);
	return;
}


//스트림 큐의 남은 데이터 리턴
int SQue::GetEmptySize()           
{
	return m_Total - m_Write - EMPTYSIZE + m_Read;
}