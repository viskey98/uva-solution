#include<iostream>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
long C[1001];
int main()
{
	long i,t,n,ans,sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		FOR(i,n)
			cin>>C[i];
		sum=0;ans=0;
		for(i=0;i<n;i++)
			{
			sum+=C[i];
			if(i+1<n)
			{
				if(sum<C[i+1])ans++;
				else sum-=C[i];
			}
			else ans++;
		}	
		cout<<ans<<endl;
	}
	return 0;
}