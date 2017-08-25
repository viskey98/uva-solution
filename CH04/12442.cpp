//O(N*t) dp type algorithm
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
using namespace std;
int graph[50002],dp[50002],dp2[50002];
int cyclestart=0,cyclelength=0;
int forward(int u)
{
	int v=graph[u];
	if(!dp[v])
	{
		dp[v]=dp[u]+1;
		forward(v);
	}
	else if(!dp2[v])
	{
		cyclestart=v;
		cyclelength=dp[u]-dp[v];
	}
	if(cyclestart)
	{
		if(cyclestart==u)cyclestart=0;
		return dp2[u]=cyclelength;
	}
	return dp2[u]=1+dp2[v];
	
}
int main()
{
	int t,k,i,n,x,y,max,cur,maxv;
	cin>>t;
	FOR0(k,t)
	{
		memset(dp,0,sizeof dp);
		memset(dp2,0,sizeof dp2);
		cin>>n;
		FOR0(i,n)
		{
			cin>>x>>y;
			graph[x]=y;
		}
		FOR(i,1,n+1)
		{
			if(!dp[i]&&!dp2[i])
			{dp[i]=1;
			forward(i);
			}
		}
		max=0,maxv=0;
		FOR(i,1,n+1)
		{
			if(dp2[i]>maxv){maxv=dp2[i];max=i;}
		}
		printf("Case %d: %d\n",k+1,max);
		
	}
	return 0;
}