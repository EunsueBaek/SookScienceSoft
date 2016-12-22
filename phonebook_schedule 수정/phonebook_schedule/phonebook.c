#include <stdio.h>
#include <malloc.h>
#include <string.h>
//#include "home.h"
#include  "Phonebook.h"

void Phonebook(void) {
   phonebook *current;
   int choice;

   current = (phonebook *)malloc(sizeof(phonebook));
   current->next = NULL;

   do {
      printf("<<PHONEBOOK MENU>>\n1. Add Phone number 2. Total phone book 3. Delete 4. Search (Home : -1)  \n");
      scanf("%d", &choice);

      fflush(stdin);

      switch(choice) {
      case 1 : 
         addPhonebook(current); 
         break;
      case 2 : 
         viewPhonebook(current->next);
         break;
      case 3 : 
         deletePhonebook(current);
         break;
      case 4 : 
         searchPhonebook(current);
         break;
      }
   }while(choice!=-1);
}

void addPhonebook(phonebook *current) {
   char inputName[10], inputPhone[14];

   while (current->next != NULL)
      current = current->next;

   current->next = (phonebook*)malloc(sizeof(phonebook));
   current = current->next;

   printf("Write phone number, name for store. \n phone number : ");
   scanf("%s", current->phone);

   while(current->phone[2]==NULL || current->phone[1]==NULL) {
      printf("\n전화번호를 제대로 입력해주세요.\n");
      printf("Write phone number & name to store. \n phone number : ");
      scanf("%s", current->phone);
   }

   printf(" name : ");
   scanf("%s", current->name);

   current->next = NULL;
   printf("저장되었습니다. \n\n");
}

void viewPhonebook(phonebook *current)  {
   int choice;

   printf("%6s", "NAME ") ;
   printf("%14s", " PHONE NUMBER \n");

   while (current != NULL) {
      printf("%6s", current->name);
      printf("%14s", current->phone);

      current = current->next;
      printf("\n");
   }
   printf("\n\n");
}

void deletePhonebook(phonebook *current)  {
   phonebook *prev;
   char deletePhone[14];

   printf("삭제할 전화번호를 선택하시오: ");
   gets(deletePhone);

   while (current->next != NULL)  {
      prev = current;
      current = current->next;

      if (strcmp(deletePhone, current->phone)==0) {
         prev->next = current->next;
         free(current);
         printf("삭제되었습니다!\n\n");
         break;
      }
   }
   return;
}

void searchPhonebook(phonebook *current)  {
   char inputName[10];

   printf("검색할 이름을 적으세요. : ");
   gets(inputName);

   printf("%6s", "이   름") ;
   printf("%14s", "전 화 번 호");

   while (current != NULL) {
      if (strcmp(inputName, current->name) == 0) {
         printf("%6s", current->name);
         printf("%14s", current->phone);
      }
      current = current->next;
      printf("\n");
   }

   printf("\n");
}