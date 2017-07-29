#include<iostream>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j) for(i=j;i>=0;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
	int Mi[2002],Md[2002],A[2002],n,testcases,curri,currd;
	int i,j,count;
	cin>>testcases;
	while(testcases--)
	{
		cin>>n;
		FOR0(i,n)
		cin>>A[i];
		//LIS & LDS
		FORD(i,n-1)
		{
			Mi[i]=1;
			Md[i]=1;
			curri=0;currd=0;
		   FOR(j,i+1,n)
		   {
			   if(A[j]>A[i])
		          if(Mi[j]>curri){curri=Mi[j];Mi[i]=Mi[j]+1;}
			  if(A[j]<A[i])
				  if(Md[j]>currd){currd=Md[j];Md[i]=Md[j]+1;}
				 
		   }
	    }
		
		int max=0;
		FOR0(i,n)
		{
			max=MAX(max,Md[i]+Mi[i]-1);
		}
		printf("%d\n",max);
	}	
}