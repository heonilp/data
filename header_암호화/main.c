
/*
2015-02-25 
헤더 붙어서 암호화
헤더 떼어서 복호화 
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int En(void);
int De(void);

 void main(void){
	int input;

		 while (1){
			 //system("cls");
			 printf(" 1. 암 호 화 \n");
			 printf(" 2. 복 호 화 \n");
			 printf(" 3. 종료 \n");
			 printf(" 메뉴를 고르세요 : ");
			 scanf("%d", &input);
			 fflush(stdin);

		
			 if (input == 1){
			 En();
		 }

			 if (input == 2){
			 De();
		 }

			 if (input == 3){
			 exit(1);
		 }
	 }
}




