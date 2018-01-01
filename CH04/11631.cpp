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
vector<vii> graph(200005);
int visited[200005]={};
int main()
{
   std::ios::sync_with_stdio(false);
   int i,n, m;
   while(1)
   {
	   cin>>m>>n;
	   if(!m)break;
	   FOR0(i,m)
	   {graph[i].clear();visited[i]=0;}
	   int x,y,z,tdis=0;
	   FOR0(i,n)
	   {
		   cin>>x>>y>>z;
		   graph[x].pb(make_pair(z,y));
		   graph[y].pb(make_pair(z,x));
		   tdis+=z;
	   }
	   set<ii>pq;
	   set<ii>::iterator it;
	   int dis=0;
	   pq.insert(make_pair(0,0));
	   while(pq.size())
	   {
		   it=pq.begin();
		   int s= it->ss;
		   int f= it->ff;
		   if(!visited[s])
		   {
			   dis+=f;
			   visited[s]=1;
			   FOR0(i,graph[s].size())
			   {
				   if(!visited[graph[s][i].ss])
				   {
					   pq.insert(graph[s][i]);
				   }
			   }
		   }
		   else 
		   pq.erase(it);
	   }
	   cout<< tdis-dis<<endl;
   }
}