#include <stdio.h>
#include <unistd.h>
#include "y.tab.h"


#define bool int
#define true 1
#define false 0




extern bool lookUpToggle;
extern bool lexDebug;
extern bool parseDebug;
extern bool symbolTableDebug;
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
    //Type Flags
    bool void_flag;
    bool short_flag;    
    bool bool_flag;
    bool long_flag;
    bool float_flag;
    bool double_flag;  
    bool signed_flag;
    bool unsigned_flag;   
    bool struct_flag;
    bool enum_flag;
    bool typedef_id;
    
    
    //Storage Flag	
	bool auto_flag;
	bool register_flag;
	bool static_flag;
	bool extern_flag;
	
    
    
    //Data Containers
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









