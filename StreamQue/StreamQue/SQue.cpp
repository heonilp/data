#include "stdafx.h"
#include "SQue.h"
#include <string.h>

SQue::SQue(int Size) :m_Read(0), m_Write(0), m_UseSize(0)
{
	//Size��ŭ �����Ҵ�
	m_Buffer = new char[Size];
	m_Total = Size;
}

SQue::~SQue()
{
	//�����Ҵ� ����
	delete m_Buffer;
}


bool SQue::Put(char *pData, int Size)
{
	//��������� size�� ũ��
	if (GetEmptySize() < Size)   
	{
		return false;
	}

	//�� ������ ���� write+size�� ũ��(ť�� �Ѿ��)
	if ((m_Write + Size) > m_Total)   
	{
		int iSize = m_Total - m_Write - EMPTYSIZE;
		//memcpy(m_Buffer + m_Write, pData, Size);
		//memcpy(m_Buffer, pData + nSize, Size - nSize);
		m_Write = Size - iSize;
	}
	else
	{
		//����+write ��ŭ pData�� �����ϰ� Write�� size�� ����
		memcpy(m_Buffer + m_Write, pData, Size);
		m_Write += Size;
	}

	//���� ����Ʈ ��ŭ ������� m_UseSize�� ���Ѵ�.
	m_UseSize = m_UseSize + Size;

	return true;
}

bool SQue::Get(char *pData, int Size)
{
	// ���� ����Ÿ�� Ŭ��� ����
	if (Size > m_UseSize)                 
	{
		pData = NULL;
		return false;
	}

	// ť�� �Ѿ ���
	if ((m_Read + Size) > m_Total)
	{
		int iSize = m_Total - m_Read - EMPTYSIZE; //�ѻ��뷮���� ���� ���� ����.
		//	memcpy(pData, m_Buffer + m_Read, iSize);
		//	memcpy(pData + iSize, m_Buffer, Size - iSize);
		m_Read = m_Read+ Size + iSize;
	}

	else
	{
		memcpy(pData, m_Buffer + m_Read, Size);
		m_Read = m_Read+ Size; //������ ��ŭ Read�̵�
	}

	m_UseSize -= Size;                   

	return true;
}

bool SQue::Peek(char *pData, int Size)
{
	// ���� ����Ÿ�� Ŭ��� ����
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


// �� �뷮 ���
int SQue::GetTotolSize()
{
	return m_Total;
}


//��� �뷮
int SQue::GetUseSize()
{
	return m_UseSize;
}

//���۸� ���� �Լ� memset���� �ʱ�ȭ
void SQue::EmptyBuffer()
{
	memset(m_Buffer, 0, m_Total);
	return;
}


//��Ʈ�� ť�� ���� ������ ����
int SQue::GetEmptySize()           
{
	return m_Total - m_Write - EMPTYSIZE + m_Read;
}