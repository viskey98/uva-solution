#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool start=false;
bitset<7> fault;
string digit[10]={"YYYYYYN","NYYNNNN","YYNYYNY","YYYYNNY","NYYNNYY","YNYYNYY","YNYYYYY","YYYNNNN",
"YYYYYYY","YYYYNYY"},input[10];
int n;
void backtrack(int curr,int ele)
{
    int i,j;
    bitset<7>pre=fault;
	if(curr<n&&ele==0)return;
	if(curr==n)
	{
		start=true; cout<<"MATCH\n"; return ;
	}
	if(curr==0)
	for( i=0;i<10;i++)
	{
		
		if(start)return;
		for( j=0;j<7;j++)
		{
			if(fault[j]==1&&input[curr][j]=='Y')break;
			else if(input[curr][j]==digit[i][j])
				continue;
			else if(input[curr][j]=='N'&&digit[i][j]=='Y')
			{if(fault[j]!=1)fault[j]=1;}	
			else break;
			
		}
		if(j==7)
		{
			backtrack(curr+1,i);
		}
		
		fault=pre;
	}
	else 
	{
		for( j=0;j<7;j++)
		{
			if(fault[j]==1&&input[curr][j]=='Y')break;
			else if(input[curr][j]==digit[ele-1][j])
				continue;
			else if(input[curr][j]=='N'&&digit[ele-1][j]=='Y')
			{if(fault[j]!=1)fault[j]=1;}	
			else break;
		}
		if(j==7)
		{
			backtrack(curr+1,ele-1);
		}
		fault=pre;
		
	}
}	
int main()
{
	while(1)
	{
		cin>>n; if(!n)break;
		for(int i=0;i<n;i++)
		{
			input[i].clear();
			cin>>input[i];
		}
		start=false;fault.reset();
		backtrack(0,10);
		if(!start)cout<<"MISMATCH\n";
	}
	return 0;
}