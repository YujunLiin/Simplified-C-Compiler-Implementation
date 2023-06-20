#include "common.h"
#include <fstream>

extern TreeNode *root;
extern symbol_table *root_table;
extern FILE *yyin;
extern int yyparse();
extern Node_Stack *top,*bottle;

using namespace std;
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *fin = fopen(argv[1], "r");
        if (fin != nullptr)
        {
            yyin = fin;
        }
        else
        {
            cerr << "failed to open file: " << argv[1] << endl;
        }
    }
    top=new Node_Stack();
    bottle=new Node_Stack();
    top->element=nullptr;
    top->next=bottle;
    bottle->element=nullptr;
    bottle->next=nullptr;
    yyparse();
    //cout<<"ok"<<endl;
    if(root != NULL) {
        root->genNodeId();
        //root->printAST();
        //cout<<endl<<endl;
        root->printParseTree();
        //cout<<endl<<endl;
        root->gen_code();
    //     if(root_table!=nullptr)
    // {
    //     root_table->print_symbol_table();
    // }
    // else
    // {
    //     cout<<"symbol table is empty!!!"<<endl;
    // }
    }
    return 0;
}