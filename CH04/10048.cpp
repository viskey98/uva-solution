#include<bits/stdc++.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
#define ff first
#define ss second
#define ninf -1000000000
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
vector<vii>mst(105);
vector<pair<int,ii>> edges;
int c,s,q;
vi rnk,parent;
int mx_edge;
int visited[105]={};
int dfs(int x, int y)
{
	visited[x]=1;
	int i;
	if(x==y)return 1;
	FOR0(i,mst[x].size())
	{
		if(!visited[mst[x][i].ss])
		{
			if(dfs(mst[x][i].ss,y))
			{
				mx_edge=MAX2(mx_edge,mst[x][i].ff);
				return 1;
			}
		}
	}
	return 0;
}
int FindSet(int i)
{
	return (parent[i]==i)? (i):(parent[i]=FindSet(parent[i]));
}
bool IsSameSet(int i , int j)
{
	if(FindSet(i)==FindSet(j))
		return true;
	else return false;
}
void UnionSet(int i , int j)
{
	if(IsSameSet(i,j))
		return;
	int x = FindSet(i);
	int y = FindSet	(j);
	if(rnk[x]>rnk[y])
		parent[y]=x;
	else 
	{
		if(rnk[x]==rnk[y])
		rnk[x]++;
		parent[y]=x;
	}
}
void kruskal()
{
	int i;
	FOR0(i,s)
	{
		pair<int,pair<int,int>> front = edges[i];
		int x = front.second.first,y=front.second.second,z=front.first;
		if(!IsSameSet(x,y))
		{
			mst[x].pb(make_pair(z,y));
			mst[y].pb(make_pair(z,x));
			UnionSet(x,y);
		}
	}
}
int main()
{
    int i,k=0;
	while(1)
	{
		k++;
		cin>>c>>s>>q;
		if(!c)break;
		int x,y,d;
		if(k!=1)cout<<endl;
		rnk.assign(c+5,0);
		parent.assign(c+5,0);
		edges.clear();
		FOR0(i,c+5)
		{
			mst[i].clear();
			parent[i]=i;
		}
		FOR0(i,s)
		{
			cin>>x>>y>>d;
			edges.pb(make_pair(d,make_pair(x,y)));
		}
		sort(edges.begin(),edges.end());
		kruskal();
		cout<< "Case #"<<k<<endl;
		FOR0(i,q)
		{
			cin>>x>>y;
			if(!IsSameSet(x,y))
				cout<< "no path\n";
			else 
			{
				memset(visited,0,sizeof visited);
				mx_edge=ninf;
				dfs(x,y);
				cout<<mx_edge<<endl;
			}
		}
	}
}