#include "symbol.h"


symbol_table* symbol_table::addChild()
{
    if(this->child==nullptr)
    {
        this->child=new symbol_table();
        this->child->parent=this;
        return this->child;
    }
    else
    {
        symbol_table *temp=this->child->addSibling();
        return temp;
    }
    
}
symbol_table* symbol_table::addSibling()
{
    symbol_table *temp=this;
    while(temp->sibling!=nullptr)
    {
        temp=temp->sibling;
    }
    temp->sibling=new symbol_table();
    temp->sibling->parent=this->parent;
    return temp->sibling;
}
symbol_table* symbol_table::KommZurMama()
{
    return this->parent;
}
symbol_table * symbol_table::find_scope(string name)
{
    symbol_table *cursor=this;
    while(cursor!=nullptr)
    {
        int existential_crisis=cursor->lookup(name);
        if(existential_crisis!=-1)
           return cursor;
        else
           cursor=cursor->parent;
    }
    return nullptr;
}
int symbol_table::lookup(string name)
{
    for(int i=0;i<this->size;i++)
    {
        if(this->table[i].name==name)
           return i;
    }
    return -1;
}
int symbol_table::insert(string name)
{
    if(this->size>=MAX_ID)
       return -1;
    this->table[this->size].name=name;
    this->table[this->size].type=NO_TYPE;
    this->size++;
    //cout<<"inserted success"<<this->size<<endl;
    return (this->size)-1;
}
symbol_table::symbol_table(){}
void symbol_table::print_symbol_table()
{
    if(this!=nullptr)
    {
        //cout<<this->size<<endl;
        for(int i=0;i<this->size;i++)
        {
            cout<<this->table[i].name<<" ";
        }
        cout<<endl;
        this->child->print_symbol_table();
        this->sibling->print_symbol_table();
    }
}