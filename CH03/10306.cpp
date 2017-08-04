#include<iostream>
#include<cstring>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j) for(i=j;i>=0;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
int table[310][310],m,con[42],IT[42];
int take (int x, int y)
{
	if(x==0&&y==0)return 0;
	if(x<0||y<0)return 301;
	if(table[x][y]!=-1)return table[x][y];
    int i,min=301; 
	FOR0(i,m)
	{
		min=MIN2(min,take(x-con[i],y-IT[i]));
	}
	return table[x][y]=min+1;
}
int main()
{
	int i,j,x,y,n,s,ans;
	cin>>n;
	while(n--)
	{
		int count=0;
		memset(table,-1,sizeof table);
		ans=301;
		cin>>m>>s;
		FOR0(i,m)
		scanf("%d%d",&con[i],&IT[i]);
		FOR(x,0,s)FOR(y,x+1,s+1)
		{
			if(x*x+y*y==s*s)
			{ans=MIN3(ans,take(x,y),take(y,x));count++;}
		}
		if(count)
		{
		if(ans>300)printf("not possible\n");
	    else printf("%d\n",ans);
		}else printf("not possible\n");
	}
}