#include <stdio.h>
#include "Log.h"

void Login(){
	char *ID_user_typed, *pswd_user_typed;
	printf("ID(first login ID :0000, exit : 0 ) :");
	ID_user_typed = InputS();
	/*����� ���̵�� �´��� üũ by(check(ID_user_typed,������)*/
	printf("Password((first login ID :0000, exit : 0) :");
	pswd_user_typed = InputS();
	scanf("%s",&ID_user_typed);
	/*����� ��й�ȣ�� �´��� üũ by(check(ID_user_typed,������)*/
	printf("Login Sucssess");
}

char *InputS(){
	char *user_typed;
	scanf("%s",&user_typed);
	return user_typed;
}