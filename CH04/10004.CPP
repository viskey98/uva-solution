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
vector< vi > v(205);
int ar[205];
int dfs( int i)
{
	int j;
	FOR0(j,v[i].size())
	{   
        if(ar[v[i][j]]==-1)
	    {ar[v[i][j]]= 1-ar[i]; 
	        if(dfs(v[i][j])==0)
				return 0;
		}
		else 
		{
			if(ar[v[i][j]]==ar[i])
				return 0;
		}
	}
	return 1;	
}
int main()
{
	int i,j,n,l,a,b;
	while(1)
	{
		memset(ar,-1,sizeof ar);
		FOR0(i,201)
		v[i].clear();
		cin>>n;
		cin>>l;
		if(!n)break;
		FOR0(i,l)
		{
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		ar[0]=0;
		FOR0(i,n)
		{
			if(dfs(i)==0)
				break;	
		}
		if(i!=n)
			cout<<"NOT BICOLORABLE.\n";
		else cout<<"BICOLORABLE.\n";
	}
	return 0;
 
}