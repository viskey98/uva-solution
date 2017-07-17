//p108 with O(n^4) complexity
#include<iostream>
#define FOR(i,n) for(i=0;i<n;i++)
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
	int i,j,n,l,m,in[105][105],A[105][105];
	long ans,sum;
	cin>>n;
	FOR(i,n)
		FOR(j,n)
			scanf("%d",&in[i][j]);
	
    FOR(i,n)
		FOR(j,n)
		{
			A[i][j]=in[i][j];
			if(i>0)A[i][j]+=A[i-1][j];
			if(j>0)A[i][j]+=A[i][j-1];
			if(i>0&&j>0)A[i][j]-=A[i-1][j-1];
		}
	 ans=-127*100*100;
	FOR(i,n)
		FOR(j,n)
		{   
			for(l=i;l<n;l++)
				for(m=j;m<n;m++)
				{
					sum=A[l][m];
					if(i>0)sum-=A[i-1][m];
					if(j>0)sum-=A[l][j-1];
					if(i>0&&j>0)sum+=A[i-1][j-1];
					ans=MAX(sum,ans);
				}
		}
	cout<<ans<<endl;
	
}