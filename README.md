# C-Compiler
C Compiler

Use make to build. 
-d[lsp] as command line argument to debug


Things to do: 


1. YACC File: 

We need to start going through and adding appropriate C code to each token. I have a basic example working for an int identifier (int i = 0;) where it is scanned and its ID name
'i' is typecast to an integer value and added to the symbol table. A node pointer, current branch, is returned after inserting so that we can add its value 0 when the following  INTEGER_CONSTANT is scanned and processed in YACC. 

It should be simple for trivial cases like characters, floats, etc but we should also start thinking about what to do and store for whenever a function ID is declared or encountred. 


2. LEX File:

We should store the source code text in some sort of buffer so that we can print it out along with column and row number whenever there is an error. Refer to his scanner write- up, he has an example of what I mean there. I already have declared and accounted for row and colum number so it is only a matter of storing the actual source code.
 
 
 3. Symbol Table: 
    
We just need have a delete tree function for the BST. Also, we will need to add a lot of deatil to how and what is printed in the printIdentifiers function. Right now it only prints values if the identifier is of type int. 
