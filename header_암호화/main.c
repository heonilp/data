
/*
2015-02-25 
��� �پ ��ȣȭ
��� ��� ��ȣȭ 
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
			 printf(" 1. �� ȣ ȭ \n");
			 printf(" 2. �� ȣ ȭ \n");
			 printf(" 3. ���� \n");
			 printf(" �޴��� ������ : ");
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




