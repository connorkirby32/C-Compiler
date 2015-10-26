#include "driver.h"
#include "symTable.h"
#include "symTable.c"
//#include "ast.h"
//#include "ast.c"


//Global variables.....
//Global variables everywhere....


//File pointers 
FILE *lexFile = NULL;
FILE *parseFile = NULL;
FILE *symbolTableFile = NULL;

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
flagContainer flags;
flagContainer reset = {0};

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
  while ((options = getopt (argc, argv, "-d[lsp]")) != -1){ 
    switch (options)
      {
      //Lex Debug
      case 'l':
        lexDebug = 1;
        lexFile = fopen("lexOutput.txt", "w");
        break;
      //Symbol Table Debug
      case 's':
        symbolTableDebug = 1;
        symbolTableFile = fopen("symbolTableOutput.txt", "w");
        break;
      //Parser Debug
      case 'p':
        parseDebug = 1;
        parseFile = fopen("parserOutput.txt", "w");
        break;

      }
      
   }       
	//Set lex to read from the test_file
	yyin = test_file;
	
	//Parse test_file
  yyparse(); 
  
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


 
 

