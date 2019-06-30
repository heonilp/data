/*
파일 복호화 코드 입니다.
//*/

#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

int De(void){
	int i;
	FILE *fp;
	char *file;
	int bufsize;
	char Header[4] ="park";
	file = malloc(sizeof(char) * 10);
	printf("파일의 이름을 적어주세요: ");
	scanf("%s", file);
	fflush(stdin);
	//디코딩 된것 다른파일이 받으면 막아야한다.
	fp = fopen(file, "rb");
	

	//막기
	
	//헤더 이름
	//길이 재기 
	fseek(fp, 0, SEEK_END);
	bufsize = ftell(fp);
	rewind(fp);
	////////////////////////////////////
	
	// 디코딩 된것을 막기
	// 헤더가 없으면 막기
	 
	//읽어서 체크 버퍼(ck Data)에 저장

	fread(Data, 4, 1, fp);

	for (i = 0; i < 4 ; i++){
		//헤더와 체크 헤더와 같으면 리턴 -1
	   if(Data[i]!= Header[i]){
			printf("복호화 된것 입니다.\n");
			return -1;	
	   
	   }
    }

	
	//앞 위치에서 4칸이동 ->헤더를 지우기 위함
	rewind(fp);
	fseek(fp, 4, SEEK_CUR);
	//읽어서 적을 버퍼( Data)에 저장
	fread(Data, bufsize, 1, fp);

	//파일 닫기
	fclose(fp);

	for (i = 0; i <bufsize; i++){
		Data[i] = Data[i] ^ KEY;
	}

	//파일 다시 열기
	fp = fopen(file, "wb");
	
	fwrite(Data, bufsize-4, 1, fp);

	//bufsize에 (bufsize-4)뒷 값에 4개가 쓰레기가 나와서 사이즈를 4 줄게함 
	//////////////////////////////////////



	fclose(fp);
	free(file);


	return 1;
}


