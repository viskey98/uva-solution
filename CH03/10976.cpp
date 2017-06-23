#include<iostream>
#include<cmath>
using namespace std;
int isinteger(float a)
{
	
	if(roundf(a)==a)return 1;
	else return 0;
}
int main()
{
	int count=0,no1[10000],no2[10000],i,j,num;
	int k,x,y;
	while(cin>>k)
	{
		i=0;
		for(x=k+1;x<=2*k;x++)
		{
			y=((k*x)/(x-k));
			if((k*x)%(x-k)==0){no1[i]=y;no2[i]=x;i++;}
		}
		cout<<i<<endl;
		for(j=0;j<i;j++)
			printf("1/%d = 1/%d + 1/%d\n",k,no1[j],no2[j]);
	}
	return 0;
}