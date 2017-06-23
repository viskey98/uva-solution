#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	double dp,loan,value,*dep,owe; // declaration of variables , dp - downpayment , loan, value , dep- depreviation , owe- money owed ;
	int i,j,k=0,nd,du,*dep0; 
	int temp,prev,count=0,output[100];
	do
	{
		cin>>du;
		if(du<0)	
			break;
		dep=(double*)calloc(du,sizeof(double));
		cin>>dp>>loan>>nd;
		dep0=(int*)calloc(nd,sizeof(double));
		
		for( i=0;i<nd;i++)
		{
			cin>>temp;
			cin>>dep[temp];
			dep0[i]=temp;
		
		}
		for(i=0;i<nd;i++)
		{
			for(j=dep0[i];j<du;)
			{	
		      dep[j]=dep[dep0[i]];
			  j++;
			  if(i!=nd-1&&j<dep0[i+1])
				  continue;
			  else if(i==nd-1)
				  continue	;
			  else if(j>=dep0[i+1])
				  break;
			  
			  
			}  
		
		}
		owe=loan;
		value=loan+dp;	
		value=value*(1-dep[0]); 	
		if(value>owe)
		{output[k]=0;
	      
		}
		for(i=1;i<=du;)
		else
		{   
			value*=(1-dep[i]);
			owe-=loan/du;
			i++;
			if(value>owe)
			{output[k]=i-1;
		     break;
			}
			
		}
		k++;
		
	}while(du>0);
	
	for(i=0;i<k;i++)
	{
		if(output[i]==1)
			printf("%d month\n",output[i]);
		else 
			printf("%d months\n",output[i]);
	}
	return 0;
}