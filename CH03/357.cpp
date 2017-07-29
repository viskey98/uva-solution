#include<iostream>
#include<cstring>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j) for(i=j;i>=0;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int denom[5]={1,5,10,25,50};
long long table[5][30010];
long long ways(int type , int value)
{
	if(type==5)return 0;
	if(value<0)return 0;
	if(value==0)return table[type][value]=1;
	if(table[type][value]!=-1)return table[type][value];
	
	return table[type][value]= (ways(type+1,value)+ ways(type,value-denom[type]));
}
int main()
{
	long long  n,m;
	memset (table,-1,sizeof table);
	ways(0,30000);
	while(cin>>n)
	{
		m=ways(0,n);
		if(m==1)
			printf("There is only 1 way to produce %lld cents change.\n",n);
		else printf("There are %lld ways to produce %lld cents change.\n",m,n);
	}
}