#include <stdio.h>
#include <string.h>

#define MAX_NUM 100

typedef struct{
   char date[30];
   char description[30];
}User;

int saveFile(User* ptr, int* num);
int openFile(User* ptr, int* num);
void Add(User* ptr, int* num);
int deleted(User* ptr, int* num);
int search(User* ptr, int* num);
void View(User* ptr, int* num);

int main(void){
   int input;
   User user[MAX_NUM]; //����� ������ ������ ����ü �迭
   int person = 0; //����� user��

   openFile(user, &person);//����� �����͸� �ҷ����� �Լ�

   //�޴� ����
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
         Add(user, &person);
      }
      else if (input == 2){
         printf("\n[View] \n");
         View(user, &person);
      }
      else if (input == 3){
         printf("\n[Delete] \n");
         deleted(user, &person);
      }
      else if (input == 4){
         printf("\n[Search] \n");
         search(user, &person);
      }

      else if (input == 5){
         saveFile(user, &person);
         return 0;
      }
      else
         printf("\nError! ReTry! \n\n");
   }
   return 0;
}

//�����͸� ���Ͽ� �����ϴ� �Լ�
int saveFile(User* ptr, int* num){
   if (*num > 0){
      int i, state;
      FILE* fp = fopen("scheduleInfo.txt", "wt");

      /* fopen�Լ��� �����߻��� NULL�� �����ϹǷ�
      ���� ���� �� �����߻��� ���α׷��� ���� */
      if (fp == NULL){
         printf("File Open Error!\n");
         return 1;
      }

      //����ü �迭�� ����� �����͸� ���Ͽ� ����
      //�ٹٲ����� �����Ͽ� ����
      for (i = 0; i < *num; i++){
         fprintf(fp, "%s %s", ptr[i].date, ptr[i].description);
         fputc('\n', fp);
      }

      /* fclose�Լ��� ����� ������ �߻��ϸ�
      0�� �ƴ� �ٸ����� �����ϹǷ� ������ ����� �ǴܵǸ�
      �ȳ��� ���α׷��� ���� */
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

//���Ϸκ��� �����͸� �ҷ����� �Լ�
int openFile(User* ptr, int* num){
   int state;
   char temp;
   FILE* fp = fopen("scheduleInfo.txt", "rt");

   if (fp == NULL){
      printf("File Open Error!\n");
      return 1;
   }

   //���Ͽ� ����� �����͸� ����ü �迭�� ����
   while (1){
      fscanf(fp, "%s %s", ptr[*num].date, ptr[*num].description);
      if (feof(fp) != 0)
         break;
      (*num)++;
   }

   /* fclose�Լ��� ����� ������ �߻��ϸ�
   0�� �ƴ� �ٸ����� �����ϹǷ� ������ ����� �ǴܵǸ�
   �ȳ��� ���α׷��� ���� */
   state = fclose(fp);
   if (state != 0){
   printf("File Close Error!\n");
   return 1;
   }
   return 0;
}

//������� ������ �����ϴ� �Լ�
void Add(User* ptr, int* num){
   //���������� �� ���� ������
   if (*num < MAX_NUM){
      printf("��¥�� �Է��Ͻÿ�(6�ڸ����Է� ex.161225): ");
      scanf("%s", ptr[*num].date);

      while( ptr[5].date==NULL || ptr[4].date==NULL || ptr[3].date==NULL || ptr[2].date==NULL || ptr[1].date==NULL) {
         printf("6�ڸ��� �Է��Ͻÿ�");
         printf("��¥�� �Է��Ͻÿ�(6�ڸ����Է� ex.161225): ");
         scanf("%s", ptr[*num].date);
      }

      printf("������ �Է��ϼ���: ");
      scanf("%s", ptr[*num].description);
      (*num)++;
      printf(" ����Ǿ����ϴ�. \n\n");
   }
   //���� ������ �� ����
   else
      printf("  ���̻� ������ �� �����ϴ�. \n\n");
}

//������� ������ �����ϴ� �Լ�
int deleted(User* ptr, int* num){
   char date[30];
   int i, j;

   //���� ������ �Ѱ��� ����������
   if (*num > 0){
      printf("��¥�� �Է��ϼ���: ");
      scanf("%s", date);

      for (i = 0; i < MAX_NUM; i++){
         //���ڿ��̹Ƿ� ���ϱ����� strcmp���
         if (strcmp(date, ptr[i].date) == 0){
            (*num)--;
            printf("  �����Ǿ����ϴ�. \n\n");
            //�����Ͱ� ���� ���� �ʾҴٸ�
            if (i != MAX_NUM - 1){
               for (j = i; j < MAX_NUM; j++){
                  //���ڿ��̹Ƿ� strcpy�� ����Ͽ� ������ ����
                  strcpy(ptr[j].date, ptr[j + 1].date);
                  strcpy(ptr[j].description, ptr[j + 1].description);
               }
               //����ü �迭�� �������� NULL�� �ٲ�
               *ptr[MAX_NUM - 1].date = NULL;
               *ptr[MAX_NUM - 1].description = NULL;
            }

            //�����Ͱ� ���� á�ٸ�
            else{
               //����ü �迭�� �������� NULL�� �ٲ�
               *ptr[MAX_NUM - 1].date = NULL;
               *ptr[MAX_NUM - 1].description = NULL;
            }
            return 0;
         }
      }
      printf("ã�����߽��ϴ�. \n\n");
      return 0;
   }

   //����� ���� ������ ���ٸ�
   else{
      printf(" ����� ������ �����ϴ�. \n\n");
      return 0;
   }
}

//������� ������ �˻��ϴ� �Լ�
int search(User* ptr, int* num){
   char date[30];
   int i;

   //����� �����Ͱ� �ִٸ�
   if (*num > 0){
      printf("��¥�� �Է��ϼ���: ");
      scanf("%s", date);

      for (i = 0; i < MAX_NUM; i++){
         //strcmp�� ���ڿ��� ��ġ�Ҷ� 0�� ��ȯ
         //0�� C���� ������ �ǹ�
         //�׷��Ƿ� ! �� �ٿ� ������ �����Ͽ� ����
         if (!strcmp(date, ptr[i].date)){
            printf("%6s", "\n��   ¥  ");
            printf("%7s\n", "  ��   ��   \n");
            printf("%s ", ptr[i].date);
            printf("%s \n", ptr[i].description);
            printf(" �˻��� �Ϸ��߽��ϴ�. \n\n");
            return 0;
         }
      }
      printf("ã�����Ͽ����ϴ�. \n\n");
      return 0;
   }
   else{
      printf(" ����� ������ �����ϴ�. \n\n");
      return 0;
   }
}

//����� ��� �̸��� ��ȭ��ȣ ������ ����ϴ� �Լ�
void View(User* ptr, int* num){
   int i = 0;
   if (*num > 0){
      for (i = 0; i < *num; i++){
         printf("%6s", "\n��   ¥  ");
         printf("%7s\n", "  ��   ��   \n");
         printf("%s ", ptr[i].date);
         printf("%s \n", ptr[i].description);
      }
   }
   else
      printf("  ����� ������ �����ϴ�. \n\n");
}