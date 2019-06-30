// Packetserialization.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "PacketSerialization.h"
PacketSerialization pack;


WCHAR a[10] = L"dddd";
WCHAR b[10];

int _tmain(int argc, _TCHAR* argv[])
{
	//char a = 'a';

 	pack.PutData(a,10);
	pack.GetData(b,10);
	wprintf(L"%c",b);
	return 0;
}

