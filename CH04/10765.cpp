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
typedef long long ll;	
vector< set<int> > graph(10005);
multimap <int,int,greater<int> > out;
map <int,int>::iterator it;
vi artpt(10005),parent(100005),num(10005),low(10005);
int counter,root,rootchildren;
void dfs(int i)
{
	num[i]=low[i]=counter++;
	set<int>::iterator it=graph[i].begin();
	while(it!= graph[i].end())
	{
		if(num[*it]==-1)
		{
			if(i==root)rootchildren++;
			parent[*it]=i;
			dfs(*it);
			low[i]=MIN2(low[i],low[*it]);
			if(low[*it]>=num[i])
				artpt[i]++;
		}
		else if(*it != parent[i])
		{
			low[i]=MIN2(low[i],num[*it]);
		}	
		it++;
	}	
}
int main()
{
	int i,n,m,x,y,connected;
	while(1)
	{
		cin>>n>>m;
		if(!n)break;
		out.clear();
		FOR0(i,n)
		{
			graph[i].clear();
			artpt[i]=0;
			num[i]=-1;
			low[i]=-1;
			parent[i]=0;
		}
		while(1)
		{
			cin>>x>>y;
			if(x==-1)break;
			
			graph[x].insert(y);
			graph[y].insert(x);
		}
		counter=0;
		connected=0;
		FOR0(i,n)
		{
			if(num[i]==-1)
			{
				connected++;
				root=i;
				rootchildren=0;
				dfs(i);	
				artpt[root]-=1;
			}	
		}
		FOR0(i,n)
		{
			artpt[i]+=1;
		}
		FOR0(i,n)
		{
			out.insert(make_pair(artpt[i],i));
		}
		it=out.begin();
		FOR0(i,m)
		{
			cout<<it->second<<" "<<it->first+(connected-1)<<endl;
			it++;
		}
		cout<<endl;
	}
	
}