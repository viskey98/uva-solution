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
#define pb push_back
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector< pair<int,int> > vii;
typedef long long ll;
vi low,num;
int visited[2005];
int counter ;
vi s;
vector < vi > graph(2005);
void dfs(int i)
{
	s.pb(i);
	num[i]=low[i]=++counter ;
	visited[i]=1;
	int j;
	FOR0(j,graph[i].size())
	{
		if(num[graph[i][j]]==-1)
			dfs(graph[i][j]);
		if(visited[graph[i][j]])
			low[i]=MIN2(low[i],low[graph[i][j]]);
	}
	if(num[i]==low[i])
	{
		while(1)
		{
		int v = s.back();
		visited[v]=0;
		low[v]=num[i];
		s.pop_back();
		if(v==i)break;
		}
	}
}
int main()
{
	int i, n,m,x,y,way;
	while(1)
	{
		low.clear();
		num.clear();
		cin>>n>>m;
		if(!n)break;
		vi temp;
		FOR0(i,n+1)
		{
			low.pb(-1);
			num.pb(-1);
			visited[i]=0;
			graph[i].clear();
		}
		FOR0(i,m)
		{
			cin>>x>>y>>way;
				graph[x-1].pb(y-1);
			    if(way==2)
					graph[y-1].pb(x-1);
		}
		counter =0;
		FOR0(i,n)
		{
			if(num[i]==-1)
			dfs(i);
		}
		int t= low[0];
		FOR(i,1,n)
		{
			if(t!=low[i])
				break;
		}
		if(i==n)
			cout<<1<<endl;
		else cout<<0<<endl;
	}
}