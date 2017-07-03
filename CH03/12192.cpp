#include<iostream>
#include<vector>
#include<algorithm>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int l,r,n,m;
vector <vector<int>> land;
int liesin(int a)
{
	if(a>=l&&a<=r)
		return 1;
	else return 0;
}
int grapevine()
{
	int size,ans=0,prev;
	vector<int>::iterator it;
	for(int i=0;i<n;i++)
	{
	
	it=lower_bound(land[i].begin(),land[i].end(),l);
	int low=it-land[i].begin();
	size=m-low;
	if(size>(n-i))size=(n-i);
	for(;size>=1;size--)
	{
		if(liesin(land[i+size-1][low+size-1]))
		{if(size>ans)ans=size;}
	}
	if(low==0) break;
	}	
	return ans;
	
}
int main()
{
	int i,j,temp,ans,q;
	vector<int>tv;
	
	while(1)
	{
	cin>>n>>m;
	land.clear();
	if(n==0) break;
	FOR(i,n)
	{
		tv.clear();
		FOR(j,m)
		{
			cin>>temp;
			tv.push_back(temp);
		}
		land.push_back(tv);
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		ans=grapevine();
		cout<<ans<<endl;
	}
	cout<<"-"<<endl;
	}
	return 0;
}