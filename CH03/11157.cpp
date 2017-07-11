#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<cmath>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
	int j,i,t,N,D;
	char a,b;
	long leap,ml,tmp,pre;
	vector<long int>dis;
	vector<char>type;
	bitset<100> used;
	cin>>t;
	FOR(j,t)
	{
		cin>>N>>D;
		dis.clear();
		type.clear();
		used.reset();
		FOR(i,N)
		{	
		  cin>>a>>b>>tmp;
		  type.push_back(a);
		  dis.push_back(tmp);
		}
		//left to right
		ml=0;
		FOR(i,N)
		{
			if(i==0)
			{
				leap=dis[i];
				pre=dis[i];
				if(type[i]=='S')
					used[i]=1;
			}
			else 
			{
				if(type[i]=='S'&&type[i-1]=='S'&&used[i-1]==1)
					continue;
				else if(type[i]=='S')
				{
					used[i]=1;
					leap=dis[i]-pre;
					pre=dis[i];
				}
				else
				{
				    leap=dis[i]-pre;
					pre=dis[i];
				}
			}
			if(ml<leap)ml=leap;
		}
		if(abs(D-pre)>ml)ml=abs(D-pre);
		//right to left
		pre=D;
		for(i=N-1;i>=0;i--)
		{
			if(!(type[i]=='S'&&used[i]==1))
			{
				leap=abs(dis[i]-pre);
				pre=dis[i];
			}
			if(ml<leap)ml=leap;	
		}
		if(pre>ml)ml=pre;
        printf("Case %d: %d\n",j+1,ml);
	}
	return 0;
}