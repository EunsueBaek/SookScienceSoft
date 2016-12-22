#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct _node {
   char date[7];      
   char description[15];   
   struct _node *link;
};

typedef struct _node node;

void Add(node*);      
void Delete(node*);      
void View(node*);  
void Search(node*);

int Schedule(void) {
   node *ptr;
   int choice;

   ptr = (node *)malloc(sizeof(node));
   ptr->link = NULL;

   do {

      printf("Schedule\n");
      printf("1. Add\n");
      printf("2. View\n");
      printf("3. Delete\n");
      printf("4. Search\n");
      printf("5. Home\n");
      printf("���ϴ� �۾��� �����Ͻÿ�: ");

      choice = getchar() - '0';

      fflush(stdin);

      switch(choice) {
      case 1 : 
         Add(ptr); 
         break;
      case 2 : 
         View(ptr->link);
         break;
      case 3 : 
         Delete(ptr); 
         break;
      case 4 : 
         Search(ptr); 
         break;
      }
   }while(choice!=5);
}


void Add(node *ptr) {
   int i;

   while (ptr->link != NULL)
      ptr = ptr->link;

   ptr->link = (node*)malloc(sizeof(node));
   ptr = ptr->link;


   printf("\n��¥�� �Է��Ͻÿ�(6�ڸ����Է� ex.161225): ");
   scanf("%s",ptr->date);
   ptr->date[7]='\0';
   getchar();

   while( ptr->date[5]==NULL || ptr->date[4]==NULL || ptr->date[3]==NULL || ptr->date[2]==NULL || ptr->date[1]==NULL) {
      printf("6�ڸ��� �Է��Ͻÿ�");
      printf("\n��¥�� �Է��Ͻÿ�(6�ڸ����Է� ex.161225): ");
      scanf("%s",ptr->date);
      ptr->date[7]='\0';
      getchar();
   }


   printf("\n������ �Է��Ͻÿ�(7�� ���� �Է�): ");
   gets(ptr->description);

   ptr->link = NULL;

   printf("\n");
   printf("\n����Ǿ����ϴ�!\n\n");
}

void View(node *ptr)  {
   int num;

   printf("%6s", "\n��   ¥  ");
   printf("%7s\n", "  ��   ��   ");

   while (ptr != NULL) {
      printf("%6s ", ptr->date);
      printf("%15s", ptr->description);

      ptr = ptr->link;
      printf("\n");
   }

   printf("\n");

}

void Delete(node *ptr)  {
   node *prev;
   char _date[14];

   printf("\n������ ��¥�� �Է��Ͻÿ�: ");
   gets(_date);

   while (ptr->link != NULL)  {
      prev = ptr;
      ptr = ptr->link;

      if (strcmp(_date, ptr->date) == 0) {
         prev->link = ptr->link;
         free(ptr);
         printf("�����Ǿ����ϴ�!\n");
         break;
      }
   }
   return;
}

void Search (node *ptr)  {
   char _date[14];

   printf("\n�˻��� ��¥�� ��������.(6�ڸ�) : ");
   gets(_date);
   
   printf("%6s", "\n��   ¥  ");
   printf("%15s\n", "    ��   ��   ");

   while (ptr != NULL) {
      if (strcmp(_date, ptr->date) == 0) {

         printf("%6s", ptr->date);
         printf("%14s", ptr->description);
      }
      ptr = ptr->link;
   }

   printf("\n\n");
}