#include <iostream>
#include <string>
#include <sstream>
#include <sstream>
using namespace std;

struct node
{
	string data;
	node *next;
};
node* tail=NULL;
void push(string val) {
   node* newnode = new node; 
   newnode->data = val; 
   newnode->next = tail; 
   tail = newnode;
}

string pop()
{
	string op="$";
	if(tail==NULL)
	return op;
	op=tail->data;
	tail=tail->next;
	return op;
}
class evaluator{
public:
string toPostFix(string exp)
{
	
	string c;
	if(exp.empty())
	return "empty";
	string eq="";
	bool f=true;;
	string track="$";
		for(int i=0;i<exp.length();i++)
		{
		if(isalpha(exp[i]) || isdigit(exp[i])) //takes opening and push to stack
		{
			eq=eq+exp[i];
			continue;
		}
		else if(exp[i]=='(' )
		{
			c=exp[i];
			push(c);
			if(i==0)
			f=false;
			continue;
		}
		else if(track=="$"&&f)
		{
			if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*'|| exp[i]=='/')
			c=exp[i];
			push(c);
			track=exp[i];	
			continue;			
		}

		else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*'|| exp[i]=='/')
		{

			switch(exp[i])
			{
				case '*':
				case '/':
				if(track=="+"||track=="-")
				{
			c=exp[i];
			push(c);
					track=exp[i];
				}
				else
				{
					eq=eq+pop();
			c=exp[i];
			push(c);
					track=exp[i];
				}
				break;
				case '+':
				case '-':
						
					track=pop();
				while(track=="+" || track=="-" || track=="*"|| track=="/"&&track!="(")
				{
				
					eq=eq+track;
					track=pop();
				}
			c=exp[i];
			push(c);
				break;
				
			}		
		}
		}
			track=pop();
	while(track!="$")
	{
		eq=eq+track;
		track=pop();
		
	}
		cout<<"after infix to postfix "<<eq<<endl;
		return eq;			
}

int stToInt(string exp)
{
	stringstream cnv(exp);
	int x=0;
	cnv>>x;
	return x;	
}

string intToSt(int exp)
{
ostringstream ostr;
ostr << exp;
string str = ostr.str();
return str;
}

void toInfix(string exp)
{
	char a;
	string b;
	int op1,op2,res;
	for(int i=0;i<exp.length();i++)
	{//cout<<"pushing "<<exp[i]<<endl;
	
		if(isdigit(exp[i])){
			b=exp[i];
			push(b);
			continue;}
			else
			{
			switch(exp[i])
			{
			case '+':
			op2=stToInt(pop());
//			cout<<"popped"<<op2<<endl;
			op1=stToInt(pop());
//			cout<<"popped"<<op1<<endl;
			res=op1+op2;	
			b=intToSt(res);
			push(b);
		//	cout<<"adding "<<pop()<<endl;
			break;
			case '-':
			op2=stToInt(pop());
//			cout<<"popped"<<op2<<endl;
			op1=stToInt(pop());
//			cout<<"popped"<<op1<<endl;
			res=op1-op2;
			b=intToSt(res);
			push(b);
			break;
			case '*':
			op2=stToInt(pop());
//			cout<<"popped"<<op2<<endl;
			op1=stToInt(pop());
//			cout<<"popped"<<op1<<endl;
			res=op1*op2;
			b=intToSt(res);
			push(b);
//	cout<<"mul "<<res<<endl;
			break;
			case '/':
			op2=stToInt(pop());
			op1=stToInt(pop());
			res=op1/op2;
			b=intToSt(res);
			push(b);
//			cout<<"div "<<res<<endl;
			break;
			}
		}//system("pause");
		//cout<<"res"<<res<<endl;
	}	cout<<"after evaluating the postfix "<<pop();
}
}e;
int main()
{
	e.toInfix(e.toPostFix("(2+2)*5"));
	return 0;
}
