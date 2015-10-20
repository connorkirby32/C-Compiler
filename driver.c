#include "driver.h"
#include "symTable.c"


//Shared Variables
FILE *yyin;
FILE *lexFile;
FILE *parseFile;
FILE *symbolTableFile;
int parseDebug = 0;
int lexDebug = 0;
int symbolTableDebug = 0;

int rowNum = 1;
int tabSize = 4;
int column = 1;


bool lookUpMode = 0; 

node * symbolTable;
treeNode* currentIdentifier;



int main(int argc, char **argv)
{

  //Declerations
  int options = 0;
  FILE * testFile;
  
  //Initiate SymTable
  symbolTable = createTable(symbolTable);
  symbolTable = pushLevel(symbolTable,0);

  //Parse the command line for debugging options
  while ((options = getopt (argc, argv, "-d[lsp]")) != -1){ 
    switch (options)
      {
      case 'l':
        lexDebug = 1;
        lexFile = fopen("lexOutput.txt", "w");
        break;
      case 's':
        symbolTableDebug = 1;
        symbolTableFile = fopen("symbolTableOutput.txt", "w");
        break;
      case 'p':
        parseDebug = 1;
        parseFile = fopen("parserOutput.txt", "w");
        break;

      }
      
     } 
      
    testFile = fopen("testFile.c", "r");
	//Open our test C file(s)
	if (!testFile) {
		printf("Error opening Test File!\n");
		return -1;
	}
	

  
    
	// set lex to read from it instead of defaulting to STDIN:
	yyin = testFile;
	// parse through the input until there is no more:
    yyparse(); 
	
    fclose(testFile); 
    
    if(parseDebug)
        fclose(parseFile);
        
    if(lexDebug)
        fclose(lexFile);
        
    if(symbolTableDebug)
    {
        printTable(symbolTable);
        fclose(symbolTableFile);
        
    }
        	  
	
}



 
 

