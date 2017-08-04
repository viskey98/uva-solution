#include<iostream>
#include<cstring>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j) for(i=j;i>=0;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
using namespace std;
int m,n;
int table[10201][101];
int f[101],p[101];
int take(int value,int index)
{
	if(value>m&&m<=1800)return -1000;
	if(value>m+200)return -1000;
	if(index==n)
	{
		if(value>m)
	    {
		if(value>2000) return 0;
		else return -1000;
	    }
		return 0;
	}
	if(table[value][index]!=-1)return table[value][index];

	return table[value][index]=MAX(f[index]+take(value+p[index],index+1),take(value,index+1));
}
int main()
{
	int i,temp1,temp2,ans;
	while(cin>>m)
	{
		memset(table,-1,sizeof table);
		cin>>n;
		FOR0(i,n)
		{
			scanf("%d%d",&p[i],&f[i]);
		}
		
		ans=take(0,0);
		printf("%d\n",ans);
	}
}