#include<iostream>
#include<cstring>
#include<string>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
using namespace std;
int n,m,x,y;
char dir,a[4]={'L','S','O','N'};
char input[100][100];
void process(char c)
{
    int cur;
	FOR0(cur,4)if(a[cur]==dir)break;
    if(c=='D')
	{
		if(cur+1<4)cur+=1;
		else cur=0;
		dir=a[cur];
	}
	else if(c=='E')
	{
		if(cur-1>=0)cur-=1;
		else cur=3;
		dir=a[cur];
	}
	else
	{
		if(dir=='S')
		{if(x+1<n&&input[x+1][y]!='#')
		x+=1;}
		
		else if(dir=='N')
		{if(x-1>=0&&input[x-1][y]!='#')
		x-=1;}
		else if(dir=='O')
		{if(y-1>=0&&input[x][y-1]!='#')
		y-=1;}
		else {if(y+1<m&&input[x][y+1]!='#')
		y+=1;}	
	}
}
int main()
{
	int i,j,s,ans;
	char temp;
	string st;
	while(1)
	{
		cin>>n>>m>>s;
		if(!n)break;
		FOR0(i,n)FOR0(j,m)
		{
			cin>>temp;
			if(!(temp=='.'||temp=='*'||temp=='#'))
			{
				input[i][j]='.';
				dir=temp;
				x=i;y=j;
			}
			else input[i][j]=temp;
		}
		cin.ignore();
		getline(cin,st);
		ans=0;
		FOR0(i,st.size())
		{
			process(st[i]);
			if(input[x][y]=='*'){ans++;input[x][y]='.';}
		}
		printf("%d\n",ans);
	}
	return 0;
}