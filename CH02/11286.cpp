#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	map<vector<int>,int>m;
	map<vector<int>,int>::iterator it;
	vector<int>v;
	int n,temp,max,ans;
	while(1)
	{
		m.clear();
		cin>>n;
		if(n==0)break;
		while(n--)
		{
			v.clear();
			for(int i=0;i<5;i++)
			{cin>>temp;v.push_back(temp);}
		    sort(v.begin(),v.begin()+5);
			it=m.find(v);
			if(it==m.end())m[v]=1;
			else {it->second++;}
		}
		it=m.begin();
		max=it->second;
		for(;it!=m.end();it++)
			if((it->second)>max)max=it->second;
		ans=0;
		for(it=m.begin();it!=m.end();it++)
			if(it->second==max)ans+=it->second;
		cout<<ans<<endl;
	}
	return 0;
		
}