#ifndef __PACKET_SERIALIZATION_H__
#define __PACKET_SERIALIZATION_H__

#define TOTALSIZE 10000
#define EMPTYSIZE 4
//단일 큐로 만들기
class PacketSerialization
{
private:
	char *m_pchBuffer;
	int m_iTotalSize;
	int m_writePos; //리어
	int m_readPos; //프론트
	int m_UseSize;

public:
	PacketSerialization();
	~PacketSerialization();
	
	int PutData(char* pData);
	int GetData(char* pData);
	int PutData(int* pData);
	int GetData(int* pData);
	int PutData(short* pData);
	int GetData(short* pData);
	int PutData(WCHAR* pData, int buffsize);
	int GetData(WCHAR* pData, int buffsize);


	int PutData(char pData);
	int GetData(char pData);
	int PutData(int pData);
	int GetData(int pData);
	int PutData(short pData);
	int GetData(short pData);
	int PutData(WCHAR pData, int buffsize);
	int GetData(WCHAR pData, int buffsize);

	int DeepCpy();
	void EmptyBuffer();
	int GetEmptySize();
	void PacketSerialization::Remove(int iSize);


	//operator
	void operator<<(char pPutData); //(PUT)
	void operator>>(char pGetData); //(GET)
	void operator<<(int pPutData); //(PUT)
	void operator>>(int pGetData); //(GET)
	void operator<<(short pPutData); //(PUT)
	void operator>>(short pGetData); //(GET)
};




PacketSerialization::PacketSerialization()
{
	m_iTotalSize = TOTALSIZE;
	m_pchBuffer = new char[m_iTotalSize];
}

PacketSerialization::~PacketSerialization()
{
	//memset(m_pchBuffer, 0, m_iTotalSize);
	//파괴자 : 동적할당 해제
	delete[]m_pchBuffer;
}


int PacketSerialization::PutData(char* pData)
{
	int iSize = sizeof(pData);

	int putemtpysize = m_iTotalSize - m_writePos + m_readPos;

	if (putemtpysize == 0) return 0;

	if (iSize <= putemtpysize)
	{
		memcpy(&m_pchBuffer[m_writePos], pData, iSize);

		m_writePos = m_writePos + iSize;

		m_UseSize = m_UseSize + iSize;
	}

	return iSize;
}


int PacketSerialization::GetData(char* pData)
{

	int iSize = sizeof(pData);

	int Getenablesize = m_iTotalSize + m_writePos - m_readPos;

	if (Getenablesize == 0) return 0;

	if (iSize <= Getenablesize)
	{
		memcpy(pData, &m_pchBuffer[m_readPos], iSize);

		m_readPos = m_readPos + iSize;

		m_UseSize = m_UseSize - iSize;
	}

	return iSize;

}





int PacketSerialization::PutData(int* pData)
{
	int iSize = sizeof(pData);

	int putemtpysize =m_iTotalSize - m_writePos + m_readPos;

	if (putemtpysize == 0) return 0;

	if (iSize <= putemtpysize)
	{
		memcpy(&m_pchBuffer[m_writePos], pData, iSize);

		m_writePos = m_writePos + iSize;

		m_UseSize = m_UseSize + iSize;
	}

	return iSize;
}


int PacketSerialization::GetData(int* pData)
{

	int iSize = sizeof(pData);

	int Getenablesize = m_iTotalSize + m_writePos - m_readPos;

	if (Getenablesize == 0) return 0;

	if (iSize <= Getenablesize)
	{
		memcpy(pData, &m_pchBuffer[m_readPos], iSize);

		m_readPos = m_readPos + iSize;

		m_UseSize = m_UseSize - iSize;
	}

	return iSize;

}

int PacketSerialization::PutData(char pData)
{
	int iSize = sizeof(pData);

	int putemtpysize = m_iTotalSize - m_writePos + m_readPos;

	if (putemtpysize == 0) return 0;

	if (iSize <= putemtpysize)
	{
		memcpy(&m_pchBuffer[m_writePos], &pData, iSize);

		m_writePos = m_writePos + iSize;

		m_UseSize = m_UseSize + iSize;
	}

	return iSize;


}



int PacketSerialization::GetData(char pData)
{
	int iSize = sizeof(pData);

	int Getenablesize = m_iTotalSize + m_writePos - m_readPos;

	if (Getenablesize == 0) return 0;

	if (iSize <= Getenablesize)
	{
		memcpy(&pData, &m_pchBuffer[m_readPos], iSize);

		m_readPos = m_readPos + iSize;

		m_UseSize = m_UseSize - iSize;
	}

	return iSize;

}


int PacketSerialization::PutData(int pData)
{
	int iSize = sizeof(pData);

	int putemtpysize = m_iTotalSize - m_writePos + m_readPos ;

	if (putemtpysize == 0) return 0;

	if (iSize <= putemtpysize)
	{
		memcpy(&m_pchBuffer[m_writePos], &pData, iSize);

		m_writePos = (m_writePos + iSize) % m_iTotalSize;

		m_UseSize = m_UseSize + iSize;
	}

	return iSize;


}
int PacketSerialization::GetData(int pData)
{
	int iSize = sizeof(pData);

	int Getenablesize = m_iTotalSize + m_writePos - m_readPos;

	if (Getenablesize == 0) return 0;

	if (iSize <= Getenablesize)
	{
		memcpy(&pData, &m_pchBuffer[m_readPos], iSize);

		m_readPos = m_readPos + iSize;

		m_UseSize = m_UseSize - iSize;
	}

	return iSize;

}


int PacketSerialization::PutData(WCHAR* pData, int buffsize)
{

	//int iSize = sizeof(pData);

	int putemtpysize = m_iTotalSize - m_writePos + m_readPos;

	if (putemtpysize == 0) return 0;

	if (buffsize <= putemtpysize)
	{
		memcpy(&m_pchBuffer[m_writePos], &buffsize, sizeof(int));

		memcpy(&m_pchBuffer[m_writePos + sizeof(int)], pData, buffsize);

		m_writePos = m_writePos + sizeof(int) + buffsize;

		m_UseSize = m_UseSize + buffsize + sizeof(int);
	}


	return buffsize + sizeof(int);

}



int PacketSerialization::GetData(WCHAR* pData, int buffsize)
{
	//int iSize = sizeof(pData);

	int Getenablesize = m_iTotalSize + m_writePos - m_readPos;

	if (Getenablesize == 0) return 0;

	if (buffsize <= Getenablesize)
	{
		if (buffsize == m_pchBuffer[m_readPos])
		{
			memcpy(pData, &m_pchBuffer[m_readPos + sizeof(int)], buffsize);

			m_readPos = m_readPos + buffsize + sizeof(int);

			m_UseSize = m_UseSize - buffsize - sizeof(int);
		}
	}

	return buffsize + sizeof(int);
}



void PacketSerialization::Remove(int iSize)
{
	int emptySize = min(iSize, (m_iTotalSize + m_writePos - m_readPos));

	m_readPos = m_readPos + emptySize;
}




void PacketSerialization::EmptyBuffer()
{
	m_writePos = 0;
	m_readPos = 0;
}


int PacketSerialization::GetEmptySize()
{
	int GetEmptySize = (m_iTotalSize - m_writePos + m_readPos - EMPTYSIZE) % m_iTotalSize;

	return GetEmptySize;
}


#endif