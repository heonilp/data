// cppParser.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.

#include "stdafx.h"
#include "Parser.h"
#define _CRT_SECURE_NO_WARNINGS

int _tmain(int argc, _TCHAR* argv[])
{
	Parser parser;
	parser.Parser_LoadFile("Test.txt");

	int iValue1;
	int iValue2;
	int iValue3;
	int iValue4;
	float fValue;
	char chValue1[MAX];
	char chValue2[MAX];
	char chValue3[MAX];
	

	parser.Parser_ProvideArea("MAIN");

	parser.Parser_GetValue("NAME", chValue1);
	parser.Parser_GetValue("HP", &iValue1);
	parser.Parser_GetValue("MP", &iValue2);
	parser.Parser_GetValue("N", chValue2);

	printf("NAME=%s\n", chValue1);
	printf("HP=%d\n", iValue1);
	printf("MP=%d\n", iValue2);
	printf("N=%s\n", chValue2);


	parser.Parser_ProvideArea("END");
	parser.Parser_GetValue("FIRST", chValue3);
	parser.Parser_GetValue("LUCK", &iValue3);
	parser.Parser_GetValue("INT", &iValue4);
	parser.Parser_GetValue("CA", &fValue);
	printf("FIRST=%s\n", chValue3);
	printf("LUCK=%d\n", iValue3);
	printf("INT=%d\n", iValue4);
	printf("CA=%lf\n", fValue);



	return 0;
}

