#include <stdio.h>
#include "account.h"

void AccUpdate(){
	int jobnum;

	printf("\n \t Account Update \n");
	printf("\t\t 1. ID Change \n");
	printf("\t\t 2.Passwd Change \n");
	printf("\t Select Jobnumber! \n");

	scanf(" %d ",&jobnum);
}

void Errmsg(void){
	printf("Please insert right number!");
}