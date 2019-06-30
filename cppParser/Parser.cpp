

#include "stdafx.h"
#include "Parser.h"


template <typename DATA>
class Parser{
private:
	char *buffer;
	char *chpPos;
	FILE *fp;
	Parser()
	{
		buffer = (char *)malloc(df_RARSER_BUFFER_SIZE);
	}


	~Parser()
	{
		free(buffer);
		fclose(fp);
	}
public:
	void Parser_LoadFile(char *Filename);
	bool Parser_ProvideArea(char *Area);
	bool skipNoneCommand(void);
	bool GetNextWord(char **chppBuffer, int *ipLength, int temp);
	bool Parser_GetValue(char *szName, DATA *dValue, int temp);
};




template <typename DATA>
void Parser<DATA>::Parser_LoadFile(char *Filename){
	//불러올파일
	//파일 이름 20자 
	int bufsize;
	fp = fopen(Filename, "rb");
	fseek(fp, 0, SEEK_END);
	bufsize = ftell(fp);
	rewind(fp);
	fread(buffer, bufsize, 1, fp);

	if (buffer == NULL){
		exit(1);
	}
	chpPos = buffer;


}

template <typename DATA>
bool Parser<DATA>::Parser_ProvideArea(char *Area){

	char chWord[1024];
	int iLength;
	char *chpBuff;

	while (1){

		if (GetNextWord(&chpBuff, &iLength,1)){   //변수
			memset(chWord, 0, 1024);
			memcpy(chWord, chpBuff, iLength);
			//printf("<%s 지역> \n", chWord);
			if (strcmp(chWord, Area) == 0){
					if (GetNextWord(&chpBuff, &iLength, 1)){  //{
						memset(chWord, 0, 1024);
						memcpy(chWord, chpBuff, iLength);
						if (strcmp(chWord, "{") == 0){
							if (GetNextWord(&chpBuff, &iLength, 3)){  // 글자
								memset(chWord, 0, 1024);
								memcpy(chWord, chpBuff, 1024);
								if (GetNextWord(&chpBuff, &iLength, 1)){  //{
									memset(chWord, 0, 1024);
									memcpy(chWord, chpBuff, iLength);
									if (strcmp(chWord, "}") == 0){
										memset(chWord, 0, 1024);
										memcpy(chWord, chpBuff, iLength);
										return true;
									}
								}
							}
						}
					}
			}
		}
	}
	return false;
}
// NAME = "dark"




template <typename DATA>
bool Parser<DATA>::skipNoneCommand(void){
	//          [             ]
	//임시 버퍼를 받음

	while (1)
	{
		if (*chpPos == '"' || *chpPos == ',' || *chpPos == 0x20 || *chpPos == 0x09 || *chpPos == 0x0A || *chpPos == 0x0D) {
			*chpPos++;
		}

		//주석 제외

		else{
			break;
		}
	}
	return true;

}

//temp1이 원래 2가 GetStringWord
template <typename DATA>
bool Parser<DATA>::GetNextWord(char **chppBuffer, int *ipLength, int temp)
{
	//단어의 처음 위치를 받음 char **chppBuffer // 단어의 int *ipLength길이를 받음
	//단어를 받아야함
	//// GetNextWord(&chpbuff,&Length)로 받음

	//검사할 chpBuffer
	skipNoneCommand();
	*chppBuffer = chpPos;
	*ipLength = 0;
	// =다음에 1.공백일 경우 / 2. 값을 찾을 경우 
	if (temp == 1)
	{
		while (1){
			if (*chpPos == '"' || *chpPos == ','||*chpPos == 0x20 || *chpPos == 0x08 || *chpPos == 0x09 || *chpPos == 0x0A || *chpPos == 0x0D){
				break;
			}


			else{
				(*ipLength)++;
				*chpPos++;
			}
		}

	}

	if (temp == 2)
	{
	
		while (1){
			if (*chpPos == '"'){
				break;
			}
			(*ipLength)++;
			*chpPos++;
		}
	
	}

	if (temp == 3)
	{

		while (1){
			if (*chpPos == '}'){
				break;
			}
			(*ipLength)++;
			*chpPos++;
		}

	}
	return true;
}




template <typename DATA>
bool Parser<DATA>::Parser_GetValue(char *szName, DATA *dValue, int temp){
	char chWord[256];
	int iLength;
	char *chpBuff;
	while (GetNextWord(&chpBuff, &iLength, 1)){   //변수
		memset(chWord, 0, 256);
		memcpy(chWord, chpBuff, iLength);
		if (strcmp(szName, chWord) == 0){
			if (GetNextWord(&chpBuff, &iLength, 1)){  //=
				memset(chWord, 0, 256);
				memcpy(chWord, chpBuff, iLength);
				if (strcmp(chWord, "=") == 0){
					if (temp == 1){
						if (GetNextWord(&chpBuff, &iLength, 2)){  // 글자
							memset(chWord, 0, 256);
							memcpy(chWord, chpBuff, iLength);
							memcpy(dValue, chWord, MAX);
							return true;
						}
					}
					else if (temp == 2){
						if (GetNextWord(&chpBuff, &iLength, 1)){  //값
							memset(chWord, 0, 256);
							memcpy(chWord, chpBuff, iLength);
							*dValue = atoi(chWord);
							return true;
						}
					}
					else if (temp == 3){
						if (GetNextWord(&chpBuff, &iLength, 1)){
							memset(chWord, 0, 256);
							memcpy(chWord, chpBuff, iLength);
							*dValue = (float)atof(chWord);
							return true;
						}
					}

					return false;
				}

			}
			return false;
		}

	}
	return false;
}