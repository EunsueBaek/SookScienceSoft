#include <stdio.h>
#include "Schedule.h"
#include "Phonebook.h"
void JopPerformAtHome(int jobnum);

int main (){
	int jobnum;
	
	printf("\t 1. Account Update \n");
	printf("\t 2. Phone book \n");
	printf("\t 3. Schedule \n");
	printf("\t 4. Logout \n");
	printf(" Select a Jobnumber! \n");
	scanf("%d",&jobnum);
	if (jobnum == 2){
		Phonebook();
	}
	else if ( jobnum == 3){
		Schedule();
	}
}