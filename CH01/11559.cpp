#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
int main()
{   
	int N,B,H,W,*p,**a,output[1000]={},i,j,k=0,cost;
	int flag1=0,flag2=0;
	while(!cin.eof())
	{
		cin>>N>>B>>H>>W;
	a=(int**)calloc(H,sizeof(int*));
	for(i=0;i<H;i++)
		a[i]=(int*)calloc(W,sizeof(int));
	p=(int*)calloc(H,sizeof(int));
	for(i=0;i<H;i++)
	  {
		cin>>p[i];
		for(j=0;j<W;j++)
	
		cin>>a[i][j];
	  }
    for(i=0;i<H;i++)
	  {  
        flag1=0,flag2=0;
	     if(N*p[i]<=B)
			 flag1=1;
		 if(flag1==1)
			 for(j=0;j<W;j++)
			 {
				if(a[i][j]>=N)
				{flag2=1;
				break;}
			 }
		 if(flag2==1&&flag1==1)
		 {   if(output[k]==0)
				 output[k]=N*p[i];
			 else
				 if(output[k]>N*p[i])
					output[k]=N*p[i]; 
		 }
         		 
	  }
	 k++;
	}
	k--;
	for(i=0;i<k;i++)
		if(output[i]==0)
		cout<<"stay home\n";
	    else
			cout<<output[i]<<"\n";
	return 0;	
		
	
}