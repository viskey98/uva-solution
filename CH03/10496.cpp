#include<iostream>
#include<cmath>
#include<cstring>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
using namespace std;
int X[20],Y[20],table[20][2100];
int N;
int dp(int index,int visited)
{
	int i,ans=1000000,temp;
	if(visited==((1<<(N+1))-1))
		return (abs(X[index]-X[0])+abs(Y[index]-Y[0]));
	if(table[index][visited]!=-1)return table[index][visited];
	FOR(i,1,N+1)
	{
		if(!(visited&1<<i))
		{temp=abs(X[index]-X[i])+abs(Y[index]-Y[i])+dp(i,visited|1<<i);
	     ans=MIN(ans,temp);
		}
	}
	return table[index][visited]=ans;
}
int main()
{
	int i,n,ans,a,b;
	cin>>n;
	while(n--)
	{
		memset(table,-1,sizeof table);
		cin>>a>>b;
		cin>>X[0]>>Y[0];
		cin>>N;
		FOR(i,1,N+1)
			cin>>X[i]>>Y[i];
		ans=dp(0,1);
		printf("The shortest path has length ");
		cout<<ans<<endl;
	}
}