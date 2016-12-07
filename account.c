#include <stdio.h>
#include "account.h"

void AccUpdate(){
	int jobnum;

	printf("\n \t Account Update \n");
	printf("\t\t 1. ID Change \n");
	printf("\t\t 2.Passwd Change \n");
	printf("\t 중 수행할 작업의 번호를 입력하세요 \n");

	scanf(" %d ",&jobnum);
}

void Errmsg(void){
	printf("바른값을 입력하세요.");
}