#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_SIZE 100
#define MULTIPLIER 31

typedef enum  {START, QUIT, ATRIB, ADD, SUB, MUL, PRINT, READ, IF, GOTO, LABEL} OpKind;
typedef enum {INT_CONST, STRING, EMPTY} ElemKind;

typedef struct{
  ElemKind kind;
  union
  {
    int val;
    char* name;
  }content;
} Elem;

typedef struct{
  OpKind op;
  Elem first, second, third;
  int type, index;
} Instr;

Elem mkVar(char*);
Elem mkInt(int);
Elem empty();
Instr mkInstr(OpKind, Elem, Elem, Elem, int, int);
int getVal(Elem );
char* getName(Elem);
void escrever(Instr);
void removeSpaces(char*);
Instr parseInstr(char*, int);
int getType(char*, char*);

//---------------LIST--------------------

typedef struct list{
   Instr head;
   struct list *tail;
} *ILIST;

ILIST mkList(Instr, ILIST);
Instr head(ILIST);
ILIST tail(ILIST);
void printList(ILIST);
ILIST append(ILIST, ILIST);
ILIST addLast(Instr, ILIST);
int getIndex(char*, ILIST);

//-----------HASH----------------------

typedef struct List List;
struct List{
  char* key;
  int value;
  List* next;
};

List* table[HASH_SIZE];

unsigned int hash(char*);
List* lookup(char*);
void insert(char*, int);
void display();
void init_table();
int getHashValue(List*);
char* getHashKey(List*);
