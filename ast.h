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

typedef struct direct_declarator_node
{
   IdentifierNode * identifier;
   DeclaratorNode * declarator;
   DirectDeclaratorNode * direct_declarator; 
   ConstantExpressionNode * constant_expression;
   PointerNode * pointer;
   ParaneterTypeListNode * parameter_type_list;
   IdentifierListNode * identifier_list; 
  
}DeclaratorNode;


#endif


pointer
	: '*'
		{if(parseDebug){
			fprintf(parseFile,"pointer <- '*' \n\n");
			}
		}
	| '*' type_qualifier_list
		{if(parseDebug){
			fprintf(parseFile,"pointer <- '*' type_qualifier_list \n\n");
			}
		}
	| '*' pointer
		{if(parseDebug){
			fprintf(parseFile,"pointer <- '*' pointer \n\n");
			}
		}
	| '*' type_qualifier_list pointer
		{if(parseDebug){
			fprintf(parseFile,"pointer <- '*' type_qualifier_list pointer \n\n");
			}
		}
	;

type_qualifier_list
	: type_qualifier
		{if(parseDebug){
			fprintf(parseFile,"type_qualifier_list <- type_qualifier \n\n");
			}
		}
	| type_qualifier_list type_qualifier
		{if(parseDebug){
			fprintf(parseFile,"type_qualifier_list <- type_qualifier_list type_qualifier_list \n\n");
			}
		}
	;

parameter_type_list
	: parameter_list
		{if(parseDebug){
			fprintf(parseFile,"parameter_type_list <- parameter_list \n\n");
			}
		}
	| parameter_list ',' ELIPSIS
		{if(parseDebug){
			fprintf(parseFile,"parameter_type_list <- parameter_list ',' ELIPSIS \n\n");
			}
		}
	;

parameter_list
	: parameter_declaration
		{if(parseDebug){
			fprintf(parseFile,"parameter_list <- parameter_declaration \n\n");
			}
		}
	| parameter_list ',' parameter_declaration
		{if(parseDebug){
			fprintf(parseFile,"parameter_list <- parameter_list ',' parameter_declaration \n\n");
			}
		}
	;

parameter_declaration
	: declaration_specifiers declarator
		{if(parseDebug){
			fprintf(parseFile,"parameter_declaration <- declaration_specifiers declarator \n\n");
			}
		}
	| declaration_specifiers
		{if(parseDebug){
			fprintf(parseFile,"parameter_declaration <- declaration_specifiers \n\n");
			}
		}
	| declaration_specifiers abstract_declarator
		{if(parseDebug){
			fprintf(parseFile,"parameter_declaration <- declaration_specifiers abstract_declarator \n\n");
			}
		}
	;

identifier_list
	: identifier
		{if(parseDebug){
			fprintf(parseFile,"identifier_list <- identifier \n\n");
			}
		}
	| identifier_list ',' identifier
		{if(parseDebug){
			fprintf(parseFile,"identifier_list <- identifier_list ',' identifier \n\n");
			}
		}
	;

initializer
	: assignment_expression
		{if(parseDebug){
			fprintf(parseFile,"initializer <- assignment_expression \n\n");
			}
		}
	| '{' initializer_list '}'
		{if(parseDebug){
			fprintf(parseFile,"initializer <- '{' initializer_list '}' \n\n");
			}
		}
	| '{' initializer_list ',' '}'
		{if(parseDebug){
			fprintf(parseFile,"initializer <- '{' initializer_list ',' '}' \n\n");
			}
		}
	;

initializer_list
	: initializer
		{if(parseDebug){
			fprintf(parseFile,"initializer_list <- initializer \n\n");
			}
		}
	| initializer_list ',' initializer
		{if(parseDebug){
			fprintf(parseFile,"initializer_list <- initializer_list ',' initializer \n\n");
			}
		}
	;

type_name
	: specifier_qualifier_list
		{if(parseDebug){
			fprintf(parseFile,"type_name <- specifier_qualifier_list \n\n");
			}
		}
	| specifier_qualifier_list abstract_declarator
		{if(parseDebug){
			fprintf(parseFile,"type_name <- specifier_qualifier_list abstract_declarator \n\n");
			}
		}
	;

abstract_declarator
	: pointer
		{if(parseDebug){
			fprintf(parseFile,"abstract_declarator <- pointer \n\n");
			}
		}
	| direct_abstract_declarator
		{if(parseDebug){
			fprintf(parseFile,"abstract_declarator <- direct_abstract_declarator \n\n");
			}
		}
	| pointer direct_abstract_declarator
		{if(parseDebug){
			fprintf(parseFile,"abstract_declarator <- pointer direct_abstract_declarator \n\n");
			}
		}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
		{if(parseDebug){
			fprintf(parseFile,"direct_abstract_declarator <- '(' abstract_declarator ')' \n\n");
			}
		}
	| '[' ']'
		{if(parseDebug){
			fprintf(parseFile,"direct_abstract_declarator <- '[' ']' \n\n");
			}
		}
	| '[' constant_expression ']'
		{if(parseDebug){
			fprintf(parseFile,"direct_abstract_declarator <- '[' constant_expression ']' \n\n");
			}
		}
	| direct_abstract_declarator '[' ']'
		{if(parseDebug){
			fprintf(parseFile,"direct_abstract_declarator <- direct_abstract_declarator '[' ']' \n\n");
			}
		}
	| direct_abstract_declarator '[' constant_expression ']'
		{if(parseDebug){
			fprintf(parseFile,"direct_abstract_declarator <- direct_abstract_declarator '[' constant_expression ']' \n\n");
			}
		}
	| '(' ')'
		{if(parseDebug){
			fprintf(parseFile,"direct_abstract_declarator <- '(' ')' \n\n");
			}
		}
	| '(' parameter_type_list ')'
		{if(parseDebug){
			fprintf(parseFile,"direct_abstract_declarator <- '(' parameter_type_list ')' \n\n");
			}
		}
	| direct_abstract_declarator '(' ')'
		{if(parseDebug){
			fprintf(parseFile,"direct_abstract_declarator <- direct_abstract_declarator '(' ')' \n\n");
			}
		}
	| direct_abstract_declarator '(' parameter_type_list ')'
		{if(parseDebug){
			fprintf(parseFile,"direct_abstract_declarator <- direct_abstract_declarator '(' parameter_type_list ')' \n\n");
			}
		}
	;

statement
	: labeled_statement
		{if(parseDebug){
			fprintf(parseFile,"statement <- labeled_statement \n\n");
			}
		}
	| compound_statement
		{if(parseDebug){
			fprintf(parseFile,"statement <- compound_statement \n\n");
			}
		}
	| expression_statement
		{if(parseDebug){
			fprintf(parseFile,"statement <- expression_statement \n\n");
			}
		}
	| selection_statement
		{if(parseDebug){
			fprintf(parseFile,"statement <- selection_statement \n\n");
			}
		}
	| iteration_statement
		{if(parseDebug){
			fprintf(parseFile,"statement <- iteration_statement \n\n");
			}
		}
	| jump_statement
		{if(parseDebug){
			fprintf(parseFile,"statement <- jump_statement \n\n");
			}
		}
	;

labeled_statement
	: identifier ':' statement
		{if(parseDebug){
			fprintf(parseFile,"labeled_statement <- identifier ':' \n\n");
			}
		}
	| CASE constant_expression ':' statement
		{if(parseDebug){
			fprintf(parseFile,"labeled_statement <- CASE constant_expression ':' statement \n\n");
			}
		}
	| DEFAULT ':' statement
		{if(parseDebug){
			fprintf(parseFile,"DEFAULT ':' statement \n\n");
			}
		}
	;

expression_statement
	: ';'
		{if(parseDebug){
			fprintf(parseFile,"expression_statement <- ';' \n\n");
			}
		}
	| expression ';'
		{if(parseDebug){
			fprintf(parseFile,"expression_statement <- expression ';' \n\n");
			}
		}
	;

compound_statement
	: '{' '}'
		{if(parseDebug){
			fprintf(parseFile,"compound_statement <- '{' '}' \n\n");
			}
		}
	| '{' statement_list '}'
		{if(parseDebug){
			fprintf(parseFile,"compound_statement <- '{' statement_list '}' \n\n");
			}
		}
	| '{' declaration_list '}'
		{if(parseDebug){
			fprintf(parseFile,"compound_statement <- '{' declaration_list '}' \n\n");
			}
		}
	| '{' declaration_list statement_list '}'
		{if(parseDebug){
			fprintf(parseFile,"compound_statement <- '{' declaration_list statement_list '}'  \n\n");
			}
			
			
		}
	;

statement_list
	: statement
		{if(parseDebug){
			fprintf(parseFile,"statement_list <- statement  \n\n");
			}
			

		}
	| statement_list statement
		{if(parseDebug){
			fprintf(parseFile,"statement_list <- statement_list statement \n\n");
			}

		}
	;

selection_statement
	: IF '(' expression ')' statement
		{if(parseDebug){
			fprintf(parseFile,"selection_statement <- IF '(' expression ')' statement  \n\n");
			}
		}
	| IF '(' expression ')' statement ELSE statement
		{if(parseDebug){
			fprintf(parseFile,"selection_statement <- IF '(' expression ')' statement ELSE statement \n\n");
			}
		}
	| SWITCH '(' expression ')' statement
		{if(parseDebug){
			fprintf(parseFile,"selection_statement <- SWITCH '(' expression ')' statement \n\n");
			}
		}
	;

iteration_statement
	: WHILE '(' expression ')' statement
		{if(parseDebug){
			fprintf(parseFile,"iteration_statement <- WHILE '(' expression ')' statement \n\n");
			}
		}
	| DO statement WHILE '(' expression ')' ';'
		{if(parseDebug){
			fprintf(parseFile,"iteration_statement <- DO statement WHILE '(' expression_statement ')'; \n\n");
			}
		}
	| FOR '(' ';' ';' ')' statement
		{if(parseDebug){
			fprintf(parseFile,"iteration_statement <- FOR '(' ';' ';' ')' statement \n\n");
			}
		}
	| FOR '(' ';' ';' expression ')' statement
		{if(parseDebug){
			fprintf(parseFile,"iteration_statement <- FOR '(' ';' ';' expression ')' statement \n\n");
			}
		}
	| FOR '(' ';' expression ';' ')' statement
		{if(parseDebug){
			fprintf(parseFile,"iteration_statement <- FOR '(' ';' expression ';' ')' statement \n\n");
			}
		}
	| FOR '(' ';' expression ';' expression ')' statement
		{if(parseDebug){
			fprintf(parseFile,"iteration_statement <- FOR '(' ';' expression ';' expression ')' statement \n\n");
			}
		}
	| FOR '(' expression ';' ';' ')' statement
		{if(parseDebug){
			fprintf(parseFile,"iteration_statement <- FOR '(' expression ';' ';' ')' statement \n\n");
			}
		}
	| FOR '(' expression ';' ';' expression ')' statement
		{if(parseDebug){
			fprintf(parseFile,"iteration_statement <- FOR '(' expression ';' ';' expression ')' statement \n\n");
			}
		}
	| FOR '(' expression ';' expression ';' ')' statement
		{if(parseDebug){
			fprintf(parseFile,"iteration_statement <- FOR '(' expression ';' expression ';' ')' statement \n\n");
			}
		}
	| FOR '(' expression ';' expression ';' expression ')' statement
		{if(parseDebug){
			fprintf(parseFile,"iteration_statement <- FOR '(' expression ';' expression ';' expression ')' statement \n\n");
			}
		}
	;

jump_statement
	: GOTO identifier ';'
		{if(parseDebug){
			fprintf(parseFile,"jump_statement <- GOTO identifier ';' \n\n");
			}
		}
	| CONTINUE ';'
		{if(parseDebug){
			fprintf(parseFile,"jump_statement <- CONTINUE ';' \n\n");
			}
		}
	| BREAK ';'
		{if(parseDebug){
			fprintf(parseFile,"jump_statement <- BREAK ';' \n\n");
			}
		}
	| RETURN ';'
		{if(parseDebug){
			fprintf(parseFile,"jump_statement <- RETURN ';' \n\n");
			}
		}
	| RETURN expression ';'
		{if(parseDebug){
			fprintf(parseFile,"jump_statement <- RETURN expression';' \n\n");
			}
		}
	;



