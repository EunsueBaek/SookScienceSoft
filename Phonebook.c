#include <stdio.h>
#include "home.h"
#include  "Phonebook.h"
char names[100][20];
int phones[100][25];
char inputName[25];
int inputPhone[25];
int idx;

void Phonebook() {
	int menu;
	printf("1. Add Phone number 2. Total phone book (Home : –1)");
	scanf("%d", &menu);
	if(menu==1)
		addPhonenum();
	else if (menu==2)
		viewPhonebook();
	else if (menu==-1)
		ViewHome(id);
}//viewMenu

void addPhoneum(void) {
	printf("Write name & phone number to store. (ex) hello 01099998888) : ");
	scanf("%s %s", inputName, inputPhone);
	checkPhonenum(inputName, inputPhone);
}

void checkPhonenum(char name[], int phone[]) {
	if(!name || !phone) {
		printf("Try again.\n");
		addPhonenum();
	}
	else 
		storePhonenum(name, phone);
}

void generatePhonenum(char name[], int phone[]) {
}

void viewPhonebook() {
	printf("index  |   name   |   PhoneNumber \n");
	for(int i=0;;) {
	//printf all table records
	}
}

void checkDelPhonenum() {
	deletePhonenum();
}

void deletePhonenum() {
	//delete record
	viewPhonebook();
}
