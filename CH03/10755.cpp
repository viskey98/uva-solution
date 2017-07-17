#include<iostream>
#include<cstring>
#define FOR(i,n) for(i=0;i<n;i++)
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
long long A[21][21][21];
long long calcsum(int i,int l,int j,int m, int k)
{
	long long s=0;
	s=A[l][m][k];
    if(i>0)s-=A[i-1][m][k];
	if(j>0)s-=A[l][j-1][k];
	if(i>0&&j>0)s+=A[i-1][j-1][k];
	return s;
}
int main()
{
	long long in[21][21][21],a,b,c,t,i,j,k,l,m,n,sum,ans;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		FOR(i,a)
			FOR(j,b)
				FOR(k,c)
					cin>>in[i][j][k];
		FOR(i,c)
			FOR(j,a)
				FOR(k,b)
					FOR(l,a)
						FOR(m,b)
						{
							A[j][k][i]=in[j][k][i];
							if(j>0)A[j][k][i]+=A[j-1][k][i];
							if(k>0)A[j][k][i]+=A[j][k-1][i];
							if(j>0&&k>0)A[j][k][i]-=A[j-1][k-1][i];
						}
		ans=-858993459200;		
		FOR(i,a)
			FOR(j,b)
				for(l=i;l<a;l++)
					for(m=j;m<b;m++)
					{
						sum=0;
						for(k=0;k<c;k++)
						{
							sum+=calcsum(i,l,j,m,k);
							ans=MAX(sum,ans);
							if(sum<0)sum=0;
						}
					}
				
		cout<<ans<<endl;
		if(t)cout<<endl;
	}
	
}