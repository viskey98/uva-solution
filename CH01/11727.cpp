#include<iostream>
#include<stdlib.h>
int main()
{
	int t;
	int i,*a,*b,*c,*output;
	std::cin>>t;
	a=(int*)calloc(t,sizeof(int));
	b=(int*)calloc(t,sizeof(int));
	c=(int*)calloc(t,sizeof(int));
	output=(int*)calloc(t,sizeof(int));
	for(i=0;i<t;i++)
	{
		std::cin>>a[i]>>b[i]>>c[i];
	}
	for(i=0;i<t;i++)
	{
	if((a[i]<c[i]&&c[i]<b[i])||(a[i]>c[i]&&c[i]>b[i]))
		output[i]=c[i];
	else if((a[i]<b[i]&&b[i]<c[i])||(a[i]>b[i]&&b[i]>c[i]))
		output[i]=b[i];
	else if((b[i]<a[i]&&a[i]<c[i])||(b[i]>a[i])&&(a[i]>c[i]))
		output[i]=a[i];
	}
	for(i=0;i<t;i++)
		std::cout<<"Case "<<i+1<<": "<<output[i]<<"\n";
	return 0;
}
