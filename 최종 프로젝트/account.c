#include <stdio.h>
#include "account.h"
#include "Log.h"
void AccUpdate(){
	int jobnum1;

	printf("\n \t Account Update \n");
	printf("\t\t 1. ID Change \n");
	printf("\t\t 2.Passwd Change \n");
	printf("Select Jobnumber! \n");

	scanf("%d",&jobnum1);
	JobPerformAtAccUpdate(jobnum1);
}


void JobPerformAtAccUpdate(int jobnum){
	if (jobnum == 1){
		ChgeID();
	}
	else if (jobnum == 2){
		ChgePswd();
	}
	
	else{
		printf("�ٸ����� �Է��ϼ���.");
		AccUpdate();
	}
}

void ChgeID(){

	FILE * fp1, * fp2; 
	
	printf_s("������ ID�� �Է�(0�� ID�� �� �� ����):");
	fp1= fopen("id.txt","wt");
	if(fp1 == NULL){
		puts("���Ͽ��� ������");
	}
	fputs(Input(),fp1);
	
	fclose(fp1);
	
	fp2 =fopen("id.txt","rt");
	if(fp2 == NULL){
		puts("���Ͽ��� ������");
	}
	fgets(ID,sizeof(ID),fp2);
	fclose(fp2);
	ViewHome(ID);

}
void ChgePswd(){
FILE * fp1, * fp2; 

	printf("������ �н����带 �Է�(0�� Password�� �� �� ����):");
	fp1= fopen("pswd.txt","wt");
	if(fp1 == NULL){
		puts("���Ͽ��� ������");
	}
	fputs(Input(),fp1);
	
	fclose(fp1);
	
	fp2 =fopen("pswd.txt","rt");
	if(fp2 == NULL){
		puts("���Ͽ��� ������");
	}
	fgets(Pswd,sizeof(Pswd),fp2);
	fclose(fp2);
	ViewHome(ID);
}

char* Input(){
	char *exitmsg2 = "0";
	gets(user_typed2);
	while(!strcmp(user_typed2,exitmsg2)){
		printf("�ٸ����� �Է��ϼ���:");
			gets(user_typed2);
	}
	gets(user_typed2);
	return user_typed2;
}
