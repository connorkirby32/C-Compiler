%{

#include "y.tab.h"
int rowNum = 1;
int tabSize = 4;

int column;
%}



character[a-z]
digit (-)?[0-9]


whiteSpace [ ]+
tab[\t]+
carriage[\n]
null[\0]

%%
{carriage}              {rowNum++; column = 0;}
{tab}                   {column += tabSize;}
{whiteSpace}            {column++;}




"auto"                  {return AUTO;}
"break"                 {return BREAK;}
"case"                  {return CASE;}
"char"                  {return CHAR;}
"const"                 {return CONST;}
"continue"              {return CONTINUE;}   
"default"               {return DEFAULT;}
"do"                    {return DO;}
"double"                {return DOUBLE;}
"else"                  {return ELSE;}
"enum"                  {return ENUM;}
"extern"                {return EXTERN;}
"float"                 {return FLOAT;}
"for"                   {return FOR;}
"goto"                  {return GOTO;}
"if"                    {return IF;}
"int"                   {return INT;}
"long"                  {return LONG;}
"register"              {return REGISTER;}
"return"                {return RETURN;}
"short"                 {return SHORT;}
"signed"                {return SIGNED;}
"sizeof"                {return SIZEOF;}
"static"                {return STATIC;}
"struct"                {return STRUCT;}
"switch"                {return SWITCH;}
"typedef"               {return TYPEDEF;}
"union"                 {return UNION;}
"unsigned"              {return UNSIGNED;}
"void"                  {return VOID;}
"volatile"              {return VOLATILE;}
"while"                 {return WHILE;}



{character}+            {return IDENTIFIER;}

{digit}+                {column += yyleng; yylval.iVal = atoi(yytext); }
{digit}+"."{digit}*     {column += yyleng; yylval.fVal = atof(yytext); }


"("			            {return('('); }
")"			            {return(')'); }
";"                     {return ';';}
"{"			            {return('{'); }
"}"			            {return('}'); }

 .                      {    
                         printf("Diagnostic Report:\n");
                         printf( "%s is not a valid token. \n", yytext);
                         printf("Error at Row #:%i\n",rowNum);
                         printf("Error at Column #:%i\n",column); 
                        } 


%%

