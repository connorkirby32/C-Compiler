#include "driver.h"
#include "symTable.h"
#include "symTable.c"
#include "ast.h"
#include "ast.c"


//Global variables.....
//Global variables everywhere....


//File pointers 
FILE *lexFile = NULL;
FILE *parseFile = NULL;
FILE *symbolTableFile = NULL;
FILE *astFile = NULL;

//Debug flags
int parseDebug = 0;
int lexDebug = 0;
int symbolTableDebug = 0;

//Debug info
int rowNum = 1;
int tabSize = 4;
int column = 0;
char * buffer;
long bufferSize;

//For symbol table and parser
bool lookUpMode = 0; 
bool scanner_error = 0;

//Sybmol Table
node * symbolTable;
treeNode* currentIdentifier;
flagContainer flags = {0};
flagContainer reset = {0};


//AST
AbstractSyntaxTreeNode * abstract_syntax_tree;
TranslationUnitNode * translation_unit_node;
int ast_id;

//AST Poiners
StorageClassSpecifierNode * storage_class_specifier_node;

DeclarationSpecifiersNode * declaration_specifiers_node;

FunctionDefinitionNode * function_definition_node;

DirectDeclaratorNode * direct_declarator_node;

InitDeclaratorNode * init_declarator_node;

DeclaratorNode * declarator_node;

InitDeclaratorListNode * init_declarator_list_node;

DeclarationNode * declaration_node;

ExternalDeclarationNode * external_declaration_node;

CompoundStatementNode * compound_statement_node;

DeclarationListNode * declaration_list_node;

ConstantExpressionNode * constant_expression_node;

ConditionalExpressionNode * conditional_expression_node;

StatementNode * statement_node;

StatementListNode * statement_list_node;

SelectionStatementNode * selection_statement_node;

IterationStatementNode * iteration_statement_node;

ExpressionNode * expression_node; 

InitializerNode * initializer_node;

AssignmentExpressionNode * assignment_expression_node;

LogicalOrExpressionNode * logical_or_expression_node;

LogicalAndExpressionNode * logical_and_expression_node;

InclusiveOrExpressionNode * inclusive_or_expression_node;

AndExpressionNode * and_expression_node;

EqualityExpressionNode * equality_expression_node;

RelationalExpressionNode * relational_expression_node;

PrimaryExpressionNode * primary_expression_node;

PostfixExpressionNode * postfix_expression_node;

UnaryExpressionNode * unary_expression_node;

CastExpressionNode * cast_expression_node;

MultiplicativeExpressionNode * multiplicative_expression_node;

ShiftExpressionNode * shift_expression_node;

ExclusiveOrExpressionNode * exclusive_or_expression_node;

AdditiveExpressionNode * additive_expression_node;



int main(int argc, char **argv)
{

  //Declerations
  int options = 0;
  FILE * test_file;
  
  //Open c file to examine
  test_file = fopen(argv[1], "r");
  if (!test_file){
    printf("Error opening Test File!\n");
    return -1;
  }
 
  //Read test_file into a buffer
  fseek( test_file , 0L , SEEK_END);
  bufferSize = ftell( test_file );
  rewind( test_file );

  //Allocate memory for buffer
  buffer = calloc( 1, bufferSize+1 );
  if( !buffer ) fclose(test_file),fputs("memory alloc fails",stderr),exit(1);

  //Copy into the buffer 
  if( 1!=fread( buffer , bufferSize, 1 , test_file) )
    fclose(test_file),free(buffer),fputs("entire read fails",stderr),exit(1);

  //Reset test_file
  fclose(test_file);
  test_file = fopen(argv[1], "r");
  
  //Initiate SymTable
  symbolTable = CreateTable(symbolTable);
  symbolTable = PushLevel(symbolTable,0);
  //Parse the command line for debugging options
  while ((options = getopt (argc, argv, "-d[lsp] -a")) != -1){ 
    switch (options)
      {
      //Lex Debug
      case 'l':
        lexDebug = true;
        lexFile = fopen("debugging/lexOutput.txt", "w");
        break;
      //Symbol Table Debug
      case 's':
        symbolTableDebug = true;
        symbolTableFile = fopen("debugging/symbolTableOutput.txt", "w");
        break;
      //Parser Debug
      case 'p':
        parseDebug = true;
        parseFile = fopen("debugging/parserOutput.txt", "w");
        break;
      //AST debug
      case 'a':
        astFile = fopen("astInfo.lex", "w");

      }
      
   }       
	//Set lex to read from the test_file
	yyin = test_file;
	
	//Parse test_file
  yyparse(); 
  
  fprintf(astFile,"\\Tree ");
  if(translation_unit_node != NULL){
    ReportAST(translation_unit_node);
  }
 
  
	//Close test_file
  fclose(test_file);
   
  //Close appropriate files based on flags  
  if(parseDebug)
      fclose(parseFile);     
  if(lexDebug)
      fclose(lexFile);     
  if(symbolTableDebug){
      //Output symbol table before closing file
      PrintTable(symbolTable);
      symbolTable = DestroyTable(symbolTable);
      fclose(symbolTableFile);     
  }
  
  free(buffer);
       	  	
}


 
 

