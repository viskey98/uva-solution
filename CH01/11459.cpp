#include<iostream>
#include<stdlib.h>
using namespace std;	
int main()
{
	int *out[100],k,i,j,l,n;
	int a[100],b,c,*dr;
	int start[100],stop[100];	
	cin>>n;
	for(k=0;k<n;k++)
	{
		
		cin>>a[k]>>b>>c;
		out[k]=(int*)calloc(a[k],sizeof(int));
		dr=(int*)calloc(c,sizeof(int));	
		for(i=0;i<a[k];i++)
		{
			out[k][i]=1;
		}
		for(i=0;i<b;i++)
		{
			cin>>start[i]>>stop[i];
		}
		for(i=0;i<c;i++)
		{
			cin>>dr[i];
		}
		for(i=0,j=0;i<c;i++)
		{
			if(j>=a[k])
				j=0;
			out[k][j]+=dr[i];
			for(l=0;l<b;l++)
			{
			    if(start[l]==out[k][j])
					break;
			}
			if(l!=b)
				out[k][j]=stop[l];
			if(out[k][j]>=100)
			{
				out[k][j]=100;
				break;
			}
			j++;
		}
		
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<a[i];j++)
		cout<<"Position of player "<<j+1<<" is "<<out[i][j]<<".\n";	
	}
	return 0;
	
}
