#include <stdio.h>
#include <string.h>
#include "home.h"

#define MAX_NUM 100

typedef struct{
   char date[30];
   char description[30];
}User;

int saveFile2(User* ptr, int* num);
int openFile2(User* ptr, int* num);
void Add2(User* ptr, int* num);
int deleted2(User* ptr, int* num);
int search2(User* ptr, int* num);
void View2(User* ptr, int* num);

void Schedule(void) {
   int input;
   User user[MAX_NUM]; //사용자 정보를 저장할 구조체 배열
   int person = 0; //저장된 user수

   openFile2(user, &person);//저장된 데이터를 불러오는 함수

   //메뉴 선택
   while (1){
      printf("\n1. Add \n");
      printf("2. View \n");
      printf("3. Delete \n");
      printf("4. Search \n");
      printf("5. Home \n");
      printf("Choose the item: ");
      scanf("%d", &input);

      if (input == 1){
         printf("\n[Add] \n");
         Add2(user, &person);
      }
      else if (input == 2){
         printf("\n[View] \n");
         View2(user, &person);
      }
      else if (input == 3){
         printf("\n[Delete] \n");
         deleted2(user, &person);
      }
      else if (input == 4){
         printf("\n[Search] \n");
         search2(user, &person);
      }

      else if (input == 5){
         saveFile2(user, &person);
         return;
      }
      else
         printf("\nError! ReTry! \n\n");
   }
   return;
}

//데이터를 파일에 저장하는 함수
int saveFile2(User* ptr, int* num){
   if (*num > 0){
      int i, state;
      FILE* fp = fopen("scheduleInfo.txt", "wt");

      /* fopen함수는 오류발생시 NULL을 리턴하므로
      파일 개방 중 오류발생시 프로그램을 종료 */
      if (fp == NULL){
         printf("File Open Error!\n");
         return 1;
      }

      //구조체 배열에 저장된 데이터를 파일에 저장
      //줄바꿈으로 구분하여 저장
      for (i = 0; i < *num; i++){
         fprintf(fp, "%s %s", ptr[i].date, ptr[i].description);
         fputc('\n', fp);
      }

      /* fclose함수는 종료시 오류가 발생하면
      0이 아닌 다른값을 리턴하므로 비정상 종료로 판단되면
      안내후 프로그램을 종료 */
      state = fclose(fp);
      if (state != 0){
         printf("File Close Error!\n");
         return 1;
      }
      printf("\n  Data Save \n");
      return 0;
   }
   else{
      printf("\n  Exit \n");
      return 0;
   }
}

//파일로부터 데이터를 불러오는 함수
int openFile2(User* ptr, int* num){
   int state;
   char temp;
   FILE* fp = fopen("scheduleInfo.txt", "rt");

   if (fp == NULL){
      printf("File Open Error!\n");
      return 1;
   }

   //파일에 저장된 데이터를 구조체 배열에 저장
   while (1){
      fscanf(fp, "%s %s", ptr[*num].date, ptr[*num].description);
      if (feof(fp) != 0)
         break;
      (*num)++;
   }

   /* fclose함수는 종료시 오류가 발생하면
   0이 아닌 다른값을 리턴하므로 비정상 종료로 판단되면
   안내후 프로그램을 종료 */
   state = fclose(fp);
   if (state != 0){
   printf("File Close Error!\n");
   return 1;
   }
   return 0;
}

//사용자의 정보를 삽입하는 함수
void Add2(User* ptr, int* num){
   //유저정보가 꽉 차지 않으면
   if (*num < MAX_NUM){
      printf("날짜를 입력하시오(6자리로입력 ex.161225): ");
      scanf("%s", ptr[*num].date);

      while( ptr[5].date==NULL || ptr[4].date==NULL || ptr[3].date==NULL || ptr[2].date==NULL || ptr[1].date==NULL) {
         printf("6자리로 입력하시오");
         printf("날짜를 입력하시오(6자리로입력 ex.161225): ");
         scanf("%s", ptr[*num].date);
      }

      printf("내용을 입력하세요: ");
      scanf("%s", ptr[*num].description);
      (*num)++;
      printf(" 저장되었습니다. \n\n");
   }
   //유저 정보가 꽉 차면
   else
      printf("  더이상 저장할 수 없습니다. \n\n");
}

//사용자의 정보를 삭제하는 함수
int deleted2(User* ptr, int* num){
   char date[30];
   int i, j;

   //유저 정보가 한개라도 남아있으면
   if (*num > 0){
      printf("날짜를 입력하세요: ");
      scanf("%s", date);

      for (i = 0; i < MAX_NUM; i++){
         //문자열이므로 비교하기위해 strcmp사용
         if (strcmp(date, ptr[i].date) == 0){
            (*num)--;
            printf("  삭제되었습니다. \n\n");
            //데이터가 가득 차지 않았다면
            if (i != MAX_NUM - 1){
               for (j = i; j < MAX_NUM; j++){
                  //문자열이므로 strcpy를 사용하여 데이터 복사
                  strcpy(ptr[j].date, ptr[j + 1].date);
                  strcpy(ptr[j].description, ptr[j + 1].description);
               }
               //구조체 배열의 마지막을 NULL로 바꿈
               *ptr[MAX_NUM - 1].date = NULL;
               *ptr[MAX_NUM - 1].description = NULL;
            }

            //데이터가 가득 찼다면
            else{
               //구조체 배열의 마지막을 NULL로 바꿈
               *ptr[MAX_NUM - 1].date = NULL;
               *ptr[MAX_NUM - 1].description = NULL;
            }
            return 0;
         }
      }
      printf("찾지못했습니다. \n\n");
      return 0;
   }

   //저장된 유저 정보가 없다면
   else{
      printf(" 저장된 정보가 없습니다. \n\n");
      return 0;
   }
}

//사용자의 정보를 검색하는 함수
int search2(User* ptr, int* num){
   char date[30];
   int i;

   //저장된 데이터가 있다면
   if (*num > 0){
      printf("날짜를 입력하세요: ");
      scanf("%s", date);

      for (i = 0; i < MAX_NUM; i++){
         //strcmp는 문자열이 일치할때 0을 반환
         //0은 C언어에서 거짓을 의미
         //그러므로 ! 을 붙여 참으로 변경하여 실행
         if (!strcmp(date, ptr[i].date)){
            printf("%6s", "\n날   짜  ");
            printf("%7s\n", "  내   용   \n");
            printf("%s ", ptr[i].date);
            printf("%s \n", ptr[i].description);
            printf(" 검색을 완료했습니다. \n\n");
            return 0;
         }
      }
      printf("찾지못하였습니다. \n\n");
      return 0;
   }
   else{
      printf(" 저장된 정보가 없습니다. \n\n");
      return 0;
   }
}

//저장된 모든 이름과 전화번호 정보를 출력하는 함수
void View2(User* ptr, int* num){
   int i = 0;
   if (*num > 0){
      for (i = 0; i < *num; i++){
         printf("%6s", "\n날   짜  ");
         printf("%7s\n", "  내   용   \n");
         printf("%s ", ptr[i].date);
         printf("%s \n", ptr[i].description);
      }
   }
   else
      printf("  저장된 정보가 없습니다. \n\n");
}