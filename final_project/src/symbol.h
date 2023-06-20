#ifndef STMBOL_H
#define SYMBOL_H
#include "type.h" 
#define MAX_ID 64
struct symbol_entry
{
    public:
    string name;
    ValueType type;
};
class symbol_table
{
public:
    symbol_entry table[MAX_ID];
    int size=0;
    symbol_table *parent=nullptr;
    symbol_table *child=nullptr;
    symbol_table *sibling=nullptr;
    symbol_table* addSibling();
public:
    symbol_table();
    symbol_table* addChild();
    symbol_table* KommZurMama();
    symbol_table * find_scope(string name);//查找该变量名所在的作用域节点
    int lookup(string name);//在作用域中找到变量序号
    int insert(string name);//当前作用域中插入新变量
    void print_symbol_table();
};
#endif
