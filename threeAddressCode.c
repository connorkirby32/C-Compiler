#include "driver.h"
#include "nodes.h"
#include <stdlib.h>

void GenerateThreeAddressCode(TranslationUnitNode * ast){

  
  if(ast->external_declaration != NULL && ast->translation_unit != NULL ){
  
      GenerateThreeAddressCode(ast->translation_unit);
      ThreeAddrExternalDeclaration(ast->external_declaration);
      
  } 
  else if(ast->external_declaration != NULL){
  
      ThreeAddrExternalDeclaration(ast->external_declaration);
  
  } 



}


void ThreeAddrExternalDeclaration(ExternalDeclarationNode * ast){
    
  
  if(ast->function_definition != NULL){
  
  ThreeAddrFunctionDefinition(ast->function_definition);

  } 
  
  else if(ast->declaration != NULL){
    
    ThreeAddrDeclaration(ast->declaration);
    
  } 


}


ThreeAddrDeclaration(DeclarationNode * ast){

  
  
  if(ast->declaration_specifiers != NULL && ast->init_declarator_list != NULL){
      ThreeAddrDeclarationSpecifiers(ast->declaration_specifiers);
      ThreeAddrInitDeclaratorList(ast->init_declarator_list);
      
  }
    

}

ThreeAddrDeclarationSpecifiers(DeclarationSpecifiersNode * ast){




    if(ast->type_specifier != NULL){
     
      TypeSpecifierNode * x;
      x = ast->type_specifier;
      
    }
  

}

ThreeAddrInitDeclaratorList(InitDeclaratorListNode * ast){


    
    if(ast-> init_declarator != NULL && ast-> init_declarator_list != NULL){
    
      ThreeAddrInitDeclaratorList(ast-> init_declarator_list);
      ThreeAddrInitDeclarator(ast->init_declarator);
    }
    
    else if(ast-> init_declarator != NULL){
    
      ThreeAddrInitDeclarator(ast->init_declarator);
    }
    
    

}

ThreeAddrInitDeclarator(InitDeclaratorNode * ast){

    
    if(ast-> declarator != NULL && ast-> initializer!= NULL ){
      ThreeAddrDeclarator(ast->declarator);
      ThreeAddrInitializer(ast-> initializer);


      //Three Address Code


      //Get Identifier Name
      DeclaratorNode *  declarator_temp;
      declarator_temp = ast->declarator;

      //Get the value or variable declarator is being initialized too
      InitializerNode  * initializer_temp = ast->initializer;

      printf("%s = _R%d\n", declarator_temp->identifier->name, register_count-1);
    }
    else if(ast-> declarator != NULL){
    
      ThreeAddrDeclarator(ast->declarator);
      
    }
    

} 

ThreeAddrDeclarator(DeclaratorNode * ast){


  if(ast->direct_declarator != NULL){
  
   ThreeAddrDirectDeclarator(ast->direct_declarator);

  }
    



}

void ThreeAddrDirectDeclarator(DirectDeclaratorNode * ast){


    if(ast->identifier != NULL){
    
    }
    else if(ast->constant_expression != NULL && ast->direct_declarator != NULL){
    
        ThreeAddrDirectDeclarator(ast->direct_declarator);

        ThreeAddrConstantExpression(ast->constant_expression);
     
        
        
        
    
    }


}

void ThreeAddrFunctionDefinition(FunctionDefinitionNode * ast){


  if(ast-> declaration_specifiers != NULL && ast->declarator != NULL && ast-> compound_statement != NULL ){
    
    ThreeAddrDeclarationSpecifiers(ast-> declaration_specifiers);
    ThreeAddrDeclarator(ast->declarator );
    ThreeAddrCompoundStatement(ast->compound_statement);

  }




}
void ThreeAddrCompoundStatement(CompoundStatementNode * ast){



  
   if(ast-> declaration_list != NULL && ast->statement_list != NULL){
        ThreeAddrDeclarationList(ast->declaration_list );
        ThreeAddrStatementList(ast->statement_list);
  
    }
   
   else if(ast-> declaration_list != NULL){
    
    ThreeAddrDeclarationList(ast->declaration_list );
  
   }
   else if(ast-> statement_list != NULL){
    
    ThreeAddrStatementList(ast->statement_list );
  
   }


}

void ThreeAddrStatementList(StatementListNode * ast){
  

  if(ast->statement != NULL){
  
    ThreeAddrStatement(ast->statement);
  
  }



}

void ThreeAddrStatement(StatementNode * ast){


  if(ast-> selection_statement != NULL){
  
    ThreeAddrSelectionStatement(ast->selection_statement);
    
  
  }
  
  else if(ast-> expression_statement != NULL){
  
    ThreeAddrExpressionStatement(ast->expression_statement);
    
  
  }
  else if(ast->compound_statement != NULL){
  

    ThreeAddrCompoundStatement(ast->compound_statement);
  
  }
  else if(ast->iteration_statement != NULL){
  
    ThreeAddrIterationStatement(ast->iteration_statement);
  
  }



}

void ThreeAddrExpressionStatement(ExpressionStatementNode * ast){


  if(ast-> expression != NULL){
  
    ThreeAddrExpression(ast-> expression);
    
  
  }
  
 


}


void ThreeAddrDeclarationList(DeclarationListNode * ast){



  if(ast-> declaration != NULL && ast->declaration_list != NULL){
  
    ThreeAddrDeclarationList(ast->declaration_list);
    ThreeAddrDeclaration(ast->declaration);
  
  
  }
  else if(ast-> declaration != NULL){
  
    ThreeAddrDeclaration(ast->declaration);
  
  
  }
  
  
  
   

}

void ThreeAddrConstantExpression(ConstantExpressionNode * ast){


  if(ast->conditional_expression != NULL){
  
    ThreeAddrConditionalExpression(ast->conditional_expression);
  
  }








}

void ThreeAddrSelectionStatement(SelectionStatementNode *ast){
  
  

  //selection_statement <- IF '(' expression ')' statement
  if(ast->expression != NULL && ast->statement != NULL){

    ThreeAddrExpression(ast->expression);

    ThreeAddrStatement(ast->statement);
   
  }
  
 

}

void ThreeAddrExpression(ExpressionNode * ast){


  if(ast-> assignment_expression != NULL){
  
    ThreeAddrAssignmentExpression(ast-> assignment_expression);
  
  }
  
  


}

void ThreeAddrAssignmentExpression(AssignmentExpressionNode * ast){


  if(ast-> unary_expression != NULL  && ast->assignment_expression != NULL){
  
    ThreeAddrUnaryExpressionNode(ast-> unary_expression);

    ThreeAddrAssignmentExpression(ast->assignment_expression);
  
  }
  else if(ast-> conditional_expression  != NULL){
  
    ThreeAddrConditionalExpression(ast->conditional_expression);
  
  }
  
  
  
  


}

void ThreeAddrConditionalExpression(ConditionalExpressionNode * ast){


  if(ast-> logical_or_expression  != NULL){
  
    ThreeAddrLogicalOrExpression(ast->logical_or_expression);
   
  }
    


}

void ThreeAddrLogicalOrExpression(LogicalOrExpressionNode * ast){

  if(ast-> logical_and_expression  != NULL){
  
    ThreeAddrLogicalAndExpression(ast->logical_and_expression);
   
  }
    

}

void ThreeAddrLogicalAndExpression(LogicalAndExpressionNode * ast){


  if(ast-> inclusive_or_expression  != NULL){
  
    ThreeAddrInclusiveOrExpression(ast->inclusive_or_expression);
   
  }
    

}

void ThreeAddrInclusiveOrExpression(InclusiveOrExpressionNode * ast){

  if(ast-> exclusive_or_expression  != NULL){
  
    ThreeAddrExclusiveOrExpression(ast->exclusive_or_expression);
   
  }
    

}

void ThreeAddrExclusiveOrExpression(ExclusiveOrExpressionNode * ast){


  if(ast-> and_expression  != NULL){
  
    ThreeAddrAndExpression(ast->and_expression);
   
  }
    

}

void ThreeAddrInitializer( InitializerNode * ast){
   

  
  if(ast->initializer_list != NULL){
    
    ThreeAddrInitializerList(ast-> initializer_list);
  
  }
  
  else if(ast-> assignment_expression != NULL){
    
    ThreeAddrAssignmentExpression(ast-> assignment_expression);
  
  }
    

}


void ThreeAddrInitializerList(InitializerListNode * ast){



  //initializer_list <- initializer_list ',' initializer
  if(ast->initializer_list != NULL && ast->initializer != NULL){
    
    ThreeAddrInitializerList(ast-> initializer_list);
    ThreeAddrInitializer(ast-> initializer);
  
  }
  else if(ast->initializer != NULL){

    ThreeAddrInitializer(ast-> initializer);
  
  }
 

}



void ThreeAddrAndExpression(AndExpressionNode * ast){

  if(ast->equality_expression != NULL){
    
    ThreeAddrEqualityExpression(ast-> equality_expression);
  
  }
    

  
}

void ThreeAddrEqualityExpression(EqualityExpressionNode *ast){

  if(ast->relational_expression != NULL){
    
    ThreeAddrRelationalExpression(ast-> relational_expression);
  
  }
    

}

void ThreeAddrRelationalExpression(RelationalExpressionNode *ast){

  
  if(ast->shift_expression != NULL && ast->relational_expression != NULL){
    ThreeAddrRelationalExpression(ast-> relational_expression);

    ThreeAddrShiftExpression(ast-> shift_expression);
  }

  else if(ast->shift_expression != NULL){
    ThreeAddrShiftExpression(ast-> shift_expression);
  }
    

}

void ThreeAddrShiftExpression(ShiftExpressionNode * ast){

  if(ast->additive_expression != NULL){
    
    ThreeAddrAdditiveExpressionNode(ast-> additive_expression);
  
  }
    

}

void ThreeAddrAdditiveExpressionNode(AdditiveExpressionNode * ast){

  
   if(ast->multiplicative_expression != NULL && ast->additive_expression != NULL){
    

    ThreeAddrAdditiveExpressionNode(ast->additive_expression);
    ThreeAddrMultiplicativeExpressionNode(ast-> multiplicative_expression);

    AdditiveExpressionNode * additive_temp = ast->additive_expression;
    MultiplicativeExpressionNode * multiplicative_temp = ast->multiplicative_expression;

    if(additive_temp ->identifier != NULL){

            printf("_R%d = %s + ",  register_count++, additive_temp ->identifier->name);

            if(multiplicative_temp->constant != NULL){

                 printf("_R%d\n",  register_count-2);

            }
            else{


                 printf("%s\n", multiplicative_temp->identifier->name);
            }


    }else if(additive_temp  ->constant != NULL){

            printf("_R%d = _R%d + ", register_count, register_count -1);
            
            if(multiplicative_temp->constant != NULL){

               printf("_R%d \n", register_count-2);
               register_count++;

            }

            else if(multiplicative_temp->identifier != NULL){

               printf("%s\n", multiplicative_temp->identifier->name);
               register_count++;

            }

    }

  
  }
  
  else if(ast->multiplicative_expression != NULL){
    
    ThreeAddrMultiplicativeExpressionNode(ast-> multiplicative_expression);
  
  }
    

}

void ThreeAddrMultiplicativeExpressionNode(MultiplicativeExpressionNode * ast){

  if(ast->cast_expression != NULL){
    
    ThreeAddrCastExpressionNode(ast-> cast_expression);
  
  }
    

}

void ThreeAddrCastExpressionNode(CastExpressionNode * ast){


  if(ast->unary_expression!= NULL){
    
    ThreeAddrUnaryExpressionNode(ast-> unary_expression);
  
  }
    


}
void ThreeAddrUnaryExpressionNode(UnaryExpressionNode * ast){


  if(ast->postfix_expression  != NULL){
    
    ThreeAddrPostfixExpressionNode(ast-> postfix_expression );
  
  }
    

}

void ThreeAddrPostfixExpressionNode(PostfixExpressionNode * ast){


  //postfix_expression <- postfix_expression '[' expression ']' 
  if(ast->postfix_expression != NULL && ast->expression != NULL){
    
    ThreeAddrPostfixExpressionNode(ast->postfix_expression );

    ThreeAddrExpression(ast->expression);


    printf("%s = _R%d\n", declarator_temp->identifier->name, register_count-1);

  }
  else if(ast->primary_expression != NULL){
    
    ThreeAddrPrimaryExpressionNode(ast-> primary_expression);
  
  }

}


void ThreeAddrPrimaryExpressionNode(PrimaryExpressionNode * ast){

  
  if(ast->constant != NULL){
  
    ThreeAddrConstant(ast->constant);
    
  }else if(ast->identifier != NULL){
    

  
  }




}

void ThreeAddrConstant(ConstantNode * ast){


  if(ast->int_flag){
      printf("_R%d = %d \n", register_count++, ast->int_constant);
  }
  else if( ast->char_flag) {

  }
  else if( ast->float_flag) {

  }
}


void ThreeAddrIterationStatement(IterationStatementNode * ast){



  
  //While Loop
  if(ast->expression != NULL && ast->statement != NULL){

  }


}



