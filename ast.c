#include "driver.h"
#include "ast.h"
#include <stdlib.h>

void ReportAST(TranslationUnitNode * ast){
  
  if(ast->external_declaration != NULL){
  
      printf("External Declaration"); 
      PrintExternalDeclaration(ast->external_declaration);
  
  } 
 

}

void PrintExternalDeclaration(ExternalDeclarationNode * ast){


  if(ast->function_definition != NULL){
  
  
  } 
  
  if(ast->declaration != NULL){
  
    PrintDeclaration(ast->declaration);
    
  } 
   printf("Int\n");


}


PrintDeclaration(DeclarationNode * ast){

  if(ast->declaration_specifiers != NULL && ast->init_declarator_list != NULL){
      PrintDeclarationSpecifiers(ast->declaration_specifiers);
      PrintInitDeclaratorList(ast->init_declarator_list);
       printf("DeclarationNode\n");
  }
    


}

PrintDeclarationSpecifiers(DeclarationSpecifiersNode * ast){

    if(ast->type_specifier != NULL){
     
  }
 printf("Int\n");
}

PrintInitDeclaratorList(InitDeclaratorListNode * ast){

    if(ast-> init_declarator != NULL){
    
      PrintInitDeclarator(ast->init_declarator);
      printf("InitDeclaratorListNode\n");
    }


}

PrintInitDeclarator(InitDeclaratorNode * ast){

    if(ast-> declarator != NULL){
    
      PrintDeclarator(ast->declarator);
      printf("Declarator\n");
    }

}

PrintDeclarator(DeclaratorNode * ast){


  if(ast->direct_declarator != NULL){
  
    PrintDirectDeclarator(ast -> direct_declarator);
    printf("Direct Declarator\n");
  }



}

void PrintDirectDeclarator(DirectDeclaratorNode * ast){



  printf("Identifier Goes Here\n");


}
