#ifndef TREE_H
#define TREE_H
#include "pch.h"
#include "type.h" 
#include "symbol.h"

enum NodeType
{
    NODE_CONST,   //常量
    NODE_VAR,    //变量
    NODE_EXPR,  //表达式
    NODE_UNARY_EXPR,//单目运算符表达式：-，！，&（取地址），*（取内容）
    NODE_TYPE,   //类型：int,char...
    NODE_COMP, //CompUnit
    NODE_FUNC,//FUNCTION
    NODE_STMT,
    NODE_PROG,
    NODE_BLOCK
};

enum OperatorType
{
    OP_plus , 
    OP_minus,    
    OP_times,   // *
    OP_over,    //  /
    OP_mod,
    OP_pre_inc, 
    OP_pre_dec, 
    OP_suf_inc, 
    OP_suf_dec, 
    OP_lt, 
    OP_gt, 
    OP_le ,
    OP_ge, 
    OP_nz, 
    OP_eq, 
    OP_and, 
    OP_or,  
    OP_assign, 
    OP_plus_assign,   //+=
    OP_minus_assign,  //-=
    OP_times_assign,  //*=
    OP_over_assign,   //  /= 
    OP_shl,     //  <<   还没实现
    OP_sar,     //  >>   还没实现
    OP_opposite,
    OP_uminus,
    OP_get_address, // 取地址&
    OP_get_context  // 取内容*
};

struct Label {
	string true_label;
	string false_label;
	string begin_label;
	string next_label;
};

enum StmtType {
    STMT_SKIP,
    //STMT_FUNCDEF,
    STMT_TEST,//用于找错
    STMT_DECL,
    //STMT_EXPR,
    STMT_IF,
    STMT_FOR,
    STMT_WHILE,
    STMT_PRINTF,
    STMT_SCANF,
    STMT_BREAK,
    STMT_CONTINUE,
    STMT_RETURN
}
;

enum ExpType{
    VoidT,
    IntegerT,
    CharT,
    StringT,
    BooleanT,
    StructT,
    UnionT,
    ArrayT,
    FunctionT,
    Notype
}; //用于类型检查

struct TreeNode
{
public:
    int nodeID; //用于作业序号输出
    int lineno;
    NodeType nodeType;   //节点类型

    Label label;
    ExpType check_type=Notype;//类型检查的节点类型

    int node_seq=0;
    //int temp_var_seq=0;
    //int label_seq=0;
    int temp_var=-1;//临时变量序号，也可以是字符串的序号

	TreeNode * child=nullptr;
	TreeNode * sibling=nullptr;

    void addChild(TreeNode*);
    void addSibling(TreeNode*);

    void genNodeId();//从根节点开始逐个赋Id 实现方式同学们可以自行修改
    void printAST();//打印语法树结点,先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printParseTree();
    void printNodeInfo();
    void printChildrenId();
    void printSpecialInfo();

    void get_temp_var(TreeNode *);
    string new_label();
    void get_label(TreeNode *);
    void stmt_get_label(TreeNode *);
    void expr_get_label(TreeNode *);
    void gen_header();
    void gen_decl(TreeNode *);
    void stmt_gen_code(TreeNode *);
    void expr_gen_code(TreeNode *);
    void recursive_gen_code(TreeNode *);
    void recursive_gen_str_decl(TreeNode *);
    char* toStr(TreeNode *);
    void gen_code();//ostream &out);
public:
    OperatorType optype;  // 如果是表达式
    Type* type;  // 变量、类型、表达式结点，有类型。
    symbol_table *table=nullptr;  //此节点所在符号表
    int symbol_index=-1;
    StmtType stype;
    int int_val;
    char ch_val;
    bool b_val;
    string str_val;//字符串的内容
    string var_name;
public:
    static string nodeType2String (NodeType type);
    static string opType2String (OperatorType type);
    static string sType2String (StmtType type);
    ExpType type_check(TreeNode *);
public:
    TreeNode(int lineno, NodeType type);
    TreeNode();
};


struct Node_Stack 
{
public:
	TreeNode* element=nullptr;       
	Node_Stack* next=nullptr;
    Node_Stack();
    void pushStack(TreeNode *);
    TreeNode* popStack();
    bool isEmpty();
};

#endif
