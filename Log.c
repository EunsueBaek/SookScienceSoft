#include <stdio.h>
#include "Log.h"

void Login(){
	char *ID_user_typed, *pswd_user_typed;
	printf("ID(ù �α��ν� 0000, ���� �� 0 �Է�) :");
	ID_user_typed = InputS();
	/*����� ���̵�� �´��� üũ by(check(ID_user_typed,������)*/
	printf("��й�ȣ(ù �α��ν� 0000, ���� �� 0 �Է�) :");
	pswd_user_typed = InputS();
	scanf("%s",&ID_user_typed);
	/*����� ��й�ȣ�� �´��� üũ by(check(ID_user_typed,������)*/
	printf("�α��� ����");
}

char *InputS(){
	char *user_typed;
	scanf("%s",&user_typed);
	return user_typed;
}