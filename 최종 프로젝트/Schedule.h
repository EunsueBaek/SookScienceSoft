#include "home.h"

#define MAX_NUM 100

typedef struct{
   char date[30];
   char description[30];
}User;

void Schedule(void);
int saveFile2(User* ptr, int* num);
int openFile2(User* ptr, int* num);
void Add2(User* ptr, int* num);
int deleted2(User* ptr, int* num);
int search2(User* ptr, int* num);
void View2(User* ptr, int* num);