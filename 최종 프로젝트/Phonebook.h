#include "home.h"

#define MAX_NUM 100

typedef struct{
   char name[30];
   char phone[30];
}phonebook;

void Phonebook(void);
int saveFile(phonebook* ptr2, int* num);
int openFile(phonebook* ptr2, int* num);
void Add(phonebook* ptr2, int* num);
int deleted(phonebook* ptr2, int* num);
int search(phonebook* ptr2, int* num);
void View(phonebook* ptr2, int* num);