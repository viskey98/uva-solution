#include<iostream>
#include<cstring>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j) for(i=j;i>=0;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
using namespace std;
int coins[5]={1,5,10,25,50};
long long dp[30001];
int main()
{
	int n,i,j;
	memset(dp,0,sizeof dp);
		dp[0]=1;
		FOR0(i,5)
		FOR(j,1,30001)
		{
			if(j>=coins[i])
				dp[j]=dp[j]+dp[j-coins[i]];
		}
	while(cin>>n)
	{
		if(dp[n]>1)
		printf("There are %lld ways to produce %d cents change.\n",dp[n],n);
        else printf("There is only 1 way to produce %d cents change.\n",n);
	}
}