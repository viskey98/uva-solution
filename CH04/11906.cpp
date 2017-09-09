#include<iostream>
#include<cstring>
#include<queue>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
using namespace std;
int X[4]={1,-1,1,-1},m,n,r,c;
int Y[4]={1,-1,-1,1};
int visited[105][105],grid[105][105];
queue<pair<int,int>>q;
void explore(int x,int y)
{
	int i,j,up=4;
	if(visited[x][y])return;
	visited[x][y]=1;
	if(!m||!n)up=2;
	for(i=0;i<up;i++)
	{
		if((x+m*X[i]>=0&&x+m*X[i]<r)&&(y+n*Y[i]>=0&&y+n*Y[i]<c)&&(grid[x+m*X[i]][y+n*Y[i]]!=-1))
		{
		grid[x+m*X[i]][y+n*Y[i]]++;
		if(!visited[x+m*X[i]][y+n*Y[i]])
			q.push(make_pair(x+m*X[i],y+n*Y[i]));
		}
	}
	if(m!=n)
	for(i=0;i<up;i++)	
	{
		if((x+n*X[i]>=0&&x+n*X[i]<r)&&(y+m*Y[i]>=0&&y+m*Y[i]<c)&&(grid[x+n*X[i]][y+m*Y[i]]!=-1))
		{
		grid[x+n*X[i]][y+m*Y[i]]++;
		if(!visited[x+n*X[i]][y+m*Y[i]])
			q.push(make_pair(x+n*X[i],y+m*Y[i]));
		}
	}
	while(!q.empty())
	{
		int a,b;
		a=q.front().first;
		b=q.front().second;
		q.pop();
		explore(a,b);
	}
}
int main()
{
	int t,k,i,j,w,x,y,even,odd;
	cin>>t;
	FOR0(k,t)
	{
		memset(visited,0,sizeof visited);
	    memset(grid,0,sizeof grid);
		cin>>r>>c>>m>>n;
		cin>>w;
		FOR0(i,w)
		{
			cin>>x>>y;
			grid[x][y]=-1;
		}
		explore(0,0);
		even=0;odd=0;
		FOR0(i,r)FOR0(j,c)
		{
			if(grid[i][j]!=-1&&(grid[i][j]!=0||visited[i][j]==1))
			{
				if(grid[i][j]%2==0)even++;
				else odd++;
			}
		}
		printf("Case %d: %d %d\n",k+1,even,odd);
	}
}