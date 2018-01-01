#include<bits/stdc++.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
#define ff first
#define ss second
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
vi rnk,parent;
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
vector<pair<int,ii>>edges;
int main()
{
   int n,m,i;
   while(1)
   {
	   cin>>n>>m;
	   if(!n)break;
	   parent.clear();rnk.clear();
	   parent.assign(n+5,0);
	   rnk.assign(n+5,0);
	   int u,v,w;
	   FOR0(i,n+1)
	   {
		   parent[i]=i;
	   }
	   edges.clear();
	   FOR0(i,m)
	   {
		   cin>>u>>v>>w;
		   edges.pb(make_pair(w,make_pair(u,v)));
	   }
	   sort(edges.begin(),edges.end());
	   vi mce;
	   mce.clear();
	   FOR0(i,m)
	   {
		   pair<int,ii>front = edges[i];
		   int x = front.second.first,y=front.second.second,z= front.first;
		   if(!IsSameSet(x,y))
		   {
			   UnionSet(x,y);
		   }
		   else 
		   {
			   mce.pb(z);
		   }
	   }
	   if(!mce.size())
	   cout<< "forest\n";
       else 
	   {
		   sort(mce.begin(),mce.end());
		   FOR0(i,mce.size())
		   {
			   cout<<mce[i];if(i!=mce.size()-1)cout<< " ";
		   }
		   cout<<endl;
	   }
   }
}