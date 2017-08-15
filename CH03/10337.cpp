#include<iostream>
#include<cstring>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX2(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
using namespace std;
int wind[1005][11],dp[1005][11],X,n;
long plan(int mile,int alt)
{
	int i;
	if(mile==n&&alt==0)return 0;
    if(alt<0)return 1000000;
	if(alt>9)return 1000000;
	if(dp[mile][alt]!=-1)return dp[mile][alt];
	long ans= MIN3(60-wind[mile][alt]+plan(mile+1,alt+1),30-wind[mile][alt]+plan(mile+1,alt),20-wind[mile][alt]+plan(mile+1,alt-1));
	return dp[mile][alt]=ans;
}
int main()
{
	int N,i,j;
	cin>>N;
	while(N--)
	{
		memset(dp,-1,sizeof dp);
		cin>>X;
		n=(X/100);
		FOR0(i,10)
		FOR0(j,n)
		  scanf("%d",&wind[j][9-i]);
		cout<<plan(0,0)<<endl<<endl;
	}

}