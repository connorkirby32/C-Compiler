#include "driver.h"
#include "ast.h"
#include <stdlib.h>

void ReportAST(TranslationUnitNode * ast){


  fprintf(astFile,"[.{Translation Node} ");
  
  if(ast->external_declaration != NULL && ast->translation_unit != NULL ){
  
      ReportAST(ast->translation_unit);
      PrintExternalDeclaration(ast->external_declaration);
      
  } 
  else if(ast->external_declaration != NULL){
  
      PrintExternalDeclaration(ast->external_declaration);
  
  } 
  fprintf(astFile," ] ");


}



void PrintExternalDeclaration(ExternalDeclarationNode * ast){
    

  fprintf(astFile," [.{External Declaration} ");
  
  if(ast->function_definition != NULL){
  
    PrintFunctionDefinition(ast->function_definition);
    ast->function_definition != NULL;
  } 
  
  else if(ast->declaration != NULL){
    
    PrintDeclaration(ast->declaration);
    
  } 

  fprintf(astFile," ] ");

}


PrintDeclaration(DeclarationNode * ast){

  fprintf(astFile,"[ .{Declaration} ");
  
  
  if(ast->declaration_specifiers != NULL && ast->init_declarator_list != NULL){
      PrintDeclarationSpecifiers(ast->declaration_specifiers);
      PrintInitDeclaratorList(ast->init_declarator_list);
      
  }
    
  fprintf(astFile," ] ");

}

PrintDeclarationSpecifiers(DeclarationSpecifiersNode * ast){

    fprintf(astFile," [.{Declaration Specifiers} ");

    //fprintf(astFile,"Declaration Specifiers %d %d\n", level++, ast_id++);
    if(ast->type_specifier != NULL){
     
    }
    
    fprintf(astFile," ] ");

}

PrintInitDeclaratorList(InitDeclaratorListNode * ast){

    fprintf(astFile," [.{Init Declarator List} ");
    if(ast-> init_declarator != NULL){
    
      PrintInitDeclarator(ast->init_declarator);
    }
    

    fprintf(astFile," ] ");
}

PrintInitDeclarator(InitDeclaratorNode * ast){

    fprintf(astFile," [.{Init Declarator} ");
    
    if(ast-> declarator != NULL && ast-> initializer!= NULL ){
    PrintDeclarator(ast->declarator);
    fprintf(astFile," = ");
    PrintInitializer(ast-> initializer);
    }
    else if(ast-> declarator != NULL){
    
      PrintDeclarator(ast->declarator);
      
    }
    
   fprintf(astFile," ] ");
} 

PrintDeclarator(DeclaratorNode * ast){

  fprintf(astFile," [.Declarator ");
  if(ast->direct_declarator != NULL){
  
    PrintDirectDeclarator(ast->direct_declarator);

  }
    
  fprintf(astFile," ] ");


}

void PrintDirectDeclarator(DirectDeclaratorNode * ast){

  fprintf(astFile," [.{Direct Declarator} ");

    if(ast->identifier != NULL){
  
        fprintf(astFile," [.{%s} ] ", ast->identifier->name);
    
    }
    else if(ast->constant_expression != NULL && ast->direct_declarator != NULL){
    
        PrintDirectDeclarator(ast->direct_declarator);
        PrintConstantExpression(ast->constant_expression);
        
        
        
        
        
    
    }

  fprintf(astFile," ] ");
}

void PrintFunctionDefinition(FunctionDefinitionNode * ast){

  fprintf(astFile," [.{Function Definition} ");
  if(ast-> declaration_specifiers != NULL && ast->declarator != NULL && ast-> compound_statement != NULL ){
    
    PrintDeclarationSpecifiers(ast-> declaration_specifiers);
    PrintDeclarator(ast->declarator );
    PrintCompoundStatement(ast->compound_statement);

  }

   fprintf(astFile," ] ");


}
void PrintCompoundStatement(CompoundStatementNode * ast){


  fprintf(astFile," [.{Compound Statement} {Open Bracket} ");
  
   if(ast-> declaration_list != NULL && ast->statement_list != NULL){
        PrintDeclarationList(ast->declaration_list );
        PrintStatementList(ast->statement_list);
  
    }
   
   else if(ast-> declaration_list != NULL){
    
    PrintDeclarationList(ast->declaration_list );
  
   }
   else if(ast-> statement_list != NULL){
    
    PrintStatementList(ast->statement_list );
  
   }
  fprintf(astFile," {Closed Bracket} ] ");

}

void PrintStatementList(StatementListNode * ast){
  
  fprintf(astFile," [.{Statement List} ");
  if(ast->statement != NULL){
  
    PrintStatement(ast->statement);
  
  }
  fprintf(astFile," ] ");


}

void PrintStatement(StatementNode * ast){

  fprintf(astFile," [.{Statement} ");
  if(ast-> selection_statement != NULL){
  
    PrintSelectionStatement(ast->selection_statement);
    
  
  }
  else if(ast->compound_statement != NULL){
  

    PrintCompoundStatement(ast->compound_statement);
  
  }
  fprintf(astFile," ] ");


}

void PrintDeclarationList(DeclarationListNode * ast){


  fprintf(astFile," [.{Declaration List} ");
  if(ast-> declaration != NULL && ast->declaration_list != NULL){
  
    PrintDeclarationList(ast->declaration_list);
    PrintDeclaration(ast->declaration);
  
  
  }
  else if(ast-> declaration != NULL){
  
    PrintDeclaration(ast->declaration);
  
  
  }
  
  
  
   fprintf(astFile," ] ");

}

void PrintConstantExpression(ConstantExpressionNode * ast){

  fprintf(astFile," [.{Constant Expression} ");
  if(ast->conditional_expression != NULL){
  
    PrintConditionalExpression(ast->conditional_expression);
  
  }



  fprintf(astFile," ] ");





}

void PrintSelectionStatement(SelectionStatementNode *ast){
  
  
  fprintf(astFile," [.{Selection Statement} ");
  //selection_statement <- IF '(' expression ')' statement
  if(ast->expression != NULL && ast->statement != NULL){
    fprintf(astFile," [.{if} ] [ ( ] ");
    PrintExpression(ast->expression);
    fprintf(astFile," [ ) ] ");
    PrintStatement(ast->statement);
   
  }
  
   fprintf(astFile," ] ");

}

void PrintExpression(ExpressionNode * ast){

  fprintf(astFile," [.{Expression} ");
  if(ast-> assignment_expression != NULL){
  
    PrintAssignmentExpression(ast-> assignment_expression);
  
  }
  
  
  fprintf(astFile," ] ");

}

void PrintAssignmentExpression(AssignmentExpressionNode * ast){

  fprintf(astFile," [.{Assignment Expression} ");
  if(ast-> conditional_expression  != NULL){
  
    PrintConditionalExpression(ast->conditional_expression);
  
  }
  
  
  
  
  fprintf(astFile," ] ");

}

void PrintConditionalExpression(ConditionalExpressionNode * ast){

  fprintf(astFile," [.{Conditional Expression} ");
  if(ast-> logical_or_expression  != NULL){
  
    PrintLogicalOrExpression(ast->logical_or_expression);
   
  }
    
  fprintf(astFile," ] ");

}

void PrintLogicalOrExpression(LogicalOrExpressionNode * ast){

  fprintf(astFile," [.{Logical Or Expression} ");
  if(ast-> logical_and_expression  != NULL){
  
    PrintLogicalAndExpression(ast->logical_and_expression);
   
  }
    
  fprintf(astFile," ] ");
}

void PrintLogicalAndExpression(LogicalAndExpressionNode * ast){

  fprintf(astFile," [.{ Logical And Expression} ");
  if(ast-> inclusive_or_expression  != NULL){
  
    PrintInclusiveOrExpression(ast->inclusive_or_expression);
   
  }
    
  fprintf(astFile," ] ");
}

void PrintInclusiveOrExpression(InclusiveOrExpressionNode * ast){

  fprintf(astFile," [.{ Inclusive Or Expression} ");
  if(ast-> exclusive_or_expression  != NULL){
  
    PrintExclusiveOrExpression(ast->exclusive_or_expression);
   
  }
    
  fprintf(astFile," ] ");
}

void PrintExclusiveOrExpression(ExclusiveOrExpressionNode * ast){

  fprintf(astFile," [.{ Exclusive Or Expression} ");
  if(ast-> exclusive_or_expression  != NULL){
  
    //PrintLogicalAndExpression(ast->exclusive_or_expression);
   
  }
    
  fprintf(astFile," ] ");
}

void PrintInitializer( InitializerNode * ast){
   
  fprintf(astFile," [.{ Initializer} ");
  if(ast-> assignment_expression != NULL){
    
    PrintAssignmentExpression(ast-> assignment_expression);
  
  }
    
  fprintf(astFile," ] ");



}




/*

storage_class_specifier <- INT 

declaration_specifiers <- type_specifier 

Insert Mode 

identifier ->IDENTIFIER (x)
direct_declarator <- identifier 

declarator <- direct_declarator 

CONSTANT <- INTEGER_CONSTANT 

primary_expression <- constant 

postfix_expression <- primary_expression 

unary_expression <- postfix_expression 

cast_expression <- unary_expression 

multiplicative_expression <- cast_expression 

additive_expression <- multiplicative_expression 

shift_expression <- additive_expression 

relational_expression <- shift_expression 

equality_expression <- relational_expression 

and_expression <- equality_expression 

exclusive_or_expression <- and_expression 

inclusive_or_expression <- exclusive_or_expression  

logical_and_expression <- inclusive_or_expression 

logical_or_expression <- logical_and_expression 

conditional_expression <- logical_or_expression 
 
assignment_expression <- conditional_expression 

initializer <- assignment_expression 

init_declarator <- declarator '=' initializer 

init_declarator_list <- init_declarator 

declaration <- declaration_specifiers init_declarator_list 

external_declaration <- declarationn 

translation_unit <- external_declaration 

*/
