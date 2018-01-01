#include<bits/stdc++.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
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
vii cd;
vector<vector<pair<double,int>>> graph(1005);
vector<int> parent,rnk;
int visited[1005]={};
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
int main()
{
   std::ios::sync_with_stdio(false);
	int t,k;
	cin>>t;
	FOR0(k,t)
	{
		int i,j,n;
		double r;
		cin>>n>>r;
		int x,y;
		cd.clear();
		rnk.clear();
		parent.clear();
		rnk.assign(n,0);
		parent.assign(n,0);
		FOR0(i,n)
		{
			cin>>x>>y;
			cd.pb(make_pair(x,y));
			parent[i]=i;
			visited[i]=0;
			graph[i].clear();
		}
		FOR0(i,n)
		FOR(j,i+1,n)
		{
			double dis = sqrt(((cd[i].ff-cd[j].ff)*(cd[i].ff-cd[j].ff))+((cd[i].ss-cd[j].ss)*(cd[i].ss-cd[j].ss)));
			graph[i].pb(make_pair(dis,j));
			graph[j].pb(make_pair(dis,i));
		}
		FOR0(i,n)
		{
			FOR0(j,graph[i].size())
			{
				if(graph[i][j].ff<=r&&!IsSameSet(i,graph[i][j].ss))
				{
					UnionSet(i,graph[i][j].ss);
				}
			}
		}
		set<int>tmp;
		FOR0(i,n)
		{
			tmp.insert(FindSet(i));
		}
		int nstates=tmp.size();double roaddis=0,raildis=0;
		multiset<pair<double,int>> pq;
		multiset<pair<double,int>>::iterator it;
		pq.insert(make_pair(0,0));
		while(pq.size())
		{
			it=pq.begin();
			if(!visited[it->ss])
			{
				visited[it->ss]=1;
			if((it->first)<=r)
			roaddis+= (it->first);
		    else raildis += (it->first);
			FOR0(i,graph[it->second].size())
			{
				if(!visited[graph[it->second][i].ss])
				{pq.insert(graph[it->second][i]);}
			}
			}
			pq.erase(it);
		}
		cout<<"Case #"<<k+1<<": "<<nstates<< " "<<round(roaddis)<<" "<<round(raildis)<<endl;
	} 
}