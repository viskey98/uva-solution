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
char ar[105][105];
vector < vi > graph(10005);
int visited[10005],n;
int dfs(int i)
{
	int j;
	visited[i]=1;
	int ans=0;
	if(ar[i/n][i%n]=='x')
		ans=1;
	FOR0(j,graph[i].size())
	{
		if(visited[graph[i][j]]!=1)
			ans+=dfs(graph[i][j]);
	}
	return ans;
}
int main()
{
	int i,k,j,t,ans;
	cin>>t;
	FOR0(k,t)
	{
		cin>>n;
		FOR0(i,n)FOR0(j,n){cin>>ar[i][j]; visited[i*n +j]=0; graph[i*n +j].clear();}	
		FOR0(i,n)FOR0(j,n)
		{
			if(ar[i][j]!='.')
			{
				if(i+1<n && ar[i+1][j]!='.')
				{
					graph[i*n + j].push_back( (i+1)*n + j);
					graph[(i+1)*n + j].push_back(i*n + j);
				}
				if(j+1<n && ar[i][j+1]!='.')
				{
					graph[i*n + j].push_back( (i)*n + j+1);
					graph[(i)*n + j+1].push_back(i*n + j);
				}
			}
		}
		ans=0;
		FOR0(i, n*n)
		{
			if(visited[i]!=1&& ar[i/n][i%n]!='.')
			{
				if(dfs(i)>0)
					ans++;
			}
		}
		printf("Case %d: %d\n",k+1,ans);
	}
}