#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{	
	int i,j,m,n,k=0,l;
	int mo[100],no[100];
	int **outar[100]={};
	int **out;
	char **in;
	while(1)
	{
	
	cin>>n>>m;
	if(m==0&&n==0)
		break;
	in=(char**)calloc(n,sizeof(char*));
	out=(int**)calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
	{ in[i]=(char*)calloc(m,sizeof(char));
      out[i]=(int*)calloc(m,sizeof(int));
	}
	outar[k]=out;
	mo[k]=m;
	no[k]=n;
    for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cin>>in[i][j];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{   if(in[i][j]!='*')
			{
			out[i][j]==0;
			if(j-1>=0)
			{
				if(in[i][j-1]=='*')
				    out[i][j]++;
			}
			if(j+1<m)
			{
				if(in[i][j+1]=='*')
					out[i][j]++;		
			}
			if(i-1>=0)
			{
				if(in[i-1][j]=='*')
					out[i][j]++;
				if(j-1>=0)
				{
					if(in[i-1][j-1]=='*')
					   out[i][j]++;
				}
				if(j+1<m)
				{
					if(in[i-1][j+1]=='*')
						out[i][j]++;
				}
			}
			if(i+1<n)
			{
				if(in[i+1][j]=='*')
					out[i][j]++;
				if(j-1>=0)
				{
					if(in[i+1][j-1]=='*')
					   out[i][j]++;
				}
				if(j+1<m)
				{
					if(in[i+1][j+1]=='*')
						out[i][j]++;
				}
				
			}
			
		    }
			else
				out[i][j]=-1;
		}
		
	}
	
	k++;
	
	}
	for(l=0;l<k;l++)
	{
		
	cout<<"Field #"<<l+1<<":"<<"\n";	
	for(i=0;i<no[l];i++)
	{
		for(j=0;j<mo[l];j++)
		{
			if(outar[l][i][j]!=-1)
			cout<<outar[l][i][j];
		    else
			cout<<'*';
		}
		
		cout<<"\n";
	} 
	if(l!=k-1)
	cout<<"\n";
	}
	return 0;
	
}