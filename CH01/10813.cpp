#include<iostream>
using namespace std;
int bingo(int**a)
{
	int i,j,count=0,n;
	
	for(i=0;i<5;i++)
	{
		n=0;
		for(j=0;j<5;j++)
		{
		    if(a[i][j]==1)
				n++;
		}
		if(n==5)
			count++;
	}
	for(i=0;i<5;i++)
	{
		n=0;
		for(j=0;j<5;j++)
		{
		    if(a[j][i]==1)
				n++;
		}
		if(n==5)
			count++;
	}
	n=0;
	for(i=0;i<5;i++)
	{
	    if(a[i][i]==1)
			n++;
	}
	if(n==5)
	count++;
    n=0;
	for(i=0;i<5;i++)
	{
		if(a[i][4-i]==1)
			n++;
	}
	if(n==5)
		count++;
	if(count>=1)
		return 1;
	else 
		return 0;
	
}
int main()
{
	int t,i,j,l,m,x,num[75];
	int in[5][5],**a,flag1;
	
	cin>>t;
	scanf("%*c");
	for(i=0;i<t;i++)
	{
		a=(int**)calloc(5,sizeof(int*));
	     for(j=0;j<5;j++)
		a[j]=(int*)calloc(5,sizeof(int));
	    a[2][2]=1;
		for(l=0;l<5;l++)
		{
			for(m=0;m<5;m++)
			{
				if(l==2&&m==2)
					continue;
				cin>>in[l][m];
			}
		}
		for(x=0;x<75;x++)
			cin>>num[x];
		for(x=0;x<75;x++)
		{
			
			
		    flag1=0;	
			for(l=0;l<5;l++)
			{
				for(m=0;m<5;m++)
				{
					if(l==2&&m==2)
						continue;
					if(in[l][m]==num[x])
					{ 
				        a[l][m]=1;
						flag1=1;
					}
				}
			}
			
			if(bingo(a)==1)
				break;
			
		 
		}
		cout<<"BINGO after "<<x+1<<" numbers announced"<<endl;
		free(a);
	}
	return 0;
}