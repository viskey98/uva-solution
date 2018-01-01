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
inline long long  MIN3(long long  a, long long b, long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long ll;
vector < vi > graph(305);
int color[305];
int dfs(int i)
{
	int j;
	int ans=1;
	FOR0(j,graph[i].size())
	{
		if(color[graph[i][j]]==-1)
		{
			color[graph[i][j]]=1-color[i];
			ans=dfs(graph[i][j]);
			if(ans==0)break;
		}
		else if(color[graph[i][j]]!=1-color[i])
		{
			ans=0;break;
		}
	}
	return ans;
}
int main()
{
	int v,i,a,b,ans;
	while(1)
	{
		cin>>v;
		if(!v)break;
		FOR0(i,v+1)
		{
			color[i]=-1;
			graph[i].clear();
		}
		while(1)
		{
			cin>>a>>b;
			if(!a)break;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		color[1]=1;
		ans=dfs(1);
		if(ans==1)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	
}