#include <stdio.h>
#include "home.h"
#include "Phonebook.h"
#include "Schedule.h"


void ViewHome(char* id){
	int jobnum;

	printf("\n %s 's Home View \n",id);
	printf("\n ------------------- \n",id);
	printf("\t 1. Account Update \n");
	printf("\t 2. Phone book \n");
	printf("\t 3. Schedule \n");
	printf("\t 4. Logout \n");
	printf(" Select a Jobnumber! \n");
	scanf("%d",&jobnum);
	JobPerformAtHome(jobnum);
}

void JobPerformAtHome(int jobnum){
	int a;

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
	else{
		printf("바른값을 입력하세요.");
		printf(" Select a Jobnumber! \n");
		scanf("%d",&a);
		JobPerformAtHome(a);
	}
}
