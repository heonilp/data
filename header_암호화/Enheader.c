/*
���� ��ȣȭ �ڵ� �Դϴ�.
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
	printf("������ �̸��� �����ּ���: ");
	scanf("%s", file);
	fflush(stdin);

	fp = fopen(file, "rb");

	//��� �̸�
	//���� ��� 
	fseek(fp, 0, SEEK_END);
	bufsize = ftell(fp);
	rewind(fp);


	//����

	fread(Data, 4, 1, fp);
	/*
	for (i = 0; i < 4; i++){
		//����� üũ ����� ������ ���� -1
		if (Data[i] == Header[i]){
			printf("��ȣȭ �Ȱ� �Դϴ�.\n");
			return -1;

		}
	}

	//*/

	//*/
	if (strstr(Data, Header)){
		printf("��ȣȭ�� ���� �Դϴ�.\n");
		return -1;
	}

	//*/
	//�ٽ� ó������ ���ư��� ������ �б�
	rewind(fp);
	fread(Data, bufsize, 1, fp);
	
	
	//���� �ݱ�
	fclose(fp);
	
	for (i = 0; i <bufsize; i++){
		Data[i] = Data[i] ^ KEY;
	}

	//���� �ٽ� ����
	fp = fopen(file, "wb");

	fwrite(Header, 4, 1, fp);
	fwrite(Data, bufsize, 1, fp);


	fclose(fp);
	free(file);

	return 1;
}