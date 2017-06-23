#include<iostream>
#include<vector>
#include<set>
#include<list>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
vector<list<int>> graph(26);
int visited[26];
void allclear()
{
	int i;
	FOR(i,26){graph[i].clear();visited[i]=0;}
}
void backtrack(int a)
{
	list<int>::iterator it1;
	if(graph[a].empty()!=1)
	it1=graph[a].begin(); 
    else it1=graph[a].end();
	while(it1!=graph[a].end())
	{
		  if(visited[*it1]!=1)
		  {
			  visited[*it1]=1;
			  backtrack(*it1);
		  }
		
		it1++;
	}
}
int main()
{
	int n,i,size,tree,acorn;
	int prev;
	cin>>n;
	string input;
	
	while(n--)
	{
		allclear();
		while(1)
		{
			cin>>input;
			if(input[0]!='*')
			{graph[input[1]-'A'].push_back(input[3]-'A');
		     graph[input[3]-'A'].push_back(input[1]-'A');}
		    else break;
		}
		cin>>input;
	 	tree=0;acorn=0;
		
	     FOR(i,input.size()){
			 if(visited[input[i]-'A']!=1)
			 {
				 visited[input[i]-'A']=1;
				 backtrack(input[i]-'A');
				 if(graph[input[i]-'A'].size())tree++;else acorn++;
			 }
			 i++;
		 }
		 cout<<"There are "<<tree<<" tree(s) and "<<acorn<<" acorn(s).\n";
		 
	}
	return 0;
	
}