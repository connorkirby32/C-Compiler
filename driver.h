#include <stdio.h>
#include <unistd.h>
#include "y.tab.h"


extern int lookUpToggle;
extern int lexDebug;
extern int parseDebug;
extern int symbolTableDebug;
extern FILE *lexFile;
extern FILE *parseFile;
extern FILE *symbolTableFile;


extern int rowNum;
extern int tabSize;
extern int column;

#ifndef DRIVER_H
#define DRIVER_H
//Any type definitions needed
typedef struct node
{
    int level;
    struct treeNode *treePtr;
    struct node *ptr;
} node;

//BST Tree Structure
typedef struct treeNode
{

    int dataI;
    float dataF;
    char dataC;
    char * dataS;
    int dataE;
    
    int declerationLineNumber; 
    int id;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

//Global data that will be defined in main.c
extern node * top;
extern node * cursor;
extern node * temp;

extern treeNode* currentIdentifier; 


extern int count;
#endif 









