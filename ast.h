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

typedef struct storage_class_specifier_node
{
    char * storage_class_type;

}StorageClassTypeNode;

typedef struct type_specifier_node
{
    char * type;
    StructOrUnionSpecifierNode * struct_or_union_specifier;
    EnumSpecifier * enum_specifier; 
    
}TypeSpecifierNode;

typedef struct type_qualifier_node
{
    char * type;
}TypeQualifierNode;


typedef struct struct_or_union_specifier_node
{

    StructOrUnionNode * struct_or_union;
    Identifier * identifier;
    StructDeclarationList * struct_declartion_list;


}StructOrUnionSpecifierNode;

typedef struct struct_or_union_node
{
    char * type; 

}StructOrUnionNode;


typedef struct struct_declaration_list_node
{

    StructDeclarationNode * struct_declaration;
    StructDeclarationListNode * struct_declaration_list;


}StructDeclarationList; 


typedef struct init_declarator_list_node
{

   InitDeclaratorList * init_declarator_list;
   InitDeclarator * init_declarator; 
   


}InitDeclaratorList; 

typedef struct init_declarator_node_node
{

   InitializerNode* initializer;
   Declarator * declarator; 
   


}InitDeclarator;

typedef struct struct_declaration_node_node
{

   SpecifierQualifierList* specifier_qualifier_list;     
   StructDeclaratorList * struct_declarator_list; 
   
}StructDeclarationNode;

typedef struct specifier_qualifier_list_node
{

   TypeSpecifierNode * type_specifier; 
   TypeQualifierNode * type_qualifier;    
   SpecifierQualifierListNode * specifier_qualifier_list; 
  
}SpecifierQualifierListNode;


typedef struct struct_declarator_list_node
{

   StructDeclaratorListNode * struct_declarator_list; 
   StructDeclaratorNode * struct_declarator;    
  
}StructDeclaratorListNode;

typedef struct struct_declarator_node
{

   DeclaratorNode * declarator; 
   StructDeclaratorNode * struct_declarator;  
   ConstantExpressionNode * constant_expression;  
  
}StructDeclaratorNode;


typedef struct enum_specifier_node
{

   char * ENUM; 
   EnumeratorListNode enumerator_list; 
   IdentifierNode * identifier; 
  
}EnumSpecifierNode;


typedef struct enumerator_list_node
{

   EnumeratorListNode * enumerator_list; 
   EnumeratorNode * enumerator; 
  
}EnumeratorListNode;


typedef struct enumerator_node
{
   //TODO go back and add characters being returned as characters i.e. =, +, - etc
   ConstantExpressionNode * constant_expression;
   IdentifierNode * identifier; 
  
}EnumeratorNode;


typedef struct declarator_node
{

   DirectDeclaratorNode * direct_declarator; 
   PointerNode * pointer;
  
}DeclaratorNode;


typedef struct direct_declarator_node_node
{
   IdentifierNode * identifier;
   DeclaratorNode * declarator;
   DirectDeclaratorNode * direct_declarator; 
   ConstantExpressionNode * constant_expression;
   PointerNode * pointer;
   ParaneterTypeListNode * parameter_type_list;
   IdentifierListNode * identifier_list; 
  
}DirectDeclaratorNode;


typedef struct pointer_node
{

    TypeQualiferListNode * type_qualifier_list;
    PointerNode * pointer;
}PointerNode;

typedef struct type_qualifier_list_node
{

    TypeQualifierNode * type_qualifier;
    TypeQualifierListNode * type_qualifier_list;
}TypeQualiferListNode;

typedef struct parameter_type_list_node{

    ParameterListNode * parameter_list;
    char * ELIPSIS; 
}ParameterTypeListNode;

typedef struct parameter_declaration_node
{

    DeclarationSpecifiersNode * declaration_specifiers;
    DeclaratorNode * declarator;
    AbstractDeclaratorNode * abstract_declarator; 
    
}ParameterDeclarationNode;

typedef struct identifier_list_node
{

   IdentifierNode * identifier;
   IdentifieListNode * identifier_list;
    
}IdentifierListNode;

typedef struct initializer_node
{

   InitializerListNode * initializer_list;
   AssignmentExpressionNode * assignment_expression;
    
}InitializerNode;

typedef struct initializer_list_node
{

   InitializerNode * initializer;
   InitializerListNode * initializer_list;
    
}InitializerListNode;

typedef struct type_name_node
{

   AbstractDeclaratorNode * abstract_declarator;
   SpecifierQualifierListNode * specifier_qualifier_list; 
    
}TypeNameNode;

typedef struct abstract_declarator_node
{

  PointerNode * pointer;
  DirectAbstractDeclaratorNode * direct_abstract_declarator;
  ConstantExpressionNode * constant_expression;
    
}AbstractDeclaratorNode;

typedef struct type_name_node
{

  PointerNode * pointer;
  DirectAbstractDeclaratorNode * direct_abstract_declarator;
  AbstractDeclaratorNode * abstract_declarator;
  ConstantExpressionNode * constant_expression;
  ParameterListNode * parameter_list;
    
}DirectAbstractDeclaratorNode;

typedef struct statement_node
{

  LabeledStatementNode * labeled_statement;
  CompoundStatementNode * compound_statement;
  ExpressionStatementNode * expression_statement;
  SelectionStatementNode * selection_statement;
  IterationStatementNode * iteration_statement;
  JumpStatementNode * jump_statement;
    
}StatementNode;

typedef struct labeled_statement_node
{
    
  IdentifierNode * identifier;
  ConstantExpressionNode * constant_expression;
  StatementNode * statement;
  char * CASE; 
  char * COLON;
  char * DEFAULT;


}LabeledStatementNode;

typedef struct expression_statement_node
{

  char * SEMICOLON;
  ExpressionNode * expression;
  
    
}ExpressionStatementNode;

typedef struct compound_statement_node
{

  char * LEFTBRACKET;
  char * RIGHTBRACKET;
  StatementListNode * statment_list;
  DeclarationListNode * declaration_list;
    
}CompoundStatementNode;


typedef struct statement_list_node
{
  StatementListNode * statementList;
  StatementNode * statement;


}StatementListNode;

typedef struct selection_statement_node
{

  ExpressionNode * expressionNode;
  StatementNode * statement;
  StatementNode * statement2;
  char * IF;
  char * ELSE:
  char * SWITCH;
  char * LEFTPAREN;
  char * RIGHTPAREN;

}SelectionStatementNode:

typedef struct iteration_statement_node
{

  ExpressionNode * expressionNode;
  ExpressionNode * expressionNode1;
  ExpressionNode * expressionNode2;
  ExpressionStatementNode * expression_statement;
  StatementNode * statement;
  char * WHILE;
  char * DO:
  char * FOR;
  char * LEFTPAREN;
  char * RIGHTPAREN;
  char * SEMICOLON;

}IterationStatementNode;

typedef struct iteration_statement_node
{

  IdentifierNode * identifier;
  ExpressionNode * expressionNode;
  char * RETURN;
  char * BREAK:
  char * RETURN;
  char * SEMICOLON;

}JumpStatementNode:

#endif







