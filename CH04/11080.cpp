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
vector < vector<int> > graph(205);
int color[205];
int size=0;
int dfs(int i)
{
	int flag=1;
	int ans=0,temp;
	int j;
	FOR0(j,graph[i].size())
	{
		if(color[graph[i][j]]==-1)
		{ 
	        size++;
			color[graph[i][j]]=1-color[i];
			if(color[graph[i][j]]==1)ans++;
			temp=dfs(graph[i][j]);
			if(temp==-1){flag=0;break;}
			else ans+=temp;
		}
		else if(color[graph[i][j]]!=1-color[i])
		{flag=0;break;}
	}
	if(flag==0)return -1;
	else return ans;
}
int main()
{
	int i,t,v,e,F,T,ans1,ans2,ansfin,temp,flag;
	cin>>t;
	while(t--)
	{
		cin>>v>>e;
		FOR0(i,v)
		{color[i]=-1;graph[i].clear();}
		FOR0(i,e)
		{
			cin>>F>>T;
			graph[F].push_back(T);
			graph[T].push_back(F);
		}
		ansfin=0;
		temp=0;
		FOR0(i,v)
		{
			if(color[i]!=-1)continue;
			size=1;ans1=0;
			if(color[i]==-1){color[i]=1;ans1++;}
			temp=dfs(i);
			if(temp==-1)
				break;
			else ans1+=temp;
			if(size>1)
			ansfin+=MIN2(ans1,size-ans1);
		    else ansfin+=ans1;
		}
		if(i==v)
		cout<<ansfin<<endl;
	    else cout<<"-1\n";
	}
}