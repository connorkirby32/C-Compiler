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
    struct InitDeclaratorListNode * init_declarator_list;
    struct node *ptr;
} DeclarationNode;

typedef struct declaration_list_node
{
  struct DeclarationNode * declaration;
  struct DeclarationList * declaration_list;
    
} DeclarationListNode;

typedef struct declaration_specifiers_node
{
    struct StorageClassSpecifierNode * storage_class_specifier;
    struct DeclartionSpecifiersNodes * declaration_specifiers;
    struct TypeSpecifierNode * type_specifier;
    struct TypeQualifier * type_qualifier;
} DeclarationSpecifiersNode;


typedef struct storage_class_specifier_node
{

  char * SPECIFIER;
  
} StorageClassSpecifierNode;



typedef struct type_specifier_node
{

    struct StructOrUnionSpecifierNode * struct_or_union_specifier;
    struct EnumSpecifier * enum_specifier; 
    char * type;
    
} TypeSpecifierNode;

typedef struct type_qualifier_node
{
    char * type;
} TypeQualifierNode;


typedef struct struct_or_union_specifier_node
{

    struct StructOrUnionNode * struct_or_union;
    struct Identifier * identifier;
    struct StructDeclarationList * struct_declartion_list;


} StructOrUnionSpecifierNode;


typedef struct struct_or_union_node
{
    char * type; 

}StructOrUnionNode;


typedef struct struct_declaration_list_node
{

    struct StructDeclarationNode * struct_declaration;
    struct StructDeclarationListNode * struct_declaration_list;


}StructDeclarationListNode; 


typedef struct init_declarator_list_node
{

   struct InitDeclaratorListNode * init_declarator_list;
   struct InitDeclaratorNode * init_declarator; 
   


}InitDeclaratorListNode; 

typedef struct init_declarator_node
{

   struct InitializerNode* initializer;
   struct DeclaratorNode * declarator; 
   


}InitDeclaratorNode;

typedef struct struct_declaration_node
{

   struct SpecifierQualifierListNode* specifier_qualifier_list;     
   struct StructDeclaratorListNode * struct_declarator_list; 
   
}StructDeclarationNode;

typedef struct specifier_qualifier_list_node
{

   struct TypeSpecifierNode * type_specifier; 
   struct TypeQualifierNode * type_qualifier;    
   struct SpecifierQualifierListNode * specifier_qualifier_list; 
  
}SpecifierQualifierListNode;


typedef struct struct_declarator_list_node
{

   struct StructDeclaratorListNode * struct_declarator_list; 
   struct StructDeclaratorNode * struct_declarator;    
  
}StructDeclaratorListNode;

typedef struct struct_declarator_node
{

   struct DeclaratorNode * declarator; 
   struct StructDeclaratorNode * struct_declarator;  
   struct ConstantExpressionNode * constant_expression;  
  
}StructDeclaratorNode;


typedef struct enum_specifier_node
{

   struct EnumeratorListNode * enumerator_list; 
   struct IdentifierNode * identifier; 
   char * ENUMt; 
}EnumSpecifierNode;


typedef struct enumerator_list_node
{

   struct EnumeratorListNode * enumerator_list; 
   struct EnumeratorNode * enumerator; 
  
}EnumeratorListNode;


typedef struct enumerator_node
{
   //TODO go back and add characters being returned as characters i.e. =, +, - etc
   struct ConstantExpressionNode * constant_expression;
   struct IdentifierNode * identifier; 
  
}EnumeratorNode;


typedef struct declarator_node
{

   struct DirectDeclaratorNode * direct_declarator; 
   struct PointerNode * pointer;
  
}DeclaratorNode;


typedef struct direct_declarator_node
{
   struct IdentifierNode * identifier;
   struct DeclaratorNode * declarator;
   struct DirectDeclaratorNode * direct_declarator; 
   struct ConstantExpressionNode * constant_expression;
   struct PointerNode * pointer;
   struct ParaneterTypeListNode * parameter_type_list;
   struct IdentifierListNode * identifier_list; 
  
}DirectDeclaratorNode;


typedef struct pointer_node
{

    struct TypeQualiferListNode * type_qualifier_list;
    struct PointerNode * pointer;
}PointerNode;

typedef struct type_qualifier_list_node
{

    struct TypeQualifierNode * type_qualifier;
    struct TypeQualifierListNode * type_qualifier_list;
}TypeQualiferListNode;

typedef struct parameter_type_list_node{

    struct ParameterListNode * parameter_list;
    char * ELIPSISt; 
}ParameterTypeListNode;

typedef struct parameter_declaration_node
{

    struct DeclarationSpecifiersNode * declaration_specifiers;
    struct DeclaratorNode * declarator;
    struct AbstractDeclaratorNode * abstract_declarator; 
    
}ParameterDeclarationNode;

typedef struct identifier_list_node
{

   struct IdentifierNode * identifier;
   struct IdentifieListNode * identifier_list;
    
}IdentifierListNode;

typedef struct initializer_node
{

   struct InitializerListNode * initializer_list;
   struct AssignmentExpressionNode * assignment_expression;
    
}InitializerNode;

typedef struct initializer_list_node
{

   struct InitializerNode * initializer;
   struct InitializerListNode * initializer_list;
    
}InitializerListNode;

typedef struct type_name_node
{

   struct AbstractDeclaratorNode * abstract_declarator;
   struct SpecifierQualifierListNode * specifier_qualifier_list; 
    
}TypeNameNode;

typedef struct abstract_declarator_node
{

  struct PointerNode * pointer;
  struct DirectAbstractDeclaratorNode * direct_abstract_declarator;
  struct ConstantExpressionNode * constant_expression;
    
}AbstractDeclaratorNode;

typedef struct direct_abstract_declarator_node
{

  struct PointerNode * pointer;
  struct DirectAbstractDeclaratorNode * direct_abstract_declarator;
  struct AbstractDeclaratorNode * abstract_declarator;
  struct ConstantExpressionNode * constant_expression;
  struct ParameterListNode * parameter_list;
    
}DirectAbstractDeclaratorNode;

typedef struct statement_node
{

  struct LabeledStatementNode * labeled_statement;
  struct CompoundStatementNode * compound_statement;
  struct ExpressionStatementNode * expression_statement;
  struct SelectionStatementNode * selection_statement;
  struct IterationStatementNode * iteration_statement;
  struct JumpStatementNode * jump_statement;
    
}StatementNode;

typedef struct labeled_statement_node
{
    
  struct IdentifierNode * identifier;
  struct ConstantExpressionNode * constant_expression;
  struct StatementNode * statement;
  char * CASEt; 
  char * COLONt;
  char * DEFAULTt;


}LabeledStatementNode;

typedef struct expression_statement_node
{

  char * SEMICOLONt;
  struct ExpressionNode * expression;
  
    
}ExpressionStatementNode;

typedef struct compound_statement_node
{

  char * LEFTBRACKETt;
  char * RIGHTBRACKETt;
  struct StatementListNode * statment_list;
  struct DeclarationListNode * declaration_list;
    
}CompoundStatementNode;


typedef struct statement_list_node
{
  struct StatementListNode * statementList;
  struct StatementNode * statement;


}StatementListNode;

typedef struct selection_statement_node
{

  struct ExpressionNode * expressionNode;
  struct StatementNode * statement;
  struct StatementNode * statement2;
  char * IFt;
  char * ELSEt;
  char * SWITCHt;
  char * LEFTPARENt;
  char * RIGHTPARENt;

}SelectionStatementNode;

typedef struct iteration_statement_node
{

  struct ExpressionNode * expressionNode;
  struct ExpressionNode * expressionNode1;
  struct ExpressionNode * expressionNode2;
  struct ExpressionStatementNode * expression_statement;
  struct StatementNode * statement;
  char * WHILEt;
  char * DOt;
  char * FORt;
  char * LEFTPARENt;
  char * RIGHTPARENt;
  char * SEMICOLONt;

}IterationStatementNode;

typedef struct jump_statement_node
{

  struct IdentifierNode * identifier;
  struct ExpressionNode * expressionNode;
  char * RETURNt;
  char * BREAKt;
  char * SEMICOLONt;

}JumpStatementNode;

typedef struct expression_node
{

  struct ExpressionNode * expressionNode;
  struct AssignmentExpressionNode * assignment_expression;
  char * COMMAt;

}ExpressionNode;

typedef struct assignment_expression_node
{
  struct ConditionalExpressionNode * conditional_expression;
  struct AssignmentExpressionNode * assignment_expression;
  struct AssignmentOperatorNode * assignment_operator;
  struct UnaryExpressionNode * unary_expression;


}AssignmentExpressionNode;

typedef struct assignment_operator_node
{
  char * MUL_ASSIGNt;
  char * DIV_ASSIGNt;
  char * MOD_ASSIGNt;
  char * ADD_ASSIGNt;
  char * SUB_ASSIGNt;
  char * LEFT_ASSIGNt;
  char * RIGHT_ASSIGNt;
  char * AND_ASSIGNt;
  char * XOR_ASSIGNt;


}AssignmentOperatorNode;

typedef struct conditional_expression_node
{

  struct ExpressionNode * expressionNode;
  struct LogicalOrExpressionNode * logical_or_expression;
  struct ConditionalExpressionNode * conditional_expression;
  char * COLONt;
  char * QUESTIONt;


}ConditionalExpressionNode;

typedef struct constant_expression_node
{
  struct ConditionalExpressionNode * conditional_expression;
  
}ConstantExpressionNode;

typedef struct logical_or_expression_node
{
  struct LogicalAndExpressionNode * logical_and_expression;
  struct LogicalOrExpressionNode * logical_or_expression;
  char * OR_OPt;
  
}LogicalOrExpressionNode;

typedef struct logical_and_expression
{
  struct LogicalAndExpressionNode * logical_and_expression;
  struct InclusiveOrExpressionNode * inclusive_or_expression;
  char * AND_OPt;
  
}LogicalAndExpressionNode;

typedef struct inclusive_or_expression
{
  struct ExclusiveOrExpressionNode * exclusive_or_expression;
  struct InclusiveOrExpressionNode * inclusive_or_expression;
  char * PIPEt;
  
}InclusiveOrExpressionNode;

typedef struct exclusive_or_expression
{
  struct ExclusiveOrExpressionNode * exclusive_or_expression;
  struct AndExpressionNode * and_expression;
  char * ARROWt;
  
}ExclusiveOrExpressionNode;

typedef struct and_expression_node
{

  struct EqualitiyExpressionNode * equality_expression;
  struct AndExpressionNode * and_expression;
  char * ANDt;
  
}AndExpressionNode;

typedef struct equality_expression_node
{

  struct RelationalExpressionNode * relational_expression;
  struct EqualityExpressionNode * equality_expression; 
  struct AndExpressionNode * and_expression;
  char * EQ_OPt;
  char * NE_OPt;
  
}EqualitiyExpressionNode;


typedef struct relational_expression_node
{

  struct ShiftExpressionNode * shift_expression;
  struct RelationalExpressionNode * relational_expression;
  char * LESSTHANt;
  char * GREATERTHANt;
  char * LE_OPt;
  char * GE_OPt;
  
}RelationalExpressionNode;

typedef struct shift_expression_node
{

  struct AdditiveExpressionNode * additive_expression;
  struct ShiftExpressionNode * shift_expression;
  char * LEFT_OPt;
  char * RIGHT_OPt;
  
} ShiftExpressionNode;


typedef struct additive_expression_node
{

  struct AdditiveExpressionNode * additive_expression;
  struct MultiplicativeExpressionNode * multiplicative_expression;
  char * PLUSt;
  char * MINUSt;
  
} AdditiveExpressionNode;


typedef struct multiplicative_expression_node
{

  struct CastExpressionNode * cast_expression;
  struct MultiplicativeExpressionNode * multiplicative_expression;
  char * MULTIPLYt;
  char * DIVIDEt;
  char * ANDt;
  
} MultiplicativeExpressionNode;


typedef struct cast_expression_node
{

  struct CastExpressionNode * cast_expression;
  struct UnaryExpressionNode * unary_expression;
  struct TypeNameNode * type_name;
  char * LEFTPARENt;
  char * RIGHTPARENt;
  
} CastExpressionNode;

typedef struct unary_expression_node
{

  struct CastExpressionNode * cast_expression;
  struct UnaryExpressionNode * unary_expression;
  struct UnaryOperatorNode * unary_operator;
  struct TypeNameNode * type_name;
  char * DEC_OPt;
  char * INC_OPt;
  char * SIZEOFt;
  char * LEFTPARENt;
  char * RIGHTPARENt;
  
} UnaryExpressionNode;

typedef struct unary_operator_node
{

  struct TypeNameNode * type_name;
  char * ANDt;
  char * POINTERt;
  char * PLUSt;
  char * MINUSt;
  char * TILDAt;
  char * EXCLAMATIONPOINTt;
  char * LEFTPARENt;
  char * RIGHTPARENt;
  
} UnaryOperatorNode;



typedef struct postfix_expression
{
  struct PrimaryExpressionNode * primary_expression;
  struct PostfixExpressionNode * postfix_expression;
  struct ArgumentExpressionListNode * argument_expression_list;
  struct IdentifierNode * identifier;
  char * LEFTPARENt;
  char * RIGHTPARENt;
  char * LEFTSQUAREPARENt;
  char * RIGHTSQUAREPARENt;
  char * PERIODt;
  char * PTR_OPt;
  char * DEC_OPt;
  char * INC_OPt;
  

}PostfixExpressionNode;

typedef struct primary_expression
{
  struct ExpressionNode * expression;
  struct IdentifierNode * identifier;
  struct ConstantNode * constant;
  struct StringNode * string;
  char * LEFTPARENt;
  char * RIGHTPARENt;
  

}PrimaryExpressionNode;

typedef struct argument_expression_list_node
{

  struct AssignmentExpressionNode * assignment_expression;
  struct ArgumentExpressionListNode * argument_expression_list;
  char * COMMAt;

}ArgumentExpressionListNode;

typedef struct constant_node
{

  int * intConstantt;
  char * charConstantt;
  float * floatConstantt;

}ConstantNode;

typedef struct string_node
{
  char * charConstantt;
  
}StringNode;


typedef struct identifier_node
{
  char * charConstantt;
  
}IdentifierNode;

//
extern TranslationUnitNode * abstract_syntax_tree;

//Pointers used in our compiler

extern StorageClassSpecifierNode * storage_class_specifier_node;

extern DeclarationSpecifiersNode * declaration_specifiers_node;

extern DirectDeclaratorNode * direct_declarator_node;

extern InitDeclaratorNode * init_declarator_node;

extern DeclaratorNode * declarator_node;

extern InitDeclaratorListNode * init_declarator_list_node;

extern DeclarationNode * declaration_node;

extern ExternalDeclarationNode * external_declaration_node;

extern TranslationUnitNode * translation_unit_node;


#endif






