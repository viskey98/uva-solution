#include<iostream>
#include<cstring>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
using namespace std;
int n,k,m;
long long dp[55][55];
long long count(int index,int bar)
{
	if(index==n&&bar==0)return 1;
	if(index>=n)return 0;
	if(bar<=0)return 0;
	if(dp[index][bar]!=-1) return dp[index][bar];
	int i;
	long long ans=0;
	FOR(i,1,m+1)
	{
		ans+=count(index+i,bar-1);
	}
	return dp[index][bar]=ans;
}
int main()
{
	while(cin>>n)
	{
		memset(dp,-1,sizeof dp);
		cin>>k>>m;
		cout<<count(0,k)<<endl;
	}
}