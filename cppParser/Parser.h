#ifndef __PARSER_H__
#define __PARSER_H__

#define df_RARSER_BUFFER_SIZE 512000 
#define MAX 30

class Parser{
private:
	char *buffer;
	char *chpPos;
	FILE *fp;
	char chWord[1024];
	int iLength;
	char areaWord[1024];
	char *chpBuff;

public:
	Parser()
	{
		buffer = (char *)malloc(df_RARSER_BUFFER_SIZE);
	}


	~Parser()
	{
		free(buffer);
		fclose(fp);
	}
	void Parser_LoadFile(char *Filename);
	bool Parser_ProvideArea(char *Area);
	bool skipNoneCommand(void);
	bool GetNextWord(char **chppBuffer, int *ipLength, int temp);
	//�����ε�
	bool Parser_GetValue(char *szName, int *dValue);
	bool Parser_GetValue(char *szName, char *dValue);
	bool Parser_GetValue(char *szName, float *dValue);
};




void Parser::Parser_LoadFile(char *Filename){
	//�ҷ�������
	//���� �̸� 20�� 
	int bufsize;
	fp = fopen(Filename, "r");
	fseek(fp, 0, SEEK_END);
	bufsize = ftell(fp);
	rewind(fp);
	fread(buffer, bufsize, 1, fp);

	if (buffer == NULL)
	{
		exit(1);
	}
	chpPos = buffer;
}


bool Parser::Parser_ProvideArea(char *Area){

	while (GetNextWord(&chpBuff, &iLength, 1)){   //Area
		memset(chWord, 0, 1024);
		memcpy(chWord, chpBuff, iLength);
		if (strcmp(chWord, Area) == 0){
			printf("< %s >\n", chWord);
			if (GetNextWord(&chpBuff, &iLength, 3)){  // ���� ] ���������� ����
				memset(chWord, 0, 1024);
				memcpy(chWord, chpBuff, iLength);
				chpPos = chpBuff; //���� ���� ����Ŵ
				return true;
			}

		}
	}
	return false;
}
// NAME = "dark"




bool Parser::skipNoneCommand(void){
	//          [             ]
	//�ӽ� ���۸� ����

	while (1)
	{
		if (*chpPos == '/' || *chpPos == '*' || *chpPos == '"' || *chpPos == ',' || *chpPos == 0x20 || *chpPos == 0x09 || *chpPos == 0x0A || *chpPos == 0x0D) {
			*chpPos++;
		}

		//�ּ� ����

		else{
			break;
		}
	}
	return true;

}

//temp1�� ���� 2�� GetStringWord

bool Parser::GetNextWord(char **chppBuffer, int *ipLength, int temp)
{
	//�ܾ��� ó�� ��ġ�� ���� char **chppBuffer // �ܾ��� int *ipLength���̸� ����
	//�ܾ �޾ƾ���
	//// GetNextWord(&chpbuff,&Length)�� ����

	//�˻��� chpBuffer

	skipNoneCommand();
	*chppBuffer = chpPos;
	*ipLength = 0;
	// =������ 1.������ ��� / 2. ���� ã�� ��� 
	if (temp == 1)
	{
		while (1){
			if (*chpPos == '"' || *chpPos == ',' || *chpPos == 0x20 || *chpPos == 0x08 || *chpPos == 0x09 || *chpPos == 0x0A || *chpPos == 0x0D){
				break;
			}


			else{
				(*ipLength)++;
				*chpPos++;
			}
		}

	}

	else if (temp == 2) //��Ʈ��
	{

		while (1){
			if (*chpPos == '"'){
				break;
			}
			(*ipLength)++;
			*chpPos++;
		}

	}

	else if(temp == 3) // ����������
	{

		while (1){
			if (*chpPos == '}'){
				break;
			}
			(*ipLength)++;
			*chpPos++;
		}

	}

	else if (temp == 4) //�ּ� ó��
	{
		while (1){
			if ( *chpPos == '/') 
			{
				break;
			}
			(*ipLength)++;
			*chpPos++;
		}

	}

	return true;
}




bool Parser::Parser_GetValue(char *szName, int *dValue){

	while (GetNextWord(&chpBuff, &iLength, 1)){   //����
		memset(chWord, 0, 256);
		memcpy(chWord, chpBuff, iLength);
		if (strcmp(szName, chWord) == 0){
			if (GetNextWord(&chpBuff, &iLength,1)){  //=
				memset(chWord, 0, 256);
				memcpy(chWord, chpBuff, iLength);
				if (strcmp(chWord, "=") == 0){
					
							if (GetNextWord(&chpBuff, &iLength, 1)){  //��
								memset(chWord, 0, 256);
								memcpy(chWord, chpBuff, iLength);
								*dValue = atoi(chWord);
								return true;
							}
				
					return false;
				}

			}
			return false;
		}

	}
	return false;
}



bool Parser::Parser_GetValue(char *szName, float *dValue){

	while (GetNextWord(&chpBuff, &iLength, 1)){   //����
		memset(chWord, 0, 256);
		memcpy(chWord, chpBuff, iLength);
		if (strcmp(szName, chWord) == 0){
			if (GetNextWord(&chpBuff, &iLength,1)){
				memset(chWord, 0, 256);
				memcpy(chWord, chpBuff, iLength);
				if (strcmp(chWord, "=") == 0){
					if (GetNextWord(&chpBuff, &iLength,1)){
						memset(chWord, 0, 256);
						memcpy(chWord, chpBuff, iLength);
						*dValue = (float)atof(chWord);
						return true;

					}
					return false;
				}

			}
			return false;
		}

	}
	return false;
}


bool  Parser::Parser_GetValue(char *szName, char *dValue){


	while (GetNextWord(&chpBuff, &iLength, 1)){   //����
		memset(chWord, 0, 256);
		memcpy(chWord, chpBuff, iLength);
		if (strcmp(szName, chWord) == 0){
			if (GetNextWord(&chpBuff, &iLength,1)){  //=
				memset(chWord, 0, 256);
				memcpy(chWord, chpBuff, iLength);
				if (strcmp(chWord, "=") == 0){
					if (GetNextWord(&chpBuff, &iLength,2)){  // ����
						memset(chWord, 0, 256);
						memcpy(chWord, chpBuff, iLength);
						strcpy(dValue, chWord);
						return true;

					}
					return false;
				}

			}
			return false;
		}

	}
	return false;
}



#endif
