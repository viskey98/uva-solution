#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bits/stdc++.h>
#include<queue>
#include<stack>
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
vector < vi > graph(30);
vi s,visited(30),low(30),num(30);
int counter;
map< string, int > m1;
map< int , string > m2;
void dfs(int i)
{
	num[i]=low[i]=++counter;
	visited[i]=1;
	s.pb(i);
	int j;
	FOR0(j,graph[i].size())
	{
		int x=graph[i][j];
		if(num[x]==-1)
			dfs(x);
		if(visited[x])
		  low[i]=MIN2(low[i],low[x]);
	}
	if(num[i]==low[i])
	{
		while(1)
		{
			int v= s.back();
			visited[v]=0;
			cout<<m2[v];if(v!=i)cout<<", ";
			s.pop_back();
			if(v==i)break;
		}
		cout<<"\n";
	}
}
int main()
{
	int i,n,m;
	string in,temp;
	int k=0;
	cin>>n>>m;
	while(1)	
	{
		m1.clear();m2.clear();
		k++;
		if(!n)break;
		int ne=0;
		FOR0(i,n)
		{
			num[i]=-1;
			low[i]=-1;
			visited[i]=0;
			graph[i].clear();
		}
		FOR0(i,m)
		{
			cin>>in>>temp;
			if(m1.find(in)==m1.end())
			{m1[in]=ne;m2[ne]=in;ne++;}
			if(m1.find(temp)==m1.end())
			{m1[temp]=ne;m2[ne]=temp;ne++;}
			graph[m1[in]].pb(m1[temp]);
		}
		counter =0;
		printf("Calling circles for data set %d:\n",k);
		FOR0(i,n)
		{
			if(num[i]==-1)
                  dfs(i);
		}
		cin>>n>>m;
		if(n)
		cout<<"\n";
	}
}