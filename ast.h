#include "driver.h"
#include <stdlib.h>

#ifndef AST_H
#define AST_H

//All AST structure Decleartions
//God Help Us
typedef struct translation_unit_node
{
    struct TranslationUnitNode; *translation_unit_list;
    struct ExternalDeclarationNode *external_declaration;
} TranslationUnitNode;

typedef struct external_declaration_node
{
    struct treeNode *treePtr;
    struct node *ptr;
} ExternalDeclarationNode;


#endif



