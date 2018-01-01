#include<bits/stdc++.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
#define ff first
#define ss second
#define inf 1000000000
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
vector< int > parent , rnk;
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
    int n,s,p,i,j;
	vector< vector<pair<double,int> > > graph(505);
	vector<pair<double,pair<int , int > > > edgelist;
	vii co;
	cin>>n;
	while(n--)
	{
		cin>>s>>p;
		int x,y;
		co.clear();
		rnk.clear();
		parent.clear();
		rnk.assign(p+5,0);
		parent.assign(p+5,0);
		FOR0(i,p)
		{
			scanf("%d%d",&x,&y);
			co.pb(make_pair(x,y));
			parent[i]=i;
			graph[i].clear();
		}
		edgelist.clear();
		FOR0(i,p)
		{
			FOR(j,i+1,p)
			{
				double d = sqrt(((co[i].ff-co[j].ff)*(co[i].ff-co[j].ff)) + ((co[i].ss-co[j].ss)*(co[i].ss-co[j].ss)));
				edgelist.pb(make_pair(d,make_pair(i,j)));
			}
		}
		sort(edgelist.begin(),edgelist.end());
		int nc = p;
		i =0 ;
		double out;
		pair<double ,pair<int,int>> front;
		while(nc>s)
		{
			 front = edgelist[i];
			if(!IsSameSet(front.ss.ff,front.ss.ss))
			{
				UnionSet(front.ss.ff,front.ss.ss);
				nc--;
			}
			i++;
		}
		out = front.ff;
		cout<<fixed;
		cout<<setprecision(2);
		cout<<out<<endl;	
	}
}