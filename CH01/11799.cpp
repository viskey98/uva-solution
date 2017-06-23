#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int i,j,k=0,t,n,*c,output[50];
	cin>>t;
	for(i=0;i<t;i++)
	{
       		cin>>n;
			c=(int*)calloc(n,sizeof(int));
			for(j=0;j<n;j++)
				cin>>c[j];
			output[k]=c[0];
			for(j=1;j<n;j++)
			{
				if(c[j]>output[k])
					output[k]=c[j];
			}
			k++;
	}
	for(i=0;i<k;i++)
		cout<<"Case "<<i+1<<": "<<output[i]<<"\n";
	return 0;
	
}