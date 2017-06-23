#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	map<long int, long int>m;
	map<long int, long int>::iterator it;
	set<long int>s;
	set<long int>::iterator it1;
	vector<long int>v;
	long int temp,n,t,start,i;
	cin>>n;
	while(n--)
	{
		v.clear();m.clear();s.clear();
		cin>>t;
		for(i=0;i<t;i++)
		{
			cin>>temp;v.push_back(temp);
		}
		
		for(i=0;i<v.size();i++)
		{   
			it=m.find(v[i]);
			if(it==m.end())
			{
				m[v[i]]=i;
			}
			else {
				i=(it->second);
				s.insert(m.size());
				m.clear();
			}
		}
		s.insert(m.size());
		it1=s.end();it1--;
		cout<<*it1<<endl;
	}
	return 0;
}