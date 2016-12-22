#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "home.h"

struct phonebooks {
   char name[10];
   char phone[14];
   struct phonebooks *next;
};

typedef struct phonebooks phonebook;

void Phonebook(void);
void addPhonebook(phonebook*);
void viewPhonebook(phonebook*);
void deletePhonebook(phonebook*);
void searchPhonebook(phonebook*);