#include<iostream>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j) for(i=j;i>=0;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
   int H[2002],W[2002],Mi[2002],Md[2002],i,testcases,n,curri,currd,maxi,maxd,j,k;
   scanf("%d",&testcases);
   FOR0(k,testcases)
   {
	   cin>>n;
	   FOR0(i,n)
	   scanf("%d",&H[i]);
	   FOR0(i,n)
	   {scanf("%d",&W[i]);Mi[i]=W[i];Md[i]=W[i];}
	   //LIS && LDS
	   maxi=Mi[0];maxd=Md[0];
	   FOR0(i,n)
	   {
		   curri=0;currd=0;
	     FOR0(j,i)
		 {
			 if(H[j]<H[i])
			 if(Mi[j]>curri)
			 {curri=Mi[j];Mi[i]=curri+W[i];}
		     if(H[j]>H[i])
		     if(Md[j]>currd)
		     {currd=Md[j];Md[i]=currd+W[i];}
			   maxd=MAX(Md[i],maxd);
		       maxi=MAX(Mi[i],maxi);
		 }
	   }
       if(maxi>=maxd)
		   printf("Case %d. Increasing (%d). Decreasing (%d).\n",k+1,maxi,maxd);  
		   else  printf("Case %d. Decreasing (%d). Increasing (%d).\n",k+1,maxd,maxi);
		   		   
   }
}