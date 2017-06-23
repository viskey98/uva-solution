#include<iostream>
#include<string.h>
using namespace std;
int main()
	
{
	int round,i,j,k,flag1,stroke,l=0,output,count;
    char sol[1000],gues[1000],fil[1000],in2[1000];
	while(1)
	{
		cin>>round;	
        if(round<0)	 
        break;			
		cin>>sol;
		cin>>in2;
		k=0;
		stroke=0;
		for(i=0;i<strlen(sol);i++)
		{
			flag1=0;
			for(j=0;j<k;j++)
			{
				if(sol[i]==fil[j])
				{	flag1=1;
			        break;
				}
			}
			if(flag1!=1)
			{
				fil[k]=sol[i];
				k++;
			}	
		}
		fil[k]='\0';
		k=0;
		for(i=0;i<strlen(in2);i++)
		{
			flag1=0;
			for(j=0;j<k;j++)
			{
				if(in2[i]==gues[j])
				{	flag1=1;
			        break;
				}
			}
			if(flag1!=1)
			{
				gues[k]=in2[i];
				k++;
			}	
		}
		gues[k]='\0';
		for(j=0,count=0;j<strlen(gues);j++)
		{	
	        flag1=0;
	        for(i=0;i<strlen(fil)&&count<strlen(gues);i++)
			{
				if(fil[i]==gues[j])
				{
					flag1=1;
					count++;
					break;
				}
			}
			if(flag1!=1)
				stroke++;
			if(stroke>=7)
				break;
			
		}
		if(count==strlen(fil))
			output=1;
		else if(stroke>=7)
			output=-1;
		else 
			output=0;
		
		cout<<"Round "<<round<<"\n"; 	
		switch(output)
		{
			case 1: cout<<"You win."<<"\n";
			           break;
		    case 0:  cout<<"You chickened out."<<"\n";
			         
			          break;
		    case -1:  cout<<"You lose."<<"\n";
			          break;
			
		}
		
	}
	
	return 0;
}