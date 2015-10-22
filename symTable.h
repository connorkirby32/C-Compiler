#ifndef SYMTAB_H
#define SYMTAB_H

/* Symbol Table Function Headers */

node * CreateTable(node * statck);

node * PushLevel(node * statck, int data);

node * PopLevel(node * statck);

node * DestroyTable(node * statck);

node * PrintTable(node * statck);



/* IdentifierTree Function Headers */

void PrintIdentifiers(treeNode *leaf);

treeNode * InsertIdentifier(treeNode *leaf,int data, flagContainer flagInfo);

treeNode * DeleteIdentifier(treeNode *leaf,int data);

treeNode * FindIdentifier(treeNode *leaf,int data);

treeNode * DeleteTree(treeNode *leaf);

treeNode* Shadows(int id, node * top);

treeNode* FindIDTableScope(int id, node * top);

#endif
