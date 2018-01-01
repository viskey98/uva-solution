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
vector< vector<int> > graph(405);
int visited[405];
char ar[25][25];
int pos,hit=0;
int dfs(int i)
{
	visited[i]=1;
	int ans=1;
	int j;
	if(i==pos)hit=1;
	int x=graph[i].size();
	FOR0(j,x)
	{
		if(visited[graph[i][j]]!=1)
		ans+=dfs(graph[i][j]);
	}
	return ans;
}
int main()
{
	int m,n,x,y,i,j,size,ans;
	char land;
	while(cin>>m)
	{
	    ans=0;
		cin>>n;
		FOR0(i,m)FOR0(j,n){cin>>ar[i][j];visited[i*n + j]=0;graph[i*n +j].clear();}
		cin>>x>>y;
		pos= x*n + y;
		land=ar[x][y];
	    FOR0(i,m)
			FOR0(j,n)
			{
				if(ar[i][j]==land)
				{
					if(i+1<m&&ar[i+1][j]==land)
					{graph[n*i + j].push_back(n*(i+1) + j);
				     graph[n*(i+1) + j].push_back(n*i + j);
				    }
					if(j+1<n && ar[i][j+1]==land)
					{
						graph[n*i + j].push_back(n*i + j+1);
						graph[n*i + j+1].push_back(n*i + j);
					}
					else if(j+1==n && ar[i][0]==land)
					{
						graph[n*i + j].push_back(n*i );
						graph[n*i].push_back(n*i + j);
					}
				}
			}
	    FOR0(i,m)
		    FOR0(j,n)		
			if(visited[i*n + j]!=1&& ar[i][j]==land)
			{
				size=0;
				hit=0;
				size= dfs(i*n + j);
				if(hit!=1)
				ans= MAX2(ans,size);
			}	
		cout<<ans<<endl;
	}
}