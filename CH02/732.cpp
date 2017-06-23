#include<iostream>
#include<string.h>
using namespace std;
int l;
char a[1000],b[1000],ans[1000];
void print()
{
	for(int i=0;i<2*l;i++)
	{
		if(i)cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
}
void make(int i,int o,string stack)
{
	if(i==l&&o==l)print();
	if(i<l)
	{
		ans[i+o]='i';
		make(i+1,o,stack+a[i]);
	}
	if(o<i)
	{
		ans[i+o]='o';
		if(stack[stack.size()-1]==b[o]){make(i,o+1,stack.substr(0,stack.length()-1));}
	}
}
int main()
{
	while(cin>>a)
	{
		cin>>b;
		l=strlen(a);
		cout<<"["<<endl;
		if(strlen(a)==strlen(b))
			make(0,0,"");
		cout<<"]"<<endl;
	}
	return 0;
}