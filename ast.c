#include "driver.h"
#include <stdlib.h>

void reportAST(TranslationUnitNode * ast){
  
  if(ast->external_declaration != NULL){
  
      printf("External Declaration"); 
      printExternalDeclaration(ast->external_declaration);
  
  } 
  
  if(ast->translation_unit != NULL){
  
  
  } 



}

void printExternalDeclaration(ExternalDeclarationNode * ast){


 if(ast->function_definition != NULL){
  
  
  } 
  
  if(ast->declaration != NULL){
  
    printDeclaration(ast->declaration);
    
  } 



}

void printDeclaration(DeclarationNode * ast){







}

