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
int n,m;
vector< vi > graph(100005);	
int visited[100005]={},num[100005],low[100005];
int indegree[100005];
int counter;
vi roots,s;
void dfs(int i)
{
	visited[i]=1;
	s.pb(i);
	num[i]=low[i]=++counter;
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
		roots.pb(num[i]);
		while(1)
		{
			int v=s.back();
			visited[v]=0;
			low[v]=num[i];
			s.pop_back();
			if(v==i)break;
		}
	} 	
}
void check_indegree(int i)
{
	int j;
	FOR0(j,graph[i].size())
	{
		if(low[graph[i][j]]!=low[i])
		{
			indegree[low[graph[i][j]]]++;
		}
	}
}
int main()
{
	int t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		FOR0(i,n)
		{
			graph[i].clear();
			indegree[i+1]=0;
			visited[i]=0;
			num[i]=-1;
			low[i]=-1;
			roots.clear();
		}
		int x,y;
		FOR0(i,m)
		{
			cin>>x>>y;
			graph[x-1].pb(y-1);
		}
		counter =0;
		int ans=0;
		FOR0(i,n)
		{
			if(num[i]==-1)
				dfs(i);
		}
		FOR0(i,n)
		{
			check_indegree(i);
		}
		FOR0(i,roots.size())
		{
			if(indegree[roots[i]]==0)
				ans++;
		}
		cout<<ans<<endl;
		
	}
}