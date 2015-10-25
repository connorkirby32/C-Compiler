#include "driver.h"
#include <stdlib.h>

#ifndef AST_H
#define AST_H

//All AST structure Decleartions
//God Help Us
typedef struct translation_unit_node
{
    struct TranslationUnitNode *translation_unit_list;
    struct ExternalDeclarationNode *external_declaration;
} TranslationUnitNode;



typedef struct external_declaration_node
{
    struct FunctionDefinitionNode *function_definition;
    struct DeclarationNode * declaration;
} ExternalDeclarationNode;



typedef struct function_definition_node
{
    struct DeclaratorCompoundStatementNode *declarator_compound_statment;
    struct DeclaratorDeclartionListNode * declarator_declaration_list;
    struct CompoundStatementNode * compound_statement; 
    struct DeclarationSpecifiersNode * declaration_specifier;
    struct DeclarationNode * declaration; 
} FunctionDefinitionNode;



typedef struct declaration_node
{
    struct DeclarationSpecifiersNode * declaration_specifiers;
    struct InitDeclaratorListNode * declaration_specifier;
    struct node *ptr;
} DeclarationNode;




typedef struct declaration_list_node
{
    struct DeclarationNode * declaration;
    struct DeclarationList * declaration_list;
    
} DeclarationListNode;



typedef struct declaration_specifiers_node
{

    struct StorageClassSpecifier * storage_class_specifier;
    struct DeclartionSpecifiersNodes * declaration_specifiers;
    struct TypeSpecifierNode * type_specifier;
    struct TypeQualifier * type_qualifier;

} DeclarationSpecifiersNode;


typedef struct storage_class_specifier_node
{

    struct StorageClassSpecifier * storage_class_specifier;
    struct DeclartionSpecifiersNodes * declaration_specifiers;
    struct TypeSpecifierNode * type_specifier;
    struct TypeQualifier * type_qualifier;

} StorageClassSpecifierNode;

typedef struct storage_class_specifier
{
    char * storage_class_type;

}StorageClassTypeNode;

typedef struct type_specifier
{
    char * type;
}TypeSpecifierNode;

typedef struct type_qualifier
{
    char * type;
}TypeQualifierNode;


#endif



