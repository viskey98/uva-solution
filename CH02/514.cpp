#include<iostream>
using namespace std;
int stack[1000],top=-1;
void push(int a)
{
	top++;
	stack[top]=a;
}
void pop()
{
	top--;
}
int Top()
{
	if(top!=-1)return stack[top];
	else return -1;	}
int isempty()
{
	if(top==-1)return 1;else return 0;
}
int main()
{
   	int i,n,p[1000];

	while(1)
	{
		cin>>n;if(n==0)break;
		while(1)
		{
		  cin>>p[0];
		  if(p[0]==0)break;
		  for(i=1;i<n;i++)
			  cin>>p[i];
		  top=-1;
		  i=1;
		  for(int j=0;j<n;j++)
		  {
			  while(p[j]>=i)
			  {
				  push(i);i++;
			  }
			  if(p[j]==Top())
				  pop();
			  else if(p[j]==i)i++;
			  else break;
		  }
		  if(i!=n+1||isempty()!=1)
			  cout<<"No\n";
		  else cout<<"Yes\n";	  
		}
		
		cout<<endl;	
		
	}
	return 0;
}