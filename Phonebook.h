void addPhonenum();
void checkPhonenum();
void generatePhonenum();
void viewPhonebook();
void checkDelPhonenum();
void deletePhonenum(); 

void Phonebook() {
	int menu;
	printf("1. Add Phone number 2. Total phone book (Home : -1)");
	scanf("%d", &menu);
	if(menu==1)
		addPhonenum();
	else if (menu==2)
		viewPhonebook();
	else
		Home();
}
