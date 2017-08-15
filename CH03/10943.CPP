#include<iostream>
#include<cstring>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
#define num 1000000
using namespace std;
long dp[105][105];
long count(int K,int N)
{
	if(K==0&&N==0)return 1;
	if(K==0&&N!=0)return 0;
	if(N<0||K<0)return 0;
	if(dp[K][N]!=-1)return dp[K][N];
	int i;
	long ans=0;
	FOR0(i,N+1)
	{
		ans=(ans+(count(K-1,N-i)%num))%num;
	}
	return dp[K][N]=ans;
}
int main()
{
	int N,K;
	while(1)
	{
		memset(dp,-1,sizeof dp);
		scanf("%d%d",&N,&K);
		if(!N)break;
		cout<<count(K,N)<<endl;
	}
	
}