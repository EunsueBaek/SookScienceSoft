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
      printf("원하는 작업을 선택하시오: ");

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


   printf("\n날짜를 입력하시오(6자리로입력 ex.161225): ");
   scanf("%s",ptr->date);
   ptr->date[7]='\0';
   getchar();

   while( ptr->date[5]==NULL || ptr->date[4]==NULL || ptr->date[3]==NULL || ptr->date[2]==NULL || ptr->date[1]==NULL) {
      printf("6자리로 입력하시오");
      printf("\n날짜를 입력하시오(6자리로입력 ex.161225): ");
      scanf("%s",ptr->date);
      ptr->date[7]='\0';
      getchar();
   }


   printf("\n내용을 입력하시오(7자 내로 입력): ");
   gets(ptr->description);

   ptr->link = NULL;

   printf("\n");
   printf("\n저장되었습니다!\n\n");
}

void View(node *ptr)  {
   int num;

   printf("%6s", "\n날   짜  ");
   printf("%7s\n", "  내   용   ");

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

   printf("\n삭제할 날짜를 입력하시오: ");
   gets(_date);

   while (ptr->link != NULL)  {
      prev = ptr;
      ptr = ptr->link;

      if (strcmp(_date, ptr->date) == 0) {
         prev->link = ptr->link;
         free(ptr);
         printf("삭제되었습니다!\n");
         break;
      }
   }
   return;
}

void Search (node *ptr)  {
   char _date[14];

   printf("\n검색할 날짜를 적으세요.(6자리) : ");
   gets(_date);
   
   printf("%6s", "\n날   짜  ");
   printf("%15s\n", "    내   용   ");

   while (ptr != NULL) {
      if (strcmp(_date, ptr->date) == 0) {

         printf("%6s", ptr->date);
         printf("%14s", ptr->description);
      }
      ptr = ptr->link;
   }

   printf("\n\n");
}