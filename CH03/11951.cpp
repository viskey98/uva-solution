#include<iostream>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
	int i,j,l,m,T,N,M,x;
	long K,P[100][100],maxAr,cost,p;
	cin>>T;
	FOR0(x,T)
	{
		cin>>N>>M>>K;
		//O(n^4) DP table
		FOR0(i,N)FOR0(j,M)
	    {   
		    scanf("%ld",&P[i][j]);
			if(i>0)P[i][j]+=P[i-1][j];
			if(j>0)P[i][j]+=P[i][j-1];
			if(i>0&&j>0)P[i][j]-=P[i-1][j-1];
		}
		//O(n^4) table works with complexity less than n^4 by suitable pruning
		maxAr=0; cost=0;
		FOR0(i,N)FOR0(j,M)
		{
			int mpa=(N-i)*(M-j);
			if(mpa<maxAr)break;
			FOR(l,i,N)
			{
				FOR(m,j,M)
				{	
					int area=(l-i+1)*(m-j+1);
					p=P[l][m];
					if(i>0)p-=P[i-1][m];
					if(j>0)p-=P[l][j-1];
					if(i>0&&j>0)p+=P[i-1][j-1];
					if(p>K)break;
					if(p<=K)
					{
						if(area>maxAr)
						{
							cost=p;maxAr=area;
						}
						else if(area==maxAr)
						{
							if(p<cost)cost=p;
						}
							
					}
				}
			}
		}
		printf("Case #%d: %d %ld\n",x+1,maxAr,cost);
	}
}