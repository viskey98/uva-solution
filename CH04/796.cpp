#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bits/stdc++.h>
#include<queue>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
int n;
vector< set<int> > graph(100005);
vi parent(100005),low(100005),num(100005);
int counter;
set< ii > out;
void dfs(int i)
{
	low[i]=num[i]=counter++;
	set<int>::iterator it= graph[i].begin();
	while(it!=graph[i].end())
	{
		if(num[*it]==-1)
		{
			parent[*it]=i;
			dfs(*it);
			if(low[*it]>num[i])
			{
				if(i<*it)
				out.insert( make_pair(i,*it));
			    else out.insert( make_pair(*it,i));
			}
			low[i]=MIN2(low[i],low[*it]);
			
		}
		else if(*it!=parent[i])
		{
			low[i]=MIN2(low[i],num[*it]);
		}
		it++;
	}
}
int main()
{
	int i,k,net,temp,s;
	string in;
	while(cin>>n)
	{	
		cin.ignore();
		counter=0;
		out.clear();
		FOR0(i,n)
		{graph[i].clear();
		  parent[i]=0;
		  low[i]=-1;
		  num[i]=-1;
		}
	    FOR0(k,n)
		{
			cin>>net;
			cin>>in;
			if(in.size()==3)
				s=in[1]-'0';
			else s= (in[1]-'0')*10 + in[2]-'0';
			FOR0(i,s)
			{
				cin>>temp;
				graph[net].insert(temp);
				graph[temp].insert(net);
			}
		}
		FOR0(i,n)
		{
			if(num[i]==-1)
			dfs(i);	
		}
		
		cout<<out.size()<<" critical links\n";
		set< ii >::iterator it=out.begin();
		while(it!=out.end())
		{
			printf("%d - %d\n",it->first,it->second);
			it++;
		}
		cout<<endl;
	}
}