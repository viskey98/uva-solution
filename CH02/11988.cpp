#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	string s;
	struct node*next;
};
typedef struct node Node;
Node *head,*rear,*ptr;
void insertfront(string a)
{
	Node *p=(Node*)calloc(1,sizeof(Node));
	p->s+=a;
	if(head==NULL)
	{
		head=p;
		rear=p;
	}
	else {
		p->next=head;
		head=p;
	}
}
void insertend(string a)
{
	Node *p=(Node*)calloc(1,sizeof(Node));
	p->s+=a;
	if(rear==NULL)
	{
		head=p;rear=p;
	}
	else {
		rear->next=p;
		p->next=NULL;
		rear=p;
	}
}
int main()
{
	string input,temp;
	int i,key;
	while(getline(cin,input))
	{
	   head=NULL;rear=NULL;
	   temp.clear();
	   key=0;
	   for(i=0;i<input.size();i++)
	   {
		   
		   if(input.at(i)=='[')
		   {
			   if(temp!="")
			   {if(key==0)
				   {insertend(temp);temp.clear();}
			   else if(key==1)
			       {insertfront(temp);temp.clear();}
			   else if(key==2)
			   {insertend(temp);temp.clear();}
			   }
			   key=1;
		   }
		   else if(input.at(i)==']')
		   {
			   if(temp!="")
			   {if(key==0)
				   {insertend(temp);temp.clear();}
			   else if(key==1)
			       {insertfront(temp);temp.clear();}
			   else if(key==2)
			   {insertend(temp);temp.clear();}
			   }
			   key=2;
		   }
		   else 
		   {
			   temp+=input.at(i);
		   }
		   if(i==input.size()-1)
		   {
			  if(temp!="")
			   {if(key==0)
				   {insertend(temp);temp.clear();}
			   else if(key==1)
			       {insertfront(temp);temp.clear();}
			   else if(key==2)
			   {insertend(temp);temp.clear();}
			   }
		   }
	   }
	   ptr=head;
	   while(ptr!=NULL)
	   {
		   cout<<ptr->s;
		   ptr=ptr->next;
	   }
	   cout<<endl;
	   
	}
	return 0;
		
}