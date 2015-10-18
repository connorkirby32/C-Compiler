#ifndef SYMTAB_H
#define SYMTAB_H

/* Symbol Table Function Headers */

node * createTable(node * statck);

node * pushLevel(node * statck, int data);

node * popLevel(node * statck);

node * destroyTable(node * statck);

node * printTable(node * statck);



/* IdentifierTree Function Headers */

void printIdentifiers(treeNode *leaf);

treeNode * insertIdentifier(treeNode *leaf,int data);

treeNode * deleteIdentifier(treeNode *leaf,int data);

treeNode * findIdentifier(treeNode *leaf,int data);

treeNode * deleteTree(treeNode *leaf);

treeNode* shadows(int id);

#endif
