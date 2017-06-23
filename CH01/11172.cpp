#include<iostream>
#include<stdlib.h>
int main()
{
	int t, *a,*b,i;
	std::cin>>t;
	a=(int*)calloc(t,sizeof(int));
	b=(int*)calloc(t,sizeof(int));
	for(i=0;i<t;i++)
		std::cin>>a[i]>>b[i];
	for(i=0;i<t;i++)
	{	if(a[i]<b[i])
			std::cout<<'<'<<"\n";
		else if(a[i]>b[i])
			std::cout<<'>'<<"\n";
		else
			std::cout<<'='<<"\n";
	}	
	return 0;
}
