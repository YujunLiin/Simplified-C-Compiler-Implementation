#include "tree.h"
long int current_id=0;
extern TreeNode* root;
//#define max_temp_var 20;
int temp_var_count=0;//临时变量计数
int const_str_count=0;//字符串计数，用于printf和scanf参数中的字符串
int label_seq=0;//打label用的，label计数
int next_label_seq=0;//用于给if语句打label
//int var_counter[max_temp_var];
extern symbol_table *root_table;
char *check_type_info[10]={(char *)"void",(char *)"integer",(char *)"char",(char *)"string",(char *)"bool",(char *)"struct",(char *)"union",(char *)"array",(char *)"function",(char *)"type-error"};
extern Node_Stack *top,*bottle;
// void pushStack(TreeNode *);
// TreeNode* popStack();
Node_Stack::Node_Stack(){}

void Node_Stack::pushStack(TreeNode *ele)
{
	Node_Stack *t=new Node_Stack();
	t->element=ele;
	t->next=top->next;
	top->next=t;
}
TreeNode* Node_Stack::popStack()
{
	if(top->next==bottle)
	return nullptr;
	TreeNode *t=top->next->element;
	top->next=top->next->next;
	return t;
}
bool Node_Stack::isEmpty()
{
	if(top->next==bottle)
	return true;
	else 
	return false;
}
void clean()
{

}
void TreeNode::addChild(TreeNode* t)
{
	if(t!=nullptr&&this!=nullptr)
	{
		if(this->child==nullptr)
		{
			this->child=t;
		}
		else 
		{
			TreeNode *temp=this->child;
			temp->addSibling(t);
		}
	}
	return;
}
void TreeNode::addSibling(TreeNode *t)
{
	if(t!=nullptr&&this!=nullptr)
	{
	TreeNode *temp=this;
	while(temp->sibling!=nullptr)
	{
		temp=temp->sibling;
	}
	temp->sibling=t;
	}
	return;
}
void TreeNode::genNodeId()
{
	if(this!=nullptr){
	this->nodeID=current_id++;
	this->child->genNodeId();
	this->sibling->genNodeId();
	}
	return;
}
void TreeNode::printNodeInfo()
{
	if(this!=nullptr){
	cout<<"lno@"<<this->lineno<<setw(8)<<"@"<<this->nodeID<<"  ";
	cout<<setw(10)<<nodeType2String(this->nodeType)<<setw(8)<<"type: "<<check_type_info[this->check_type];
	this->printChildrenId();
	cout<<"  ";
	this->printSpecialInfo();
	cout<<endl;
	}
	return;
}
void TreeNode::printChildrenId()
{
    if(this != nullptr)
    {
        if(this->child != nullptr)
        {
            cout<<setw(8)<<"children: [";
            TreeNode* trace = this->child;
            do{
                cout<<"@"<<trace->nodeID<<' ';
                trace = trace->sibling;
            }while(trace != nullptr);
            cout<<"]";
        }
    }
	return;
}
void TreeNode::printSpecialInfo()
{
	switch(this->nodeType){
		case NODE_CONST:
		cout<<setw(8)<<"const  "<<"type: "<<this->type->getTypeInfo()<<"  value:"<<this->int_val;
		break;
		case NODE_VAR:
		cout<<setw(8)<<"variable  "<<setw(8)<<"varname: "<<this->var_name<<setw(8)<<"type: "<<check_type_info[this->check_type];
		break;
		case NODE_EXPR:
		cout<<setw(8)<<"expression: "<<this->opType2String(this->optype);
		break;
		case NODE_UNARY_EXPR:
		cout<<setw(8)<<"unary expression: ";//<<this->child->opType2String(this->child->optype);
		break;
		case NODE_TYPE:
		cout<<setw(8)<<"type: "<<this->type->getTypeInfo();
		break;
		case NODE_STMT:
		cout<<setw(8)<<"statement: "<<sType2String(this->stype);
		break;
		case NODE_PROG:
		cout<<setw(8)<<"program";
		break;
		case NODE_FUNC:
		cout<<setw(8)<<"name: "<<this->var_name;
		break;
		default:
		break;
	}
	return;
}
void TreeNode::printParseTree() {//递归地实现输出
    if(this != nullptr)
    {
		if(this->child!=nullptr)
		this->child->printParseTree();
		this->check_type=this->type_check(this);
		get_temp_var(this);
		//this->printNodeInfo();
		if(this->sibling!=nullptr)
		this->sibling->printParseTree();
    }
	return;
}
void TreeNode::printAST() {//递归地实现输出
    if(this != nullptr)
    {
        this->printNodeInfo();//还是先自己输出信息，再考虑孩子节点，再考虑兄弟节点
        this->child->printAST();
        this->sibling->printAST();
    }
	return;
}
string TreeNode::sType2String(StmtType type) {
    switch (type)
    {
    case STMT_DECL:
    return "declaration";
	//case STMT_FUNCDEF:
	//return "Function defination";
	case STMT_IF:
	return "if"; 
	case STMT_FOR:
    return "for";
	case STMT_WHILE:
	return "while"; 
	case STMT_PRINTF:
    return "printf";
	case STMT_SCANF:
	return "scanf"; 
	case STMT_BREAK:
    return "break";
	case STMT_CONTINUE:
	return "continue"; 
	case STMT_RETURN:
	return "return"; 
	//case STMT_EXPR:
	//return "expression";
	case STMT_SKIP:
	return "skip";
	case STMT_TEST:
	return "test now";
    default:
	return "???";
    break;
    }
}
string TreeNode::nodeType2String (NodeType type){
    switch (type)
    {
    case NODE_CONST:
    return "const";
    case NODE_VAR:
    return "variable";
	case NODE_COMP:
	return "CompUnit";
    case NODE_EXPR:
    return "expression";
	case NODE_UNARY_EXPR:
    return "unary expression";
    case NODE_TYPE:
    return "type";
    case NODE_STMT:
    return "statement";
    case NODE_PROG:
    return "program";
	case NODE_FUNC:
	return "function";
	case NODE_BLOCK:
	return "block";
    default:
	return "???";
    break;
    }
}
string TreeNode::opType2String (OperatorType type)
{
	switch(type){
		case OP_plus:
		return "+";
		break;
		case OP_minus:
		return "-";
		break;
		case OP_times:
		return "*";
		break;
		case OP_over:
		return "/";
		break;
		case OP_pre_inc:
		return "pre++";
		break;
		case OP_pre_dec:
		return "pre--";
		break;
		case OP_suf_inc:
		return "++suf";
		break;
		case OP_suf_dec:
		return "--suf";
		break;
		case OP_lt:
		return "<";
		break;
		case OP_gt:
		return ">";
		break;
		case OP_le:
		return "<=";
		break;
		case OP_ge:
		return ">=";
		break;
		case OP_nz:
		return "!=";
		break;
		case OP_eq:
		return "==";
		break;
		case OP_and:
		return "&&";
		break;
		case OP_or:
		return "||";
		break;
		case OP_opposite:
		return "!";
		break;
		case OP_plus_assign:   
		return "+=";
		break;
        case OP_minus_assign:  
		return "-=";
		break;
        case OP_times_assign:
		return "*=";
		break;
        case OP_over_assign:
		return "/=";
		break;
		case OP_assign:
		return "=";
		break;
		case OP_mod:
		return "%";
		break;
		case OP_shl:
		return "<<";
		break;
		case OP_sar:
		return ">>";
		break;
		case OP_uminus:
		return "-";
		break;
		case OP_get_address:
		return "&";
		break;
		case OP_get_context:
		return "*";
		break;
        default:
		return "???";
		break;
	}
}
TreeNode::TreeNode(int lineno, NodeType type)
{
	this->lineno=lineno;
	this->nodeType=type;
}
TreeNode::TreeNode()
{}
void TreeNode::get_temp_var(TreeNode *node)
{
	if(node->nodeType!=NODE_EXPR&&node->nodeType!=NODE_UNARY_EXPR)
	return;
	if(node->nodeType==NODE_EXPR)
	{
		if(node->optype>4)
	    return;
    	TreeNode* child1=node->child;
		int temp_var_count_back_up=temp_var_count;
    	if(child1->nodeType==NODE_EXPR)
    	temp_var_count--;
		//cout<<temp_var_count<<endl;
    	if(child1->sibling!=nullptr&&(child1->sibling->nodeType==NODE_EXPR||child1->sibling->nodeType==NODE_UNARY_EXPR))
    	temp_var_count--;
		if(temp_var_count_back_up==temp_var_count+2)
		temp_var_count++;
    	node->temp_var=temp_var_count;
    	temp_var_count++;
		//cout<<temp_var_count<<endl;
    	return;
	}
	else 
	{
		TreeNode *child1=node->child;
		TreeNode *child2=child1->sibling;
		if(child2!=nullptr&&(child2->nodeType==NODE_EXPR||child2->nodeType==NODE_UNARY_EXPR))
		temp_var_count--;
		node->temp_var=temp_var_count;
		temp_var_count++;
		//cout<<endl<<temp_var_count<<endl;
		return;
	}
}
ExpType TreeNode::type_check(TreeNode *node)
{
	switch(node->nodeType)
	{
	 	case NODE_CONST:
		return node->check_type;

		case NODE_VAR:
		switch(this->table->table[this->symbol_index].type)
		{
			case  VALUE_BOOL:
			return BooleanT;
			case VALUE_VOID:
			return VoidT;
			case VALUE_INT:
			return IntegerT;
			case VALUE_CHAR:
			return CharT;
			case VALUE_STRING:
			return StringT;
			case COMPOSE_STRUCT:
			return StructT;
			case COMPOSE_UNION:
			return UnionT;
			case COMPOSE_ARRAY:
			return ArrayT;
			case COMPOSE_FUNCTION:
			return FunctionT;
			default:
			return Notype;
		}
		break;

        case NODE_TYPE:
		if(node->nodeType==NODE_TYPE)
		{
			ExpType checktyp=node->check_type;
			ValueType valuetyp=node->type->type;
			TreeNode *sibling=node->sibling;
			while(sibling!=nullptr&&((sibling->nodeType==NODE_VAR)||(sibling->nodeType==NODE_EXPR)))
			{ 
				TreeNode *temp=sibling;
				if(sibling->nodeType==NODE_EXPR&&sibling->optype==OP_assign)
				{
					temp=sibling->child;
				}
				if(temp->table->table[temp->symbol_index].type==valuetyp)
				{
					cerr << "redefinition fault at line: " << node->lineno << endl;
				    sibling=sibling->sibling;
				}
				else
				{
					temp->check_type=checktyp;
				    temp->type=new Type(valuetyp);
				    temp->table->table[temp->symbol_index].type=valuetyp;
				    sibling=sibling->sibling;
				}
			}
			return checktyp;
		}
		break;

		case NODE_EXPR:
		{
		if(node->optype==OP_plus||node->optype==OP_minus||node->optype==OP_times||node->optype==OP_over||node->optype==OP_plus_assign||node->optype==OP_minus_assign||node->optype==OP_times_assign||node->optype==OP_over_assign||node->optype==OP_mod)
		{
			if(node->child->check_type==Notype)
			{
				cerr << "undifined variaty at line: " << node->lineno << endl;
			}
			else if(node->child->check_type!=node->child->sibling->check_type)
			{
				cerr << "Expression(+,-,*,/,%,+=,-=,*=,/=) type match fault at line: " << node->lineno << endl;
			}
			else 
			return node->child->check_type;
		}
		if(node->optype==OP_pre_dec||node->optype==OP_pre_inc||node->optype==OP_pre_dec||node->optype==OP_suf_inc)
		{
			if(node->child->check_type!=IntegerT)
			cerr << "self increase or decrease should be integer,type match fault at line: " << node->lineno << endl;
			else 
			return IntegerT;
		}
		if(node->optype==OP_lt||node->optype==OP_gt||node->optype==OP_le||node->optype==OP_ge||node->optype==OP_nz||node->optype==OP_eq)
		{
			if(node->child->check_type==Notype)
			{
				cerr << "undifine variaty at line: " << node->lineno << endl;
			}
			else if(node->child->check_type!=node->child->sibling->check_type)
			{
				cerr << "comparation(>=,<=,>,<,==) type match failed at line: " << node->lineno << endl;
			}
			else 
			return BooleanT;
		}
		if(node->optype==OP_and||node->optype==OP_or)
		{
			if(node->child->check_type==Notype)
			{
				cerr << "undifine variaty at line: " << node->lineno << endl;
			}
			else if(node->child->check_type!=BooleanT||node->child->sibling->check_type!=BooleanT)
			{
				cerr << "bool(and,or) type match failed at line: " << node->lineno << endl;
			}
			else 
			return BooleanT;
		}
		if(node->optype==OP_assign)
		{
			if(node->child->check_type==Notype)
			{
				cerr << "undifined variaty at line: " << node->lineno << endl;
			}
			else if(node->child->check_type!=node->child->sibling->check_type)
			{
				cerr << "assign type match failed at line: " << node->lineno << endl;
			}
			else 
			return node->child->check_type;
		}
		else
		return VoidT;
		}
		break;

		case NODE_UNARY_EXPR:
		{
		if(node->child->optype==OP_uminus)
		{
			if(node->child->sibling->check_type!=IntegerT)
			{
				cerr << "uminus type match failed at line: " << node->lineno << endl;
			}
			else 
			return IntegerT;
		}
		if(node->child->optype==OP_opposite)
		{
			if(node->child->sibling->check_type!=BooleanT)
			{
				cerr << "opposite type match failed at line: " << node->lineno << endl;
			}
			else 
			return BooleanT;
		}
		if(node->child->optype==OP_get_address)
		{
			if(node->child->sibling->nodeType!=NODE_VAR)
			{
				cerr << "GET_ADDRESS(&) type match failed at line: " << node->lineno << endl;
			}
			else 
			return IntegerT;
		}
		if(node->child->optype==OP_get_context)
		{}
        else
		return VoidT;
		}
		break;

		case NODE_STMT:
		{
		if(node->stype==STMT_DECL)	
		{}
		if(node->stype==STMT_IF)
		{
			if(node->child->check_type!=BooleanT)
			{
				cerr << "statement IF type should be cond,bool match failed at line: " << node->lineno << endl;
			}
			else 
			return VoidT;
		}
		if(node->stype==STMT_FOR)
		{
			if(node->child->sibling->check_type!=BooleanT&&node->child->sibling->stype!=STMT_SKIP)
			{
				cerr << "statement FOR type should be cond or null,type match failed at line: " << node->lineno << endl;
			}
			else 
			return VoidT;
		}
		if(node->stype==STMT_WHILE)
		{
			if(node->child->check_type!=BooleanT)
			{
				cerr << "statement WHILE type should be cond,bool match failed at line: " << node->lineno << endl;
			}
			else 
			return VoidT;
		}
	    else
		return VoidT;
		}
		break;

		default:
		return VoidT;
		break;
	}
	//cout<<node->nodeType<<endl;
}
string TreeNode::new_label()
{
	char tmp[20];
	sprintf(tmp,".L%d",label_seq);
	label_seq++;
	return tmp;
}
void TreeNode::get_label(TreeNode *node)
{
	if(node->nodeType==NODE_EXPR||node->nodeType==NODE_UNARY_EXPR)
	{
		//cout<<node->nodeType<<"  expr_label 1 "<<node->nodeID<<endl;
		this->expr_get_label(node);
		//cout<<node->nodeType<<"  expr_label 2 "<<node->label.true_label<<"  "<<node->label.false_label<<endl;
		return;
	}
	else if(node->nodeType==NODE_STMT)
	{
		this->stmt_get_label(node);
		return;
	}
	else 
	return;
}
void TreeNode::stmt_get_label(TreeNode *node)
{
	if(node->stype==STMT_WHILE||node->stype==STMT_FOR)
	node->label.begin_label=new_label();
	return;
}
void TreeNode::expr_get_label(TreeNode *node)
{
	if(node->check_type!=BooleanT)
	return;
	if(node->label.false_label.size()==0)
	{
		node->label.true_label=new_label();
		node->label.false_label=new_label();
		//cout<<endl<<node->nodeID<<" "<<node->label.true_label<<" "<<node->label.false_label<<endl;
	}
	if(node->child!=nullptr&&node->child->sibling!=nullptr)
    {
		TreeNode *child1=node->child;
		TreeNode *child2=child1->sibling;
		if(node->optype==OP_and)
		{
			child1->label.true_label=new_label();
			child2->label.true_label=node->label.true_label;
			child1->label.false_label=child2->label.false_label=node->label.false_label;
		}
		else if(node->optype==OP_or)
		{
			child2->label.false_label=node->label.false_label;
			child2->label.true_label=node->label.true_label;
			child1->label.false_label=new_label();
			child1->label.true_label=node->label.true_label;
	        //cout<<endl<<node->nodeID<<" "<<child2->label.true_label<<" "<<child2->label.false_label<<endl;	
		}
		else if(node->nodeType==NODE_UNARY_EXPR&&child1->optype==OP_opposite)
		{
			child2->label.true_label = node->label.false_label;
			child2->label.false_label = node->label.true_label;
		}
	}
	return;
}
void TreeNode::gen_header(){}//ostream &out){}
void TreeNode::gen_decl(TreeNode *node)
{
	cout<<endl<<"# define your veriables and temp veriables here" << endl;
	cout<<"\t.text"<<endl;
	cout<<"\t.bss"<<endl;
	TreeNode *node_back_up=node;
	for(;node!=nullptr;node=node->sibling)
	{
		if(node->nodeType==NODE_STMT&&node->stype==STMT_DECL)
		{
			for(TreeNode *t=node->child;t!=nullptr;t=t->sibling)
			{
				if(t->nodeType==NODE_VAR)
				{
					if(t->check_type==IntegerT)
					{
						cout<<"\t.globl\t"<<t->var_name<<endl;
					    cout<<"\t.align\t4"<<endl;
						cout<<"\t.type\t"<<t->var_name<<", @object"<<endl;
						cout<<t->var_name<<":"<<endl;
						cout<<"\t.zero\t4"<<endl;
				    }
				    else if(t->check_type==CharT)
				    {
					    cout<<"\t.globl\t"<<t->var_name<<endl;
					    //cout<<"\t.align\t4"<<endl;
						cout<<"\t.type\t"<<t->var_name<<", @object"<<endl;
						cout<<t->var_name<<":"<<endl;
						cout<<"\t.zero\t1"<<endl;
				    }
			    }
			    else if(t->nodeType==NODE_EXPR&&t->optype<OP_opposite)
				{
					TreeNode *temp=t->child;
					if(temp->nodeType==NODE_VAR)
				{
					if(temp->check_type==IntegerT)
					{
						cout<<"\t.globl\t"<<temp->var_name<<endl;
					    cout<<"\t.align\t4"<<endl;
						cout<<"\t.type\t"<<temp->var_name<<", @object"<<endl;
						cout<<temp->var_name<<":"<<endl;
						cout<<"\t.zero\t4"<<endl;
				    }
				    else if(temp->check_type==CharT)
				    {
					    cout<<"\t.globl\t"<<temp->var_name<<endl;
					    //cout<<"\t.align\t4"<<endl;
						cout<<"\t.type\t"<<temp->var_name<<", @object"<<endl;
						cout<<temp->var_name<<":"<<endl;
						cout<<"\t.zero\t1"<<endl;
				    }
			    }
				}
			}
		}
		else if(node->nodeType==NODE_COMP&&node->child->nodeType==NODE_FUNC)
		{
			if(node->child->child->sibling->nodeType==NODE_BLOCK)
			{
				for(TreeNode *t=node->child->child->sibling->child;t!=nullptr;t=t->sibling)
				{
					if(t->nodeType==NODE_STMT&&t->stype==STMT_DECL)
					{
						for(TreeNode *child=t->child->sibling;child!=nullptr;child=child->sibling)
			            {
							TreeNode *temp=child;
							if(child->nodeType==NODE_EXPR&&child->optype==OP_assign)
							temp=child->child;
				            if(temp->nodeType==NODE_VAR)
				            {
        					    if(temp->check_type==IntegerT)
		        			    {
				        	    	cout<<"\t.globl\t"<<temp->var_name<<endl;
					                cout<<"\t.align\t4"<<endl;
					            	cout<<"\t.type\t"<<temp->var_name<<", @object"<<endl;
					            	cout<<temp->var_name<<":"<<endl;
					            	cout<<"\t.zero\t4"<<endl;
				                }
        				        else if(temp->check_type==CharT)
		        		        {
				        	        cout<<"\t.globl\t"<<temp->var_name<<endl;
					                //cout<<"\t.align\t4"<<endl;
						            cout<<"\t.type\t"<<temp->var_name<<", @object"<<endl;
						            cout<<temp->var_name<<":"<<endl;
					            	cout<<"\t.zero\t1"<<endl;
			    	            }
			                }
			            }
					}
				}
			}
			
		}
	}
	for(int i=0; i < temp_var_count;i++)
	{
		cout<<"\t.globl"<<"\tt"<<i<<endl;
		cout<<"\t.align\t4"<<endl;
		//cout<<"\t.type\t"<<t->var_name<<", @object"<<endl;
		cout<<"t"<<i<<":"<<endl;
		cout<<"\t.zero\t4"<<endl;
	}
	cout<<endl<<"\t.section\t.rodata"<<endl;
	node=node_back_up;
	for(;node!=nullptr;node=node->sibling)
	{
		if(node->nodeType==NODE_STMT&&node->stype==STMT_PRINTF)
		{
			TreeNode *t=node->child;
			if(t->nodeType==NODE_CONST&&t->check_type==StringT)
			{
				cout<<"STR"<<const_str_count<<":"<<endl;
				cout<<"\t.string "<<t->str_val<<endl;
				t->temp_var=const_str_count;
				const_str_count++;
			}
		}
		else if(node->nodeType==NODE_STMT&&node->stype==STMT_SCANF)
		{
			TreeNode *t=node->child;
			if(t->nodeType==NODE_CONST&&t->check_type==StringT)
			{
				cout<<"STR"<<const_str_count<<":"<<endl;
				cout<<"\t.string "<<t->str_val<<endl;
				t->temp_var=const_str_count;
				const_str_count++;
			}
		}
		else if(node->nodeType==NODE_COMP&&node->child->nodeType==NODE_FUNC)
		{
			if(node->child->child->sibling->nodeType==NODE_BLOCK)
			{
				for(TreeNode *t=node->child->child->sibling->child;t!=nullptr;t=t->sibling)
				{
					if(t->nodeType==NODE_STMT&&t->stype==STMT_PRINTF)
					{
						TreeNode *p=t->child;
			            if(p->nodeType==NODE_CONST&&p->check_type==StringT)
			            {
				            cout<<"STR"<<const_str_count<<":"<<endl;
	            			cout<<"\t.string "<<p->str_val<<endl;
							p->temp_var=const_str_count;
	            			const_str_count++;
	            		}
					}
					else if(t->nodeType==NODE_STMT&&t->stype==STMT_SCANF)
					{
						TreeNode *p=t->child;
			            if(p->nodeType==NODE_CONST&&p->check_type==StringT)
			            {
				            cout<<"STR"<<const_str_count<<":"<<endl;
	            			cout<<"\t.string "<<p->str_val<<endl;
							p->temp_var=const_str_count;
	            			const_str_count++;
	            		}
					}
				    else if(t->nodeType==NODE_STMT&&(t->stype==STMT_FOR||t->stype==STMT_WHILE))
					{
						TreeNode *temp=t->child;
						while(temp->sibling!=nullptr)
						{
							temp=temp->sibling;
						}
						if(temp->nodeType==NODE_STMT)
						recursive_gen_str_decl(temp);
						else if(temp->nodeType==NODE_BLOCK)
						recursive_gen_str_decl(temp->child);
					}
					else if(t->nodeType==NODE_STMT&&t->stype==STMT_IF)
					{
						//cout<<endl<<"1 "<<t->nodeID<<" "<<t->nodeType<<endl;
						TreeNode *temp=t->child->sibling;
						for(int i=0;i<2&&temp!=nullptr;i++)
						{
							if(temp->nodeType==NODE_STMT)
						    recursive_gen_str_decl(temp);
						    else if(temp->nodeType==NODE_BLOCK)
						    recursive_gen_str_decl(temp->child);
							temp=temp->sibling;
						}
					}
				}
			}	
		}
	}
}
void TreeNode::recursive_gen_str_decl(TreeNode *node)
{
	TreeNode *t=node;
	for(;t!=nullptr;t=t->sibling)
	{
		if(t->nodeType==NODE_STMT&&t->stype==STMT_PRINTF)
		{
			TreeNode *temp=t->child;
			if(temp->nodeType==NODE_CONST&&temp->check_type==StringT)
			{
				cout<<"STR"<<const_str_count<<":"<<endl;
				cout<<"\t.string "<<temp->str_val<<endl;
				temp->temp_var=const_str_count;
				const_str_count++;
			}
		}
		else if(t->nodeType==NODE_STMT&&t->stype==STMT_SCANF)
		{
			TreeNode *temp=t->child;
			if(temp->nodeType==NODE_CONST&&temp->check_type==StringT)
			{
				cout<<"STR"<<const_str_count<<":"<<endl;
				cout<<"\t.string "<<temp->str_val<<endl;
				temp->temp_var=const_str_count;
				const_str_count++;
			}
		}
		else if(t->nodeType==NODE_STMT&&(t->stype==STMT_FOR||t->stype==STMT_WHILE))
					{
						TreeNode *temp=t->child;
						while(temp->sibling!=nullptr)
						{
							temp=temp->sibling;
						}
						if(temp->nodeType==NODE_STMT)
						recursive_gen_str_decl(temp);
						else if(temp->nodeType==NODE_BLOCK)
						recursive_gen_str_decl(temp->child);
					}
		else if(t->nodeType==NODE_STMT&&t->stype==STMT_IF)

					{
						TreeNode *temp=t->child->sibling;
						for(int i=0;i<2&&temp!=nullptr;i++)
						{
							if(temp->nodeType==NODE_STMT)
						    recursive_gen_str_decl(temp);
						    else if(temp->nodeType==NODE_BLOCK)
						    recursive_gen_str_decl(temp->child);
							temp=temp->sibling;
						}
					}
	}
}
void TreeNode::recursive_gen_code(TreeNode *node)
{
	if(node==nullptr)
	return;
	switch(node->nodeType)
	{
		case NODE_EXPR:
		case NODE_UNARY_EXPR:
		node->expr_gen_code(node);
		return;

		case NODE_COMP:
        case NODE_FUNC:
        case NODE_STMT:
        case NODE_PROG:
        case NODE_BLOCK:
		node->stmt_gen_code(node);
		return;
		default:
		return;
	}
}
void TreeNode::stmt_gen_code(TreeNode *node)
{
	get_label(node);
	if(node->nodeType==NODE_COMP)
	{
		TreeNode *t=node->child;
		// while(t!=nullptr)
		// {
		// 	recursive_gen_code(t);
		// 	t=t->sibling;
		// }
		recursive_gen_code(t);
		recursive_gen_code(node->sibling);
	}
	else if(node->nodeType==NODE_FUNC)
	{
		cout<<"\t.globl "<<node->var_name<<endl;
		cout<<"\t.type "<<node->var_name<<", @function"<<endl;
		cout<<node->var_name<<":"<<endl;
		if(node->var_name=="main")
		{
			cout<<"\tleal 4(%esp), %ecx"<<endl;
			cout<<"\tandl $-16, %esp"<<endl;
	        cout<<"\tpushl -4(%ecx)"<<endl;
			cout<<"\tpushl %ebp"<<endl;
			cout<<"\tmovl %esp, %ebp"<<endl;
			cout<<"\tpushl %ecx"<<endl;
			cout<<"\tsubl $4, %esp"<<endl;
		}
		TreeNode *t=node->child;
		while(t!=nullptr)
		{
			if(t->nodeType==NODE_BLOCK)
			{
				//cout<<"stmt_gen_code:block"<<endl;
				stmt_gen_code(t);
			}
			t=t->sibling;
		}
		recursive_gen_code(node->sibling);
	}
	else if(node->nodeType==NODE_BLOCK)
	{
		TreeNode *t=node->child;
		recursive_gen_code(t);
		// while(t!=nullptr)
		// {
		// 	//cout<<"gen_code:block's children"<<endl;
		// 	recursive_gen_code(t);
		//     t=t->sibling;
		// }
	}
	else if(node->nodeType==NODE_STMT)
	{
		switch(node->stype)
		{
			case STMT_DECL:
			if(node->stype==STMT_DECL)
			{
				TreeNode *t=node->child;
				if(t->sibling!=nullptr)
				{
					t=t->sibling;
					while(t!=nullptr)
					{
						if(t->nodeType==NODE_EXPR)
						{
							//cout<<t->nodeType<<"  1  "<<t->nodeID<<endl;
							expr_gen_code(t);
						}
						//cout<<t->nodeType<<"  2  "<<t->nodeID<<endl;
						t=t->sibling;
					}
				}
				recursive_gen_code(node->sibling);
			}
			break;
			case STMT_PRINTF:
			if(node->stype==STMT_PRINTF)
			{
				int count=0;//计算压栈了几个变量，便于后续函数调用完毕后降低esp
				for(TreeNode *t=node->child;t!=nullptr;t=t->sibling)
				{
					top->pushStack(t);
					count++;
				}
				int shang=count/4;
				int yu=count%4;
				int duiqi=(4-yu)%4;
				cout<<"\tsubl $"<<4*duiqi<<", %esp"<<endl;
				while(!(top->isEmpty()))
				{
					TreeNode *t=top->popStack();
					if(t->nodeType==NODE_VAR)
					{
						cout<<"\txorl %eax,%eax"<<endl;
						cout<<"\tmovl "<<t->var_name<<", %eax"<<endl;
						cout<<"\tpushl %eax"<<endl;
					}
					else if(t->nodeType==NODE_CONST&&t->check_type==StringT)
					{
						cout<<"\tpushl $STR"<<t->temp_var<<endl;
					}
				}
				cout<<"\tcall printf"<<endl;
				if(yu!=0)
				{
					shang++;
				}
				cout<<"\taddl $"<<16*shang<<", %esp"<<endl;
				recursive_gen_code(node->sibling);
			}
			break;
			case STMT_SCANF:
			if(node->stype==STMT_SCANF)
			{
				int count=0;//计算压栈了几个变量，便于后续函数调用完毕后降低esp
				for(TreeNode *t=node->child;t!=nullptr;t=t->sibling)
				{
					top->pushStack(t);
					count++;
				}
				int shang=count/4;
				int yu=count%4;
				int duiqi=(4-yu)%4;
				cout<<"\tsubl $"<<4*duiqi<<", %esp"<<endl;
				while(!(top->isEmpty()))
				{
					TreeNode *t=top->popStack();
					if(t->nodeType==NODE_VAR)
					{
						cout<<"\txorl %eax,%eax"<<endl;
						cout<<"\tmovl "<<t->var_name<<", %eax"<<endl;
					}
					else if(t->nodeType==NODE_CONST&&t->check_type==StringT)
					{
						cout<<"\tpushl $STR"<<t->temp_var<<endl;
					}
					else if(t->nodeType==NODE_UNARY_EXPR)
					{
						if(t->child->nodeType==NODE_EXPR&&t->child->optype==OP_get_address)
						{
							if(t->child->sibling->nodeType==NODE_VAR)
							{
								cout<<"\tpushl $"<<t->child->sibling->var_name<<endl;
							}
						}
					}
				}
				cout<<"\tcall scanf"<<endl;
				if(yu!=0)
				{
					shang++;
				}
				cout<<"\taddl $"<<16*shang<<", %esp"<<endl;
				recursive_gen_code(node->sibling);
			}
		    break;
			case STMT_IF:
			if(node->stype==STMT_IF)
			{
				TreeNode *child_cond=node->child;
				TreeNode *child_if=child_cond->sibling;
				TreeNode *child_else=child_if->sibling;
				expr_gen_code(child_cond);
				cout<<child_cond->label.true_label<<":"<<endl;
				recursive_gen_code(child_if);
				cout<<"\tjmp next"<<next_label_seq<<endl;
				cout<<child_cond->label.false_label<<":"<<endl;
				recursive_gen_code(child_else);	
				cout<<"\tjmp next"<<next_label_seq<<endl;
				cout<<"next"<<next_label_seq++<<":"<<endl;
				recursive_gen_code(node->sibling);
			}
		    break;
			case STMT_WHILE:
			if(node->stype==STMT_WHILE)
			{
				if(node->label.begin_label.size()!=0)
				{
					cout<<node->label.begin_label<<":"<<endl;
				}
				expr_gen_code(node->child);
				cout<<node->child->label.true_label<<":"<<endl;
				recursive_gen_code(node->child->sibling);
				clean();
				cout<<"\tjmp "<<node->label.begin_label<<endl;
				cout<<node->child->label.false_label<<":"<<endl;
				recursive_gen_code(node->sibling);
			}
		    break;
			case STMT_FOR:
			if(node->stype==STMT_FOR)
			{
				TreeNode *child1=node->child;
				if(child1->nodeType==NODE_EXPR)
				expr_gen_code(child1);
				else if(child1->nodeType==NODE_STMT)
				{
					if(child1->stype!=STMT_SKIP)
					recursive_gen_code(child1);
				}
				if(node->label.begin_label.size()!=0)
				{
					cout<<node->label.begin_label<<":"<<endl;
				}
				TreeNode *child2=child1->sibling;
				if(child2->nodeType==NODE_EXPR)
				expr_gen_code(child2);
				else if(child2->nodeType==NODE_STMT)
				{
					if(child2->stype!=STMT_SKIP)
					recursive_gen_code(child2);
				}
				cout<<child2->label.true_label<<":"<<endl;
				TreeNode *child3=child2->sibling ;
				if(child3!=nullptr)
				{
					recursive_gen_code(child3->sibling);
					recursive_gen_code(child3);
					clean();
					cout<<"\tjmp "<<node->label.begin_label<<endl;
					cout<<child2->label.false_label<<":"<<endl;
					recursive_gen_code(node->sibling);
				}
				else
				{
					recursive_gen_code(child2->sibling);
					clean();
					cout<<"\tjmp "<<node->label.begin_label<<endl;
					cout<<child2->label.false_label<<":"<<endl;
					recursive_gen_code(node->sibling);
				}
			}
		    break;
			case STMT_RETURN:
			{
				cout<<"\tmovl $0, %eax"<<endl;
				cout<<"\tmovl -4(%ebp), %ecx"<<endl;
				cout<<"\tleave"<<endl;
				cout<<"\tleal -4(%ecx), %esp"<<endl;
				cout<<"\tret"<<endl;
				break;
			}
		}
	}
}
void TreeNode::expr_gen_code(TreeNode *node)
{
	//cout<<node->nodeType<<"  3  "<<node->nodeID<<endl;
	if(node==nullptr)
		return;
	if(!(node->nodeType==NODE_EXPR||node->nodeType==NODE_UNARY_EXPR))
	    return;
	if(node->nodeType==NODE_EXPR&&node->optype>=OP_opposite)
	return;
	get_label(node);
	//cout<<node->nodeID<<" "<<node->label.true_label<<" "<<node->label.false_label<<endl;
	//cout<<node->child->nodeID<<" "<<node->child->label.true_label<<" "<<node->child->label.false_label<<endl;
	//cout<<node->child->sibling->nodeID<<" "<<node->child->sibling->label.true_label<<" "<<node->child->sibling->label.false_label<<endl;
	TreeNode *child1=node->child;
	TreeNode *child2=child1->sibling;
	expr_gen_code(child1);
	if(child2!=nullptr&&(child2->nodeType==NODE_EXPR||child2->nodeType==NODE_UNARY_EXPR))
	{
		expr_gen_code(child2);
	}
	if(node->optype==OP_and||node->optype==OP_or)
	return;
	//cout<<node->optype<<endl;
	if(node->nodeType==NODE_EXPR)
	{
	switch(node->optype)
	{
		case OP_plus:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %eax"<<endl;
			cout<<"\taddl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tmovl %eax, ";
			toStr(node);
			cout<<endl;
			break;
		}
		case OP_minus:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %eax"<<endl;
			cout<<"\tsubl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tmovl %eax, ";
			toStr(node);
			cout<<endl;
			break;
		}
		case OP_times:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %eax"<<endl;
			cout<<"\timull ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tmovl %eax, ";
			toStr(node);
			cout<<endl;
			break;
		}
		case OP_over:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\txorl %ebx, %ebx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %eax"<<endl;
			cout<<"\tmovl ";
			toStr(child2);
			cout<<", %ebx"<<endl;
			cout<<"\tidivl %ebx"<<endl;
			cout<<"\tmovl %eax, ";
			toStr(node);
			cout<<endl;
			break;
		}
		case OP_assign:
		//cout<<"assign"<<endl;
		cout<<"\txorl %eax, %eax"<<endl;
		cout<<"\txorl %edx, %edx"<<endl;
		if(child1->check_type==CharT)
		{
			//cout<<child1->nodeType<<"  asm_1 "<<child1->nodeID<<check_type_info[child1->check_type]<<endl;
			//cout<<child2->nodeType<<"  asm_2 "<<child2->nodeID<<check_type_info[child2->check_type]<<endl;
			cout<<"\tmovl "<<toStr(child1)<<", "<<toStr(child2)<<endl;
		}
		else 
		{
			//cout<<child2->nodeType<<"  asm_3 "<<check_type_info[child2->check_type]<<endl;
			cout<<"\tmovl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			//cout<<child1->nodeType<<"  asm_4 "<<check_type_info[child1->check_type]<<endl;
			cout<<"\tmovl %eax, ";
			toStr(child1);
			cout<<endl;
		}
		break;
		case OP_mod:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\txorl %ebx, %ebx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %eax"<<endl;
			cout<<"\tmovl ";
			toStr(child2);
			cout<<", %ebx"<<endl;
			cout<<"\tidivl %ebx"<<endl;
			cout<<"\tmovl %edx, ";
			toStr(node);
			cout<<endl;
			break;
		}
		case OP_pre_inc:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %eax"<<endl;
			cout<<"\taddl $1, %eax"<<endl;
			cout<<"\tmovl %eax, ";
			toStr(child1);
			cout<<endl;
			cout<<"\tmovl %eax, ";
			toStr(node);
			cout<<endl;
			break;
		}
		case OP_pre_dec:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %eax"<<endl;
			cout<<"\tsubl $1, %eax"<<endl;
			cout<<"\tmovl %eax, ";
			toStr(child1);
			cout<<endl;
			cout<<"\tmovl %eax, ";
			toStr(node);
			cout<<endl;
			break;
		}
		case OP_lt:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tcmpl %eax, %edx"<<endl;
			if(node->label.true_label.size()!=0)
			{
				cout<<"\tjl "<<node->label.true_label<<endl;
			}
			if(node->label.false_label.size()!=0)
			{
				cout<<"\tjmp "<<node->label.false_label<<endl;
			}
			if(node->sibling!=nullptr&&node->sibling->nodeType==NODE_EXPR&&node->sibling->label.true_label.size()!=0)
			{
				if(node->label.true_label==node->sibling->label.true_label)
				cout<<node->label.false_label<<":"<<endl;
				else if(node->label.false_label==node->sibling->label.false_label)
				cout<<node->label.true_label<<":"<<endl;
			}
			break;
		}
		case OP_gt:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tcmpl %eax, %edx"<<endl;
			if(node->label.true_label.size()!=0)
			{
				cout<<"\tjg "<<node->label.true_label<<endl;
			}
			if(node->label.false_label.size()!=0)
			{
				cout<<"\tjmp "<<node->label.false_label<<endl;
			}
			if(node->sibling!=nullptr&&node->sibling->nodeType==NODE_EXPR&&node->sibling->label.true_label.size()!=0)
			{
				if(node->label.true_label==node->sibling->label.true_label)
				cout<<node->label.false_label<<":"<<endl;
				else if(node->label.false_label==node->sibling->label.false_label)
				cout<<node->label.true_label<<":"<<endl;
			}
			break;
		}
		case OP_le:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tcmpl %eax, %edx"<<endl;
			if(node->label.true_label.size()!=0)
			{
				cout<<"\tjle "<<node->label.true_label<<endl;
			}
			if(node->label.false_label.size()!=0)
			{
				cout<<"\tjmp "<<node->label.false_label<<endl;
			}
			if(node->sibling!=nullptr&&node->sibling->nodeType==NODE_EXPR&&node->sibling->label.true_label.size()!=0)
			{
				if(node->label.true_label==node->sibling->label.true_label)
				cout<<node->label.false_label<<":"<<endl;
				else if(node->label.false_label==node->sibling->label.false_label)
				cout<<node->label.true_label<<":"<<endl;
			}
			break;
		}
		case OP_ge:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tcmpl %eax, %edx"<<endl;
			if(node->label.true_label.size()!=0)
			{
				cout<<"\tjge "<<node->label.true_label<<endl;
			}
			if(node->label.false_label.size()!=0)
			{
				cout<<"\tjmp "<<node->label.false_label<<endl;
			}
			if(node->sibling!=nullptr&&node->sibling->nodeType==NODE_EXPR&&node->sibling->label.true_label.size()!=0)
			{
				if(node->label.true_label==node->sibling->label.true_label)
				cout<<node->label.false_label<<":"<<endl;
				else if(node->label.false_label==node->sibling->label.false_label)
				cout<<node->label.true_label<<":"<<endl;
			}
			break;
		}
		case OP_eq:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tcmpl %eax, %edx"<<endl;
			if(node->label.true_label.size()!=0)
			{
				cout<<"\tje "<<node->label.true_label<<endl;
			}
			if(node->label.false_label.size()!=0)
			{
				cout<<"\tjmp "<<node->label.false_label<<endl;
			}
			if(node->sibling!=nullptr&&node->sibling->nodeType==NODE_EXPR&&node->sibling->label.true_label.size()!=0)
			{
				if(node->label.true_label==node->sibling->label.true_label)
				cout<<node->label.false_label<<":"<<endl;
				else if(node->label.false_label==node->sibling->label.false_label)
				cout<<node->label.true_label<<":"<<endl;
			}
			break;
		}
		case OP_nz:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\txorl %edx, %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %edx"<<endl;
			cout<<"\tmovl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tcmpl %eax, %edx"<<endl;
			if(node->label.true_label.size()!=0)
			{
				cout<<"\tjne "<<node->label.true_label<<endl;
			}
			if(node->label.false_label.size()!=0)
			{
				cout<<"\tjmp "<<node->label.false_label<<endl;
			}
			if(node->sibling!=nullptr&&node->sibling->nodeType==NODE_EXPR&&node->sibling->label.true_label.size()!=0)
			{
				if(node->label.true_label==node->sibling->label.true_label)
				cout<<node->label.false_label<<":"<<endl;
				else if(node->label.false_label==node->sibling->label.false_label)
				cout<<node->label.true_label<<":"<<endl;
			}
			break;
		}
		case OP_plus_assign:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %eax"<<endl;
			cout<<"\taddl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tmovl %eax, ";
			toStr(child1);
			cout<<endl;
			break;
		}
		break;
		case OP_minus_assign:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %eax"<<endl;
			cout<<"\tsubl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tmovl %eax, ";
			toStr(child1);
			cout<<endl;
			break;
		}
		case OP_times_assign:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %eax"<<endl;
			cout<<"\timull ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tmovl %eax, ";
			toStr(child1);
			cout<<endl;
			break;
		}
		case OP_over_assign:
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\tmovl ";
			toStr(child1);
			cout<<", %eax"<<endl;
			cout<<"\tidivl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tmovl %eax, ";
			toStr(child1);
			cout<<endl;
			break;
		}
		break;
		default:
		cout<<node->nodeID<<" "<<node->nodeType<<" not defined";
	}
	}
	else if(node->nodeType==NODE_UNARY_EXPR)
	{
		if(child1->optype==OP_uminus)
		{
			cout<<"\txorl %eax, %eax"<<endl;
			cout<<"\tmovl ";
			toStr(child2);
			cout<<", %eax"<<endl;
			cout<<"\tnegl ";
			cout<<" %eax"<<endl;
			cout<<"\tmovl %eax, ";
			toStr(node);
			cout<<endl;
		}
		else if(child1->optype==OP_opposite)
		return;
	}
    if(node->sibling!=nullptr&&node->sibling->nodeType!=NODE_BLOCK)
	recursive_gen_code(node->sibling);
}
void TreeNode::gen_code()
{
	gen_header();
	TreeNode *t=root->child;
	if(t!=nullptr)
	gen_decl(t);
	cout<<endl<<endl<<"# your asm code here" << endl;
	cout<<"\t.text"<<endl;
	recursive_gen_code(t);//直接认为是main函数的开始，先没考虑全局变量
	// if(root->label.next_label!="")
	// out<<root->label.next_label<<":"<<endl;
	// out<<"\tret"<<endl;
	cout<<"\t"<<R"(.section  .note.GNU-stack,"",@progbits)";
}
char* TreeNode::toStr(TreeNode *node)
{
	char str[20]={0};
	if(node==nullptr)
	return NULL;
	if(node->nodeType==NODE_VAR)
	{
		cout<<node->var_name;
		//sprintf(str,"%s",node->var_name);
		//cout<<str;
		return NULL;
	}
	if(node->nodeType==NODE_CONST)
	{
		//cout<<node->check_type<<endl;
		if(node->check_type==IntegerT)
		{
			sprintf(str,"$%d",node->int_val);
			cout<<str;
			//return str;
			//cout<<node->int_val<<endl;
			return NULL;
		}
		else if(node->check_type==CharT)
		{
			//cout<<node->ch_val<<endl;
			sprintf(str,"%d",node->ch_val);
			cout<<str;
			return NULL;
		}
		else
		return NULL;
	}
	if(node->nodeType==NODE_EXPR)
	{
		if(node->temp_var==-1)
		{
			node->temp_var=temp_var_count;
			temp_var_count++;
		}
		cout<<"t"<<node->temp_var;
	}
	if(node->nodeType==NODE_UNARY_EXPR)
	{
		if(node->temp_var==-1)
		{
			node->temp_var=temp_var_count;
			temp_var_count++;
		}
		cout<<"t"<<node->temp_var;
	}
	return NULL;
}