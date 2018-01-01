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
vector< set<int> >graph(105);
vi articulationpt(105),	num(105),low(105),parent(105);
int counter,dfsroot,rootchildren;
void dfs(int i)
{
	num[i]=low[i]=counter++;	
	set<int>::iterator it;
	for(it=graph[i].begin();it!=graph[i].end();it++)
	{
		int v=*it;
		if(num[v]==-1)
		{	
	        parent[v]=i;
			if(i==dfsroot) rootchildren++;
			dfs(v);
			if(low[v]>=num[i])
				articulationpt[i]=1;	
			low[i]=MIN2(low[v],low[i]);
		}
		else if (v!=parent[i])
			low[i]=MIN2(num[v],low[i]);
	}
}
int main()
{
	int n , i,ans,k,a,b;
	string input;
	while(1)
	{
		cin>>n;
		if(!n)break;
		cin.ignore();
		FOR(i,1,n+1)
	    {graph[i].clear();num[i]=-1;low[i]=0;articulationpt[i]=0;parent[i]=i;}
		while(1)
		{
			input.clear();
			getline(cin,input);
			if(input=="0")break;
			if(input[1]==' ')
			{
				a=(input[0]-'0');
				k=2;
			}
			else 
			{
				a= (input[0]-'0')*10 + (input[1]-'0');
				k=3;
			}
			FOR(i,k,input.size())
				{
					if(i+1<input.size()&&input[i+1]==' ')
					{
						b= input[i]-'0';
						graph[a].insert(b);
						graph[b].insert(a);
						i+=1;
					}
					else 
					{
						if(i+1<input.size())
						b= (input[i]-'0')*10 + input[i+1]-'0';
					    else b= (input[i]-'0');
						graph[a].insert(b);
						graph[b].insert(a);
						i+=2;
					}
				}
		}
		ans=0;
		counter=0;
		dfsroot=1;
		rootchildren=0;
		dfs(1);
		articulationpt[1]=(rootchildren>1);
		FOR(i,1,n+1)
		if(articulationpt[i])ans++;
         cout<<ans<<endl;
	}
 
}