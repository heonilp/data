/*
���� ��ȣȭ �ڵ� �Դϴ�.
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
	printf("������ �̸��� �����ּ���: ");
	scanf("%s", file);
	fflush(stdin);
	//���ڵ� �Ȱ� �ٸ������� ������ ���ƾ��Ѵ�.
	fp = fopen(file, "rb");
	

	//����
	
	//��� �̸�
	//���� ��� 
	fseek(fp, 0, SEEK_END);
	bufsize = ftell(fp);
	rewind(fp);
	////////////////////////////////////
	
	// ���ڵ� �Ȱ��� ����
	// ����� ������ ����
	 
	//�о üũ ����(ck Data)�� ����

	fread(Data, 4, 1, fp);

	for (i = 0; i < 4 ; i++){
		//����� üũ ����� ������ ���� -1
	   if(Data[i]!= Header[i]){
			printf("��ȣȭ �Ȱ� �Դϴ�.\n");
			return -1;	
	   
	   }
    }

	
	//�� ��ġ���� 4ĭ�̵� ->����� ����� ����
	rewind(fp);
	fseek(fp, 4, SEEK_CUR);
	//�о ���� ����( Data)�� ����
	fread(Data, bufsize, 1, fp);

	//���� �ݱ�
	fclose(fp);

	for (i = 0; i <bufsize; i++){
		Data[i] = Data[i] ^ KEY;
	}

	//���� �ٽ� ����
	fp = fopen(file, "wb");
	
	fwrite(Data, bufsize-4, 1, fp);

	//bufsize�� (bufsize-4)�� ���� 4���� �����Ⱑ ���ͼ� ����� 4 �ٰ��� 
	//////////////////////////////////////



	fclose(fp);
	free(file);


	return 1;
}


