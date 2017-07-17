//p10827 with O(n^4) complexity
#include<iostream>
#define FOR(i,n) for(i=0;i<n;i++)
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
	long N,A[80][80],in[80][80],i,j,l,m,t,x,y,sum,ans;
	cin>>t;
	while(t--)
	{ 	
		cin>>N;
		FOR(i,N)FOR(j,N)
			cin>>in[i][j];	
		FOR(i,N)FOR(j,N)
		{
			A[i][j]=in[i][j];
			if(i>0)A[i][j]+=A[i-1][j];
			if(j>0)A[i][j]+=A[i][j-1];
			if(i>0&&j>0)A[i][j]-=A[i-1][j-1];
		}
		ans=-562500;
		FOR(i,N)FOR(j,N)
		{
			for(l=i,x=0;x<N;x++){for(m=j,y=0;y<N;y++)
				{sum=0;
					if(i<=l&&j<=m)
					{
						sum+=A[l][m];
						if(i>0)sum-=A[i-1][m];
						if(j>0)sum-=A[l][j-1];
						if(i>0&&j>0)sum+=A[i-1][j-1];					
					}
					else 
					{
						if(j>m&&i>l)
						{
							sum+=A[N-1][N-1];//NORMAL BLOCK
							if(i>0)sum-=A[i-1][N-1];
						    if(j>0)sum-=A[N-1][j-1];
						    if(i>0&&j>0)sum+=A[i-1][j-1];
							sum+=A[l][m];//END point BLOCK
							sum+=A[l][N-1]-A[l][j-1];
							sum+=A[N-1][m]-A[i-1][m];							
						}
						else if(j>m)
						{
							sum+=A[l][N-1];//NORMAL BLOCK
							if(i>0)sum-=A[i-1][N-1];
						    if(j>0)sum-=A[l][j-1];
						    if(i>0&&j>0)sum+=A[i-1][j-1];
							sum+=A[l][m];//END point BLOCK
							sum-=A[i-1][m];							
						}
						else 
						{
							sum+=A[N-1][m];//NORMAL BLOCK
							if(i>0)sum-=A[i-1][m];
						    if(j>0)sum-=A[N-1][j-1];
						    if(i>0&&j>0)sum+=A[i-1][j-1];
							sum+=A[l][m];//END point BLOCK
							sum-=A[l][j-1];							
						}
					}
					ans=MAX(sum,ans);
					m++;if(m==N)m=0;
				}
				l++;if(l==N)l=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}	