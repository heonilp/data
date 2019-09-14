#ifndef __DOUBLESTEAMQUE_H__
#define __DOUBLESTEAMQUE_H__
#define INPUT 0
#define OUTPUT 1
#define EMPTYSIZE 4

struct SQue
{
	char *m_buffer; //���ۻ�����
	int m_write; //����
	int m_read; //����Ʈ
	int m_Totalsize; //�ѻ�����



	SQue(int size) : m_write(0), m_read(0)
	{
		m_buffer = new char[size];
		m_Totalsize = size;
	}



	~SQue()
	{
		memset(m_buffer, NULL, m_Totalsize);
		//�ı��� : �����Ҵ� ����
		delete[]m_buffer;
	}



	int Put(char* pData, int iSize)
	{
		//������ ���� // ��? : Put,Get, Peek�� ������� ���� ����� ������ 0�̵Ǵ� �� Ȯ���Ϸ���
		int sizen = iSize;

		int iReturntemp = 0; //������ ������ �ϳ� �д�. 

		int putemtpysize = (m_Totalsize + m_read - EMPTYSIZE - m_write) % m_Totalsize;
		//1. ������� ���� ������� ���� ���

		//���� ����� 0�̰ų� ���� ����� 0�϶� 
		if ((sizen <= 0) || (putemtpysize == 0)) return 0;
		//���� ������ ���ؼ� �ֱ�

		int psize = Putsize(sizen);

		int leftsize = m_Totalsize - m_write;

		if (psize  > leftsize)
		{
			memcpy(m_buffer + m_write, pData, leftsize);
			memcpy(m_buffer, pData + leftsize, psize - leftsize);
			m_write = (psize - leftsize) % m_Totalsize;
		}
		//�����͸� ������ ��ŭ m_buffer�� ����
		else
		{
			memcpy(&m_buffer[m_write], pData, psize);
			m_write = (m_write + psize) % m_Totalsize;
		}
		sizen = sizen - psize;


		//Put�� ������� ���� ����� ������ sizen 0
		//�������̸� iSize ����
		iReturntemp = iSize - sizen;

		return iReturntemp;
	}


	int Get(char* pData, int iSize)
	{
		int sizen = iSize;
		int iReturntemp = 0;
		int Getenablesize = (m_Totalsize + m_write - m_read) % m_Totalsize;

		//���� ����� 0�̰ų� ���� ����� 0�϶� 
		if ((sizen <= 0) || (Getenablesize == 0)) return 0;
		//���� ������ ���ؼ� �ֱ�

		int gsize = GetPeeksize(sizen);

		int LSize = m_Totalsize - m_read; //�ѻ��뷮���� ���� ���� ����.
		//�Ѿ����
		if (gsize > LSize)
		{
			memcpy(pData, m_buffer + m_read, LSize);
			memcpy(pData + LSize, m_buffer, gsize - LSize);
			m_read = (gsize - LSize) % m_Totalsize;
		}
		//�����͸� ������ ��ŭ pData�� ����
		else
		{
			memcpy(pData, &m_buffer[m_read], gsize);
			//read�� ����
			m_read = (m_read + gsize) % m_Totalsize;
		}
		//Get�� ������� ���� ����� ������ 0
		sizen = sizen - gsize;

		//Get�� ������� ���� ����� ������ sizen 0
		//�������̸� iSize ����
		iReturntemp = iSize - sizen;

		return iReturntemp;
	}


	//CAysStreamDQ
	//FlipBuffer�ʿ��� ���۰� ������ִ��� Ȯ���Ѵ�.
	int Peek(char* pData, int iSize)
	{
		int iReturntemp = 0;
		int sizen = iSize;

		int peekemsize = (m_Totalsize + m_write - m_read) % m_Totalsize;

		//���� ����� 0�̰ų� ���� ����� 0�϶� 
		if ((sizen == 0) || (peekemsize == 0)) return 0;
		//���� ������ ���ؼ� �ֱ�
		int iPeeksize = GetPeeksize(sizen);
		//�����͸� ������ ��ŭ pData�� ����

		//�Ѿ����
		int LSize = m_Totalsize - m_read; //�ѻ��뷮���� ���� ���� ����.
		//�Ѿ����
		if (iPeeksize > LSize)
		{
			memcpy(pData, m_buffer + m_read, LSize);
			memcpy(pData + LSize, m_buffer, iPeeksize - LSize);
		}

		else
		{
			memcpy(pData, &m_buffer[m_read], iPeeksize);
			//Peek�� ������� ���� ����� ������ 0
		}
		sizen = sizen - iPeeksize;

		//Peek�� ������� ���� ����� ������ sizen 0
		//�������̸� iSize ����
		iReturntemp = iSize - sizen;

		return iReturntemp;
	}




	void Remove(int iSize)
	{
		//���常ŭ �̵�
		int emptySize = min(iSize, (m_Totalsize + m_write - m_read) % m_Totalsize);

		m_read = (m_read + emptySize) % m_Totalsize;

	}



	int Putsize(int iSize)
	{
		int putemtpysize = (m_Totalsize + m_read - EMPTYSIZE - m_write) % m_Totalsize;

		int iPutsize = min(iSize, putemtpysize);

		return iPutsize;
	}



	int GetPeeksize(int iSize)
	{
		int Getpeekemtpysize = (m_Totalsize + m_write - m_read) % m_Totalsize;

		int iGetPeeksize = min(iSize, Getpeekemtpysize);

		return iGetPeeksize;
	}


	void EmptyBuffer()
	{
		m_read = 0;
		m_write = 0;
	}


	int GetEmptySize()
	{
		return (m_Totalsize - m_write - EMPTYSIZE + m_read) % m_Totalsize;

	}


	int GetGetSize()
	{
		int GetGetsize = (m_Totalsize + m_write - m_read) % m_Totalsize;

		return GetGetsize;
	}
};




class DoublestreamQue
{

public:
	SQue *StreamQue[2];
	DoublestreamQue(int iSize);
	virtual~DoublestreamQue();
	void FlipQue();

};

DoublestreamQue::DoublestreamQue(int iSize)
{
	StreamQue[INPUT] = new SQue(iSize);
	StreamQue[OUTPUT] = new SQue(iSize);
}


DoublestreamQue::~DoublestreamQue()
{
	delete StreamQue[INPUT];
	delete StreamQue[OUTPUT];
}

void DoublestreamQue::FlipQue()
{
	//FlipQue : ��á�ų� ��������� �ٲ���
	if (StreamQue[INPUT]->GetEmptySize() == 0 || StreamQue[INPUT]->GetGetSize() == 0)
	{
		SQue * tempQueIN = StreamQue[INPUT];
		StreamQue[INPUT] = StreamQue[OUTPUT];
		StreamQue[OUTPUT] = tempQueIN;
	}

	/*
	else if (StreamQue[OUTPUT]->GetEmptySize() == 0 || StreamQue[OUTPUT]->GetGetSize() == 0)
	{
		SQue * tempQueOUT = StreamQue[OUTPUT];
		StreamQue[OUTPUT] = StreamQue[INPUT];
		StreamQue[INPUT] = tempQueOUT;
	}
	*/

	
}


#endif