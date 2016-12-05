#include <stdio.h>
#include "Log.h"

void Login(){
	char *ID_user_typed, *pswd_user_typed;
	printf("ID(첫 로그인시 0000, 종료 시 0 입력) :");
	ID_user_typed = InputS();
	/*사용자 앙이디랑 맞는지 체크 by(check(ID_user_typed,원래꺼)*/
	printf("비밀번호(첫 로그인시 0000, 종료 시 0 입력) :");
	pswd_user_typed = InputS();
	scanf("%s",&ID_user_typed);
	/*사용자 비밀번호랑 맞는지 체크 by(check(ID_user_typed,원래꺼)*/
	printf("로그인 성공");
}

char *InputS(){
	char *user_typed;
	scanf("%s",&user_typed);
	return user_typed;
}