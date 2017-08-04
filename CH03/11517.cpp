#include<iostream>
#include<cstring>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j) for(i=j;i>=0;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
using namespace std;
int n,denom[101],table[10001][101],table2[20001][101];
int pay(int price,int type)
{
	if(price<=0)return 0;
	if(type>=n&&price<=0) return 0;
	else if(type>=n) return 100000;
	if(table[price][type]!=-1)return table[price][type];
	return table[price][type]= MIN(denom[type]+pay(price-denom[type],type+1),pay(price,type+1));
}
int takecoins(int price,int type)
{
	if(price==0) return 0;
	if(price<0)return 100;
    if(type>=n&&price==0) return 0;
	else if(type>=n)return 100;
	if(table2[price][type]!=-1)return table2[price][type];
	return table2[price][type]=MIN(1+takecoins(price-denom[type],type+1),takecoins(price,type+1));
}
int main()
{
	int i,testcases,price,ans,coin;
	cin>>testcases;
	while(testcases--)
	{
		memset(table,-1,sizeof table);
		memset(table2,-1,sizeof table2);
		cin>>price;
		cin>>n;
		FOR0(i,n)
		scanf("%d",&denom[i]);
		ans=pay(price,0);
		coin=takecoins(ans,0);
		cout<<ans<<" "<<coin<<endl;
	}
}