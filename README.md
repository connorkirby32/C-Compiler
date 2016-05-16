#Elementary C Compiler
##Connor Kirby, Ben Wendell and Daniel Sanchez
CS 460  
Fall 2015  
Fred Harris  


The following is a small elementary C-Compiler for a subset of the C Programming Language. 


#Structure

Lexical Analysis - Parser Using Bison and Yacc

Syntax Analysis - Parser Using Bison and Yacc

Semantic Analysis - Struct data strucutre that builds an AST. Latex code to visual the tree is also generated. 

Three Address Code - Functions used by the Semantic Analysis struct to generate 3AC code.

Optimiazation - Future Work

Code Generation - Python script that translates the three address code generated in the previous step to our target code MIPS. 


#Features

Please see test_cases inside bin to see the full extent of code that will be compiled using our compiler. 

- Variable Decleration both local and global scope 
- Basic Assignment
- Conditional Branching
- Iterative Loops
- Large arithmetic expressions


#Future Work

We would like to better design our three address code and activation frame to allow function calls and recursive calls. 








