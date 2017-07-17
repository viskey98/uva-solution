//p10827 with O(n^3) complexity 
#include<iostream>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
	int i,j,N,start,end,A[75][75][75],t;//A[row][startcol][endcol]
	long totsum,currsum,negsum,maxsum;
	cin>>t;
	while(t--)
	{
	cin>>N;
	FOR0(i,N)FOR0(j,N)
	cin>>A[i][j][j];
	
	FOR0(i,N)
	FOR0(start,N)
	{
		FOR(end,start+1,N)
			A[i][start][end]=A[i][start][end-1]+A[i][end][end];
		FOR(end,0,start)
			A[i][start][end]=A[i][start][N-1]+A[i][0][end];
	}
	maxsum=-127*N*N;
	FOR0(start,N)
	FOR0(end,N)
	{
		currsum=0; totsum=0;
		bool pos=false,neg=false;
		FOR0(i,N)
		{
			int curr=A[i][start][end];
			currsum+=curr;
			totsum+=curr;
			if(curr<0)neg=true;
			else pos=true;
			maxsum=MAX(maxsum,currsum);
			if(currsum<0)currsum=0;
		}
		negsum=-127*N*N;
		if(pos&&neg)
		{
			currsum=0;
			FOR0(i,N)
			{
				int curr=A[i][start][end];
				currsum-=curr;
				negsum=MAX(negsum,currsum);
				if(currsum<0)currsum=0;
			}
		}
		maxsum=MAX(maxsum,totsum+negsum);	
	}
	cout<<maxsum<<endl;
	}
	return 0;
}