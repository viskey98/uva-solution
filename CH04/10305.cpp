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
#define MAX2(a,b) (a)>(b)?(a):(b)
#define MAX3(a,b,c) (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c))
#define MIN2(a,b) (a)<(b)?(a):(b)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
vector< vi > v(105);
vi out;
int visited[105];
void dfs(int i)
{
	int j;
	visited[i]=1;
	FOR0(j,v[i].size())
	{ if(visited[v[i][j]]!=1)
		   dfs(v[i][j]);
	}
	out.push_back(i);
}
int main()
{
	int i,n,m,a,b;
	while(1)
	{
		cin>>n>>m;
		out.clear();
		memset(visited,0,sizeof visited);
		if(!n)break;
		FOR0(i,n)
		v[i].clear();
		FOR0(i,m)
		{
			cin>>a>>b;
			v[a-1].push_back(b-1);
		}
		FOR0(i,n)
		{
			if(visited[i]!=1)
			   dfs(i);
		}
		FORD(i,out.size()-1,0)
		{cout<<out[i]+1;if(i!=0)cout<<" ";}
		cout<<endl;
	}
}