#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	string s1,s2;
	cin>>n;cin.ignore();cin.ignore();
	while(n--)
	{
		multimap<string,string> m;
		
		while(1)
		{
			s1.clear();s2.clear();
		getline(cin,s1);
		if(s1.size()==0)break;
		for(int i=0;i<s1.size();i++)
			if(s1.at(i)!=' ')s2+=s1[i];
		sort(s2.begin(),s2.end());
	    m.insert(pair<string,string>(s1,s2));
		} 
		multimap<string,string>::iterator j,i;
		for(i=m.begin();i!=m.end();i++)
		{ 
			j=i;j++;
			for(;j!=m.end();j++)
			{
				if(j->second==i->second)
					cout<<i->first<<" = "<<j->first<<endl;	
			}
			
		}
		if(n)
		cout<<endl;
	}
	return 0;
}