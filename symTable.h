#ifndef SYMTAB_H
#define SYMTAB_H

/* Symbol Table Function Headers */

void createTable(void);

void pushLevel(int data);

void popLevel(void);

void destroyTable(void);

void printTable(void);

/* IdentifierTree Function Headers */

void printIdentifiers(treeNode *leaf);

treeNode * insertIdentifier(treeNode *leaf,int data);

treeNode * deleteIdentifier(treeNode *leaf,int data);

treeNode * findIdentifier(treeNode *leaf,int data);

treeNode* shadows(int id);

#endif
