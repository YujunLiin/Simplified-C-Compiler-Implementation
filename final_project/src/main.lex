%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header

int lineno=1;
int depth=0;
symbol_table *root_table=new symbol_table();
symbol_table *current=root_table;
%}

BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/
LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]
DIGIT [0-9]
INTEGER [0-9]+
CHAR \'.?\'
STRING \".+\"
IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*

%%

{BLOCKCOMMENT}  /* do nothing */
{LINECOMMENT}  /* do nothing */
{WHILTESPACE} /* do nothing */

{EOL} lineno++;



"int"                 return T_INT;
"bool"                return T_BOOL;
"char"                return T_CHAR;
"void"                return T_VOID;
"string"              return T_STRING;
"if"                  return IF;
"else"                return ELSE;
"while"               return WHILE;
"for"                 return FOR;
"main"                return MAIN;
"break"               return BREAK;
"continue"            return CONTINUE;
"scanf" 			  return SCANF;
"printf"			  return PRINTF;
"return"              return RETURN;
"const"               return CONST;

"="                   return ASSIGN;
"<"                   return LT;
">"                   return GT;
">="		    	  return GE;
"<="			      return LE;
"=="                  return EQ;
"!="                  return NZ;

"+"                   return PLUS;
"-"                   return MINUS;
"*"                   return TIMES;
"/"                   return OVER;
"%"                   return MOD;
"++"                  return INC;
"--"                  return DEC;

"<<"                  return SHL;
">>"                  return SAR;
"&&"                  return AND;
"||"                  return OR;
"&"                   return B_AND;  //按位与，实际是取地址&
"!"                   return OPPOSITE;

"{"                   {current=current->addChild();
                       return LBRACE;}
"}"                   {if(current!=root_table)
                       current=current->KommZurMama();
                       return RBRACE;}
"("                   return LPAREN;
")"                   return RPAREN;
"["                   return LSQUARE;
"]"                   return RSQUARE;
";"                   return SEMI;
","                   return COMMA;


{INTEGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = atoi(yytext);
    node->check_type=IntegerT;
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->ch_val = yytext[1];
    node->check_type=CharT;
    yylval = node;
    return CHAR;
}

{STRING} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type=TYPE_STRING;
    node->str_val = yytext;
    node->check_type=StringT;
    yylval = node;
    return STRING;
}

{IDENTIFIER} {
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    node->table=current->find_scope(node->var_name);
    if(node->table!=nullptr)
    {
        node->symbol_index=node->table->lookup(node->var_name);
    }
    else
    {
        node->symbol_index=current->insert(node->var_name);
        if(node->symbol_index!=-1)
        node->table=current;
    }
    node->check_type=Notype;
    yylval = node;
    return IDENTIFIER;
}


. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%