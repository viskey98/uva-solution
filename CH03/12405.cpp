#include<iostream>
#include<bits/stdc++.h>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int n,ans;
bitset<100> scare;
void scarecrow(int i)
{
	if(i+1<n)scare[i+1]=1;
	scare[i-1]=1;scare[i]=1;
	ans++;
}
int main()
{
	
	string in;
	int t,i,j;
	cin>>t;
	FOR(i,t)
	{
		in.clear();
		ans=0; scare.reset();
		cin>>n>>in;
		FOR(j,n)
		{
			if(in[j]=='.'&&scare[j]==0)
			{
				if(j+1<n)scarecrow(j+1);
				else scarecrow(j);
			}
		}
		printf("Case %d: %d\n",i+1,ans);
	}
	return 0;
}