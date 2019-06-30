/*
파일 암호화 코드 입니다.
//*/

#define _CRT_SECURE_NO_WARNINGS
#include "header.h"


int En(void){
	FILE *fp;
	char *file;
	int bufsize;
	char Header[5] = "park";
	int i;
	file = malloc(sizeof(char) * 10);
	printf("파일의 이름을 적어주세요: ");
	scanf("%s", file);
	fflush(stdin);

	fp = fopen(file, "rb");

	//헤더 이름
	//길이 재기 
	fseek(fp, 0, SEEK_END);
	bufsize = ftell(fp);
	rewind(fp);


	//막기

	fread(Data, 4, 1, fp);
	/*
	for (i = 0; i < 4; i++){
		//헤더와 체크 헤더와 같으면 리턴 -1
		if (Data[i] == Header[i]){
			printf("암호화 된것 입니다.\n");
			return -1;

		}
	}

	//*/

	//*/
	if (strstr(Data, Header)){
		printf("암호화된 파일 입니다.\n");
		return -1;
	}

	//*/
	//다시 처음으로 돌아가서 끝까지 읽기
	rewind(fp);
	fread(Data, bufsize, 1, fp);
	
	
	//파일 닫기
	fclose(fp);
	
	for (i = 0; i <bufsize; i++){
		Data[i] = Data[i] ^ KEY;
	}

	//파일 다시 열기
	fp = fopen(file, "wb");

	fwrite(Header, 4, 1, fp);
	fwrite(Data, bufsize, 1, fp);


	fclose(fp);
	free(file);

	return 1;
}