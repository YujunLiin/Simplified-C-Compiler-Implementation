%{
    #include "common.h"
    #define YYstype TreeNode *  
    TreeNode* root;
    Node_Stack *top,*bottle;
    extern int lineno;
    extern int depth;
    int yylex();
    int yyerror( char const * );
%}
%token T_CHAR T_INT T_STRING T_BOOL T_VOID

%token IF MAIN ELSE FOR WHILE PRINTF SCANF BREAK CONTINUE RETURN
%token LBRACE RBRACE SEMI
%token PLUS MINUS TIMES OVER ASSIGN INC DEC MOD
%token LT EQ GT NZ GE LE
%token SHL SAR AND OR OPPSITE
%token LPAREN RPAREN COMMA LSQUARE RSQUARE
%token B_AND
%token IDENTIFIER INTEGER CHAR BOOL STRING CONST

%right ASSIGN
%left OR
%left AND 
%left EQ NZ
%left LT GT GE LE
%left SHL SAR
%left PLUS MINUS
%left TIMES OVER MOD
%right OPPOSITE B_AND
%left INC DEC

%%

program   //开始
: CompUnit
{
    root=new TreeNode($1->lineno,NODE_PROG);
    root->addChild($1);
};

CompUnit //编译单元
:FuncDef
{
    $$=new TreeNode($1->lineno,NODE_COMP);
    $$->addChild($1);
}
|Decl
{
    $$=$1;
}
|Decl CompUnit
{
    $$=$1;
    $$->addSibling($2);
}
|FuncDef CompUnit
{
    $$=$1;
    $$->addSibling($2);
};

FuncDef   //函数定义
:type IDENTIFIER LPAREN FuncFParams RPAREN Block 
{
    $$=new TreeNode($1->lineno,NODE_FUNC);
    $$->type=new Type(COMPOSE_FUNCTION);
    $$->var_name=$2->var_name;
    $$->addChild($1);
    $$->addChild($2);
    $$->addChild($4);
    $$->addChild($6);
}
|type IDENTIFIER LPAREN RPAREN Block 
{
    $$=new TreeNode($1->lineno,NODE_FUNC);
    $$->type=new Type(COMPOSE_FUNCTION);
    $$->var_name=$2->var_name;
    $$->addChild($1);
    $$->addChild($2);
    $$->addChild($5);
}
|type MAIN LPAREN RPAREN Block 
{
    $$=new TreeNode($1->lineno,NODE_FUNC);
    $$->type=new Type(COMPOSE_FUNCTION);
    $$->var_name="main";
    $$->addChild($1);
    $$->addChild($5);
};

FuncFParams   //函数形参表
:FuncFParam CommaFuncFParam
{
    $$=$1;
    $$->addSibling($2);
};

CommaFuncFParam   //{','FuncFParam}
:COMMA FuncFParam 
{
    $$=$2;
}
|{$$=NULL;};

FuncFParam   //函数形参表
:type IDENTIFIER LSQUARE RSQUARE MultiExp 
{
    $$=new TreeNode($1->lineno,NODE_STMT);
    $$->stype=STMT_DECL;
    $$->addChild($1);
    $$->addChild($2);
    $$->addChild($5);
}
|type IDENTIFIER
{
    $$=new TreeNode(lineno,NODE_STMT);
    $$->stype=STMT_DECL;
    $$->addChild($1);
    $$->addChild($2);    
};

MultiExp //{'['Exp ']'}
:LSQUARE Exp RSQUARE MultiExp
{
    $$=$2;
    $$->addSibling($4);
}
|{$$=NULL;};


Block  //语句块
:LBRACE MultiBlockItem RBRACE
{
    $$=new TreeNode(lineno,NODE_BLOCK);
    $$->addChild($2);
};

MultiBlockItem  //{BlockItem}
:BlockItem MultiBlockItem 
{
    $$=$1;
    $$->addSibling($2);
}
|{$$=NULL;};

BlockItem   //语句块项
:  Stmt {$$=$1;}
|  Decl {$$=$1;}
;

Decl     //声明
:ConstDecl
{
    $$=$1;
}
|VarDecl 
{
    $$=$1;
};

ConstDecl   //常量声明
:CONST type ConstDef CommaConstDef SEMI
{
    $$=new TreeNode(lineno,NODE_STMT);
    $$->stype=STMT_DECL;
    $$->addChild($2);
    $$->addChild($3);
    $$->addChild($4);
};

CommaConstDef    //{',' ConstDef}
:COMMA ConstDef CommaConstDef
{
    $$=$2;
    $$->addSibling($3);
}
|{$$=NULL;};

ConstDef      //常量定义
:IDENTIFIER MultiConstExp ASSIGN ConstInitVal
{
    $$=new TreeNode(lineno,NODE_EXPR);
    $$->optype=OP_assign;
    $$->addChild($1);
    $$->addChild($2);
    $$->addChild($4);
};

MultiConstExp     //{'[' ConstExp ']'}
:LSQUARE ConstExp RSQUARE MultiConstExp
{
    $$=$2;
    $$->addSibling($4);
}
|{$$=NULL;};

ConstExp //常量表达式
:AddExp {$$=$1;};

ConstInitVal   //常量初值
:ConstExp 
{
    $$=$1;
}
| LBRACE ConstInitVal CommaConstInitVal RBRACE   //需要改，暂时用不到
{
    $$=new TreeNode($2->lineno,NODE_STMT);
    $$->stype=STMT_DECL;
    $$->addChild($2);
    $$->addChild($3);
}
|LBRACE RBRACE 
{
    $$=NULL;
};

CommaConstInitVal //{',' ConstInitVal}
:COMMA ConstInitVal CommaConstInitVal 
{
    $$=$2;
    $$->addSibling($3);
}
|{$$=NULL;};

VarDecl     //变量声明
:type VarDef CommaVarDef SEMI 
{
    $$=new TreeNode(lineno,NODE_STMT);
    $$->stype=STMT_DECL;
    $$->addChild($1);
    $$->addChild($2);
    $$->addChild($3);
};

CommaVarDef    //{',' VarDef}
:COMMA VarDef CommaVarDef
{
    $$=$2;
    $$->addSibling($3);
}
|{$$=NULL;};

VarDef   //变量定义
:IDENTIFIER MultiConstExp   //remain to solve   数组
{
    if($2!=NULL)
    {
        $$=new TreeNode(lineno,NODE_TYPE);
        $$->type=new Type(COMPOSE_ARRAY);
        $$->addChild($1);
        $$->addChild($2);
    }
    else 
    {
        $$=$1;
    }
}
|IDENTIFIER MultiConstExp ASSIGN InitVal 
{
    $$=new TreeNode(lineno,NODE_EXPR);
    $$->optype=OP_assign;
    $$->addChild($1);
    $$->addChild($2);
    $$->addChild($4);    
};

InitVal   //变量初值
:Exp
{$$=$1;}
|LBRACE InitVal CommaInitVal RBRACE 
{
    $$=$2;
    $$->addSibling($3);
}
|LBRACE RBRACE
{
    $$=NULL;
};

CommaInitVal   //{',' InitVal}
:COMMA InitVal CommaInitVal 
{
    $$=$2;
    $$->addSibling($3);
}
|{$$=NULL;};

Stmt    //语句
:LVal ASSIGN Exp SEMI
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_assign;
    $$->addChild($1);
    $$->addChild($3);
}
|LVal PLUS ASSIGN Exp SEMI
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_plus_assign;
    $$->addChild($1);
    $$->addChild($4);
}
|LVal MINUS ASSIGN Exp SEMI
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_minus_assign;
    $$->addChild($1);
    $$->addChild($4);
}
|LVal TIMES ASSIGN Exp SEMI
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_times_assign;
    $$->addChild($1);
    $$->addChild($4);
}
|LVal OVER ASSIGN Exp SEMI
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_over_assign;
    $$->addChild($1);
    $$->addChild($4);
}
|Exp SEMI
{
    $$=$1;
}
|SEMI
{
    $$=new TreeNode(lineno,NODE_STMT);
    $$->stype=STMT_SKIP;
}
|Block
{
    $$=$1;
}
|IF LPAREN Cond RPAREN Stmt ElseStmt
{
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($3);
    node->addChild($5);
    node->addChild($6);
    $$=node;
}
|FOR LPAREN Exp1 Exp2 Exp3 RPAREN Stmt
{
    TreeNode *node=new TreeNode($3->lineno,NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($3);
    node->addChild($4);
    node->addChild($5);
    node->addChild($7);
    $$=node;
}
|WHILE LPAREN Cond RPAREN Stmt
{
    $$=new TreeNode($3->lineno,NODE_STMT);
    $$->stype=STMT_WHILE;
    $$->addChild($3);
    $$->addChild($5);
}
|BREAK SEMI 
{
    $$=new TreeNode(lineno,NODE_STMT);
    $$->stype=STMT_BREAK;
}
|CONTINUE SEMI 
{
    $$=new TreeNode(lineno,NODE_STMT);
    $$->stype=STMT_CONTINUE;
}
|RETURN Exp SEMI
{
    $$=new TreeNode(lineno,NODE_STMT);
    $$->stype=STMT_RETURN;
    $$->addChild($2);
}
|RETURN SEMI
{
    $$=new TreeNode(lineno,NODE_STMT);
    $$->stype=STMT_RETURN;
}
|PRINTF LPAREN Exp CommaExp RPAREN SEMI
{
    $$=new TreeNode($3->lineno,NODE_STMT);
    $$->stype=STMT_PRINTF;
    $$->addChild($3);
    $$->addChild($4);
}
|SCANF LPAREN Exp CommaExp RPAREN SEMI
{
    $$=new TreeNode($3->lineno,NODE_STMT);
    $$->stype=STMT_SCANF;
    $$->addChild($3);
    $$->addChild($4);
};

Exp1   //for(Exp1,Exp2,Exp3)  赋值语句，或是变量定义语句，或是空语句
:VarDecl{$$=$1;}
|Stmt{$$=$1;};

Exp2   //for(Exp1,Exp2,Exp3)  条件语句，或是空语句
:Cond SEMI{$$=$1;}
|SEMI
{
    $$=new TreeNode(lineno,NODE_STMT);
    $$->stype=STMT_SKIP;
};

Exp3  //for(Exp1,Exp2,Exp3) 表达式语句，fuzhiyuju或是空语句
:Exp {$$=$1;}
|{$$=NULL;};
|LVal ASSIGN Exp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_assign;
    $$->addChild($1);
    $$->addChild($3);
}
|LVal PLUS ASSIGN Exp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_plus_assign;
    $$->addChild($1);
    $$->addChild($4);
}
|LVal MINUS ASSIGN Exp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_minus_assign;
    $$->addChild($1);
    $$->addChild($4);
}
|LVal TIMES ASSIGN Exp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_times_assign;
    $$->addChild($1);
    $$->addChild($4);
}
|LVal OVER ASSIGN Exp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_over_assign;
    $$->addChild($1);
    $$->addChild($4);
}

ElseStmt   //else语句
:ELSE Stmt 
{
    $$=$2;
}
|{$$=NULL;};

LVal  //左值表达式
:IDENTIFIER MultiExp 
{
    if($2!=NULL)
    {
        $$=new TreeNode($1->lineno,NODE_STMT);  //需要改，暂时用不到
        $$->stype=STMT_DECL;
        $$->addChild($1);
        $$->addChild($2);
    }
    else 
    {
        $$=$1;
    }
};

Exp   //表达式
:AddExp
{
    $$=$1;
};

AddExp     //加减表达式
:MulExp
{
    $$=$1;
}
|MulExp PLUS AddExp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_plus;
    $$->addChild($1);
    $$->addChild($3);
}
|MulExp MINUS AddExp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_minus;
    $$->addChild($1);
    $$->addChild($3);
};

MulExp    //乘除模表达式
:UnaryExp
{
    $$=$1;
}
|UnaryExp TIMES MulExp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_times;
    $$->addChild($1);
    $$->addChild($3);
}
|UnaryExp OVER MulExp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_over;
    $$->addChild($1);
    $$->addChild($3);
}
|UnaryExp MOD MulExp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_mod;
    $$->addChild($1);
    $$->addChild($3);
};

UnaryExp     //一元表达式
:PrimaryExp
{
    $$=$1;
}
|IDENTIFIER LPAREN FuncRParams RPAREN    //需要改，暂时用不到
{
    $$=new TreeNode($1->lineno,NODE_STMT);
    $$->stype=STMT_DECL;
    $$->addChild($1);
    $$->addChild($3);    
}
|IDENTIFIER LPAREN RPAREN  //需要改，暂时用不到
{
    $$=new TreeNode($1->lineno,NODE_STMT);
    $$->stype=STMT_DECL;
    $$->addChild($1);   
}
|UnaryOp UnaryExp 
{
    $$=new TreeNode($1->lineno,NODE_UNARY_EXPR);
    $$->addChild($1);
    $$->addChild($2);
}
|UnaryOp LPAREN Cond RPAREN
{
    $$=new TreeNode($1->lineno,NODE_UNARY_EXPR);
    $$->addChild($1);
    $$->addChild($3);
}
|SpecialUnaryOp UnaryExp 
{
    $$=new TreeNode($1->lineno,NODE_UNARY_EXPR);
    $$->addChild($1);
    $$->addChild($2);
}
|INC UnaryExp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_pre_inc;
    $$->addChild($2);    
}
|DEC UnaryExp
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_pre_dec;
    $$->addChild($2);    
}
|UnaryExp INC
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_suf_inc;
    $$->addChild($1);    
}
|UnaryExp DEC
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_suf_inc;
    $$->addChild($1);    
};

FuncRParams  //函数实参表
:Exp CommaExp
{
    $$=new TreeNode($1->lineno,NODE_STMT);   //需要改，暂时用不到
    $$->stype=STMT_DECL;
    $$->addChild($1);
    $$->addChild($2);    
};

CommaExp //{',' Exp}
:COMMA Exp CommaExp 
{
    $$=$2;
    $$->addSibling($3);
}
|{$$=NULL;};

UnaryOp    //单目运算符
:MINUS 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_uminus;    
}
|OPPOSITE 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_opposite;    
};

SpecialUnaryOp  //特殊运算符：&，*
:TIMES 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_get_context;
}
|B_AND 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_get_address;
};


PrimaryExp  //基本表达式
: LPAREN Exp RPAREN 
{
    $$=$2;
}
|LVal
{ 
    $$ = $1;
}
|INTEGER
{ 
    $$ = $1;
}
|CHAR{$$=$1;}
|STRING {$$=$1;};

Cond    //条件表达式
:LOrExp
{
    $$=$1;
};

LOrExp   //逻辑或表达式
:LAndExp
{
    $$=$1;
}
|LPAREN LAndExp RPAREN
{
    $$=$2;
}
|LAndExp OR LOrExp 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_or;
    $$->addChild($1);
    $$->addChild($3);
}
;

LAndExp    //逻辑与表达式
:EqExp
{
    $$=$1;
}
|LPAREN EqExp RPAREN
{
    $$=$2;
}
|EqExp AND LAndExp 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_and;
    $$->addChild($1);
    $$->addChild($3);    
};

EqExp     //相等性表达式
:RelExp
{
    $$=$1;
}
|LPAREN RelExp RPAREN 
{
    $$=$2;
}
|EqExp EQ EqExp 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_eq;
    $$->addChild($1);
    $$->addChild($3);
}
|EqExp NZ EqExp 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_nz;
    $$->addChild($1);
    $$->addChild($3);
};

RelExp        //关系表达式
:AddExp
{
    $$=$1;
}
|LPAREN AddExp RPAREN
{
    $$=$2;
}
|RelExp LT AddExp 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_lt;
    $$->addChild($1);
    $$->addChild($3);
}
|RelExp GT AddExp 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_gt;
    $$->addChild($1);
    $$->addChild($3);
}
|RelExp LE AddExp 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_le;
    $$->addChild($1);
    $$->addChild($3);
}
|RelExp GE AddExp 
{
    $$=new TreeNode($1->lineno,NODE_EXPR);
    $$->optype=OP_ge;
    $$->addChild($1);
    $$->addChild($3);
};




type
: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;$$->check_type=IntegerT;} 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;$$->check_type=CharT;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;$$->check_type=BooleanT;}
|T_STRING {$$=new TreeNode(lineno,NODE_TYPE);$$->type=TYPE_STRING;$$->check_type=StringT;}
|T_VOID {$$=new TreeNode(lineno,NODE_TYPE);$$->type=TYPE_VOID;$$->check_type=VoidT;}
;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}