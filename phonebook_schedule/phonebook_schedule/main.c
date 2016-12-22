#include <stdio.h>
#include "Schedule.h"
#include "Phonebook.h"

int ViewHome(char* id){
	int jobnum;
	
	printf(" %s 's Home View \n",id);
	printf("\n ------------------- \n",id);
	printf("\t 1. Account Update \n");
	printf("\t 2. Phone book \n");
	printf("\t 3. Schedule \n");
	printf("\t 4. Logout \n");
	printf(" Select a Jobnumber! \n");
	scanf("%d",&jobnum);
	JobPerformAtHome(jobnum);
}

void JopPerformAtHome(int jobnum){
	if (jobnum == 1){
		AccUpdate();
	}
	else if (jobnum == 2){
		Phonebook();
	}
	else if ( jobnum == 3){
		Schedule();
	}
	else if (jobnum == 4){
		Logout();
	}
	else
		ErrMsg();
}