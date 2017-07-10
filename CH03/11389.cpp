#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int temp,i,n,d,r,cost;
	vector<int>morn,nite;
	while (1)
	{
		cost=0;
		cin>>n>>d>>r;
		if(n==0)break;
		morn.clear();
		for(i=0;i<n;i++)
		{cin>>temp;morn.push_back(temp);}
	    nite.clear();
		for(i=0;i<n;i++)
		{cin>>temp;nite.push_back(temp);}
	    sort(morn.begin(),morn.end());
		sort(nite.begin(),nite.end());
		for(i=0;i<n;i++)
		{
			temp=(morn[i]+nite[n-i-1]-d);
			if(temp>0)cost+=r*temp;
		}
		cout<<cost<<endl;
	}
	return 0;
}