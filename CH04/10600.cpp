#include<bits/stdc++.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
#define ff first
#define ss second
#define ninf -1000000000
#define inf 1000000000
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
int n , m;
vi visited,span;
int main()
{
	int t,a,b,c,i,j;
	vector< pair<double,pair<int , int> > >edgelist;
	
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		edgelist.clear();
		visited.clear();
		rnk.clear();
		parent.clear();
		rnk.assign(n+5,0);
		parent.assign(n+5,0);
		span.assign(n+5,0);
		visited.assign(m+5,0);
	   FOR0(i,n+5)
	   {
		   rnk[i]=0;
		   parent[i]=i;
	   }
		FOR0(i,m)
		{
			scanf("%d%d%d",&a,&b,&c);
			edgelist.pb(make_pair(c,make_pair(a,b)));
		}
		sort(edgelist.begin(),edgelist.end());
		int mst1=0,mst2=0;
		pair<int,pair<int,int> > front;
		FOR0(i,m)
		{
			front = edgelist[i];
			if(!IsSameSet(front.ss.ff,front.ss.ss))
			{
				UnionSet(front.ss.ff,front.ss.ss);
				visited[i]=1;
				mst1+=front.ff;
			}
		}
		mst2 = inf;
		FOR0(i,m)
		{
			if(visited[i]==0)
				continue;
			FOR0(j,n+5)
			{
				parent[j]=j;
				rnk[j]=0;
				span[j]=0;
			}
			int temp = 0;
			int cnt=n-1;
			FOR0(j,m)
			{
				if(j==i)continue;
				front = edgelist[j];
				if(!IsSameSet(front.ss.ff,front.ss.ss))
		     	{
					span[front.ss.ff]=1;
					span[front.ss.ss]=1;
				UnionSet(front.ss.ff,front.ss.ss);
				temp+=front.ff;
				 cnt--;
			    }
			}
			if(!cnt)
			mst2 = MIN2(mst2,temp);	
		}
		cout<<mst1<< " " <<mst2<<endl;
		
	}
}