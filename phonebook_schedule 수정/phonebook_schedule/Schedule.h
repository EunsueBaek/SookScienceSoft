#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "home.h"

struct _node {
   char date[7];      
   char description[15];   
   struct _node *link;
};

typedef struct _node node;

void Schedule(void);
void Add(node*);      
void Delete(node*);      
void View(node*);  
void Search(node*);