#include <stdio.h>
#include <unistd.h>
#include "y.tab.h"


#define bool int
#define true 1
#define false 0
//TODO CHANGE NODE NAMES


//File pointers 
extern FILE *yyin;
extern FILE *lexFile;
extern FILE *parseFile;
extern FILE *symbolTableFile;

//Debug flags
extern int parseDebug;
extern int lexDebug ;
extern int symbolTableDebug;

//Debug info
extern int rowNum;
extern int tabSize;
extern int column;
extern char * buffer;
extern long bufferSize;

//For symbol table and parser
extern bool lookUpMode; 

#ifndef DRIVER_H
#define DRIVER_H
//Any type definitions needed
typedef struct node
{
    int size;
    int level;
    struct treeNode *treePtr;
    struct node *ptr;
} node;

//Flag Container
typedef struct FlagTypes
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
    bool typedef_flag;
    bool char_flag;
    bool int_flag;
    bool volatile_flag;


    //Storage Flag	
    bool auto_flag;
    bool register_flag;
    bool static_flag;
    bool extern_flag;
    bool const_flag;
        
}flagContainer;

//BST Tree Structure
typedef struct treeNode
{
    //Type and storage information
    flagContainer  flags;        
    //Data Containers
    int * dataI;
    float dataD;
    char * dataC;
    
    int declerationLineNumber; 
    int id;
    char * name;
    
    
    struct treeNode *left;
    struct treeNode *right;
    
}treeNode;

//Sybmol Table
extern node * symbolTable;
extern treeNode* currentIdentifier;
extern flagContainer flags;
extern flagContainer reset;

#endif 









