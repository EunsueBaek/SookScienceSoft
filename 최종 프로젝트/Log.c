#include <stdio.h>
#include "Log.h"

void Login(){
	int a;
	char *ID_user_typed, *pswd_user_typed;
	int i,ch;
	FILE * fp1, * fp2; 
	fp1= fopen("id.txt","rt");
	fp2 = fopen("pswd.txt","rt");

	if(fp1 == NULL){
		puts("파일오픈 실패잉");
	}

	if(fp2 == NULL){
		puts("파일오픈 실패잉");
	}
	fgets(ID,sizeof(ID),fp1);
	fgets(Pswd,sizeof(Pswd),fp2);
	
	fclose(fp1);

	fclose(fp2);

	do{
		printf("ID(first login ID :0000, exit : 0 ) :");
		a=0;
		ID_user_typed = InputS();
		if(strcmp(ID_user_typed, ID)){
			printf("계정정보가 잘못되었습니다.");
			a=1;
		} 
	}while(a);

	
	do{
		printf("Password(first login Password :0000, exit : 0 ) :");
		a=0;
		pswd_user_typed = InputS();
		if(strcmp(pswd_user_typed, Pswd)){
			printf("계정정보가 잘못되었습니다.");
			a=1;
		} 
	}while(a);
	

	printf("Login Sucssess>_<!\n");
	ViewHome(ID);
}

char *InputS(){
	char *exitmsg = "0";
	gets(user_typed);
		if(!strcmp(user_typed,exitmsg))
			exits();
	return user_typed;
}

void Logout(){
	start();
}