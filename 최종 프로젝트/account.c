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
		printf("바른값을 입력하세요.");
		AccUpdate();
	}
}

void ChgeID(){

	FILE * fp1, * fp2; 
	
	printf_s("변경할 ID를 입력(0은 ID로 쓸 수 없음):");
	fp1= fopen("id.txt","wt");
	if(fp1 == NULL){
		puts("파일오픈 실패잉");
	}
	fputs(Input(),fp1);
	
	fclose(fp1);
	
	fp2 =fopen("id.txt","rt");
	if(fp2 == NULL){
		puts("파일오픈 실패잉");
	}
	fgets(ID,sizeof(ID),fp2);
	fclose(fp2);
	ViewHome(ID);

}
void ChgePswd(){
FILE * fp1, * fp2; 

	printf("변경할 패스워드를 입력(0은 Password로 쓸 수 없음):");
	fp1= fopen("pswd.txt","wt");
	if(fp1 == NULL){
		puts("파일오픈 실패잉");
	}
	fputs(Input(),fp1);
	
	fclose(fp1);
	
	fp2 =fopen("pswd.txt","rt");
	if(fp2 == NULL){
		puts("파일오픈 실패잉");
	}
	fgets(Pswd,sizeof(Pswd),fp2);
	fclose(fp2);
	ViewHome(ID);
}

char* Input(){
	char *exitmsg2 = "0";
	gets(user_typed2);
	while(!strcmp(user_typed2,exitmsg2)){
		printf("바른값을 입력하세요:");
			gets(user_typed2);
	}
	gets(user_typed2);
	return user_typed2;
}
