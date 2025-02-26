%{
	#include<stdio.h>
%}

%%

"\n"|"\t"|" " {printf("\nWhite Space");}
#.* {printf("\n%s - preprocessor directive",yytext);}
int|float|double|char|while|for|if|else|scanf|printf|main|getch {printf("\n%s-keyword",yytext);}
"++"|"--" {printf("\n%s - unary operator",yytext);}
"+"|"-"|"*"|"/"|"%" {printf("\n%s - Arithmetic Operator",yytext);}
"<"|">"|"<="|">="|"==" {printf("\n%s - Relational Operator",yytext);}
"&&"|"||"|"!" {printf("\n%s - Logical Operator",yytext);}
"="|"+="|"-="|"*=" {printf("\n%s - Assignment Operator",yytext);}
[a-zA-Z_]([a-zA-Z0-9_])* {printf("\n%s - Identifier",yytext);}
[0-9]+ {printf("\n%s - digit",yytext);}
"{" {printf("\n%s - block begins",yytext);}
"}" {printf("\n%s - block exits",yytext);}
[();,] {printf("\n%s - separator",yytext);}
\".*\" {printf("\n%s - String",yytext);}

%%
int yywrap()
{}
int main(int argc,char **argv)
{
	if(argc>1)
	{
		FILE *file;
		file=fopen(argv[1],"r");
		if(!file)
   {
    printf("Couldn't Open File %s",argv[1]);
    exit(0);
   }
   yyin=file;
 }
 yylex();
 return 0;
}




------------------------------------------------------------------------------------------------------------------------------------------




alpha [A-Za-z]
digit [0-9]
%%
[ \t\n]
if return IF;
then return THEN;
else return ELSE;
{digit}+	return NUM;
{alpha}({alpha}|{digit})* return ID;
"<=" return LE;
">=" return GE;
"==" return EQ;
"!=" return NE;
"||" return OR;
"&&" return AND;
. return yytext[0];
%%



%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
%}

%token ID NUM IF THEN LE GE EQ NE OR AND ELSE
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+' '-'
%left '*' '/'
%right UMINUS
%left '!'
%%

S	:ST {printf("Input Accepted.\n");exit(0);};
ST	:IF '(' E2 ')' THEN ST1 ';' ELSE ST1 ';'
	|IF '(' E2 ')' THEN ST1 ';'
	;
ST1 	:ST
	|E
	;
E	:ID '=' E
	|E '+' E
	|E '-' E
	|E '*' E
	|E '/' E
	|E '<' E
	|E '>' E
	|E LE E
	|E GE E
	|E EQ E
	|E NE E
	|E OR E
	|E AND E
	|ID
	|NUM
	;
E2	:E '<' E
	|E '>' E
	|E LE E
	|E GE E
	|E EQ E
	|E NE E
	|E OR E
	|E AND E
	|ID
	|NUM
	;
%%
#include "lex.yy.c"
int main(){
printf("Enter the Expression : ");
yyparse();
return 0;
}

	
	
	
	
	
----------------------------------------------------------------------------------------------------------------------------------




%%
[ \n\t] ;
for return FOR;
while return WHILE;
[a-zA-Z_]([a-zA-Z_])* return ID;
[0-9]+ return DIGIT;
"<=" return LE;
">=" return GE;
"==" return EQ;
. return yytext[0];
%%
int yywrap()
{
return 1;
}




%{
#include<stdio.h>
%}
%token FOR WHILE ID DIGIT LE GE EQ
%right '='
%left '<''>'LE GE EQ
%left '+''-'
%%

S	:ST{printf("Input Accepted");exit(0);};
ST	:FOR'('E';'E2';'E')'DEF
	|WHILE'('E')'DEF
	;
	
	DEF:'{'BODY'}'
	|ST
	|E';'
	|';'
	;

BODY	:BODY BODY
	|ST
	|E';'
	|
	;

E	:ID'='E
	|E'+'E
	|E'-'E
	|E'*'E
	|E'/'E
	|E'>'E
	|E'<'E
	|E LE E
	|E GE E
	|E EQ E
	|E'+''+'
	|E'-''-'
	|DIGIT
	|ID
	;
E2	:E'>'E
	|E'<'E
	|E LE E
	|E GE E
	|E EQ E
	;

%%

#include "lex.yy.c"
int main()
{
printf("Enter expression:\n");
yyparse();
}
yyerror()
{
printf("invalid expression");
}
	
	
	
	
	
-------------------------------------------------------------------------------------------------------------------------------




%%
[\n \t]	;
int|float|char|double	return TYPE;
return	return RETURN;
[0-9]+	return NUM;
[a-zA-Z_]([a-zA-Z0-9_])*	return ID;
.	return yytext[0];
%%





%{
#include<stdio.h>
%}
%token NUM ID TYPE RETURN
%right '='
%left '+''-'
%left '*''/'

%%
S	:FUN{printf("Input Accepted/n");exit(0);};

FUN	:TYPE ID'('PARAM')''{'BODY'}';
PARAM	:PARAM','TYPE ID
	|TYPE ID
	|TYPE ID'='NUM
	|TYPE ID'['']'
	|
	;
BODY	:BODY BODY
	|PARAM';'
	|RETURN E';'
	|
	;
E	:ID'='E
	|E'+'E
	|E'-'E
	|E'*'E
	|E'/'E
	|ID'['NUM']''='E
	|ID'['NUM']'
	|NUM
	|ID
	;
%%
#include "lex.yy.c"
main()
{
	printf("Enter Expression : ");
	yyparse();
}





