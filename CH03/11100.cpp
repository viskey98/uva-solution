#include<iostream>
#include<map>
#include<vector>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
	int i,n,temp,max;
    map<long int,int>bag;
	map<long int,int>::iterator it;
	vector<vector<long int>> out;
	vector<long int> t;
	cin>>n;
    while(true)
	{
		out.clear();bag.clear();
		max=1;
		FOR(i,n)
		{
			cin>>temp;
			it=bag.find(temp);
			if(it==bag.end())
			bag[temp]=1;
		    else 
			{it->second+=1;
			if(it->second>max)max=it->second;
			}
		}
		t.clear();
		FOR(i,max)
		{
			out.push_back(t);
		}
		i=0;
		for(it=bag.begin();it!=bag.end();it++)
		{
			while(it->second>0)
			{
				out[i].push_back(it->first);
				it->second-=1;
				i++;
				if(i==max)i=0;
			}
		}
		cout<<max<<endl;
		FOR(i,max)
		{
			for(int j=0;j<out[i].size();j++)
			{cout<<out[i][j];if(j!=out[i].size()-1)cout<<" ";}
		    cout<<endl;
		}
		cin>>n;
		if(n)
		cout<<endl;
	    else break;
	}
	
	
}