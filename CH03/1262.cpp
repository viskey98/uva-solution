#include<iostream>
#include<set>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
set<char> s1[5],s2[5];
set<string>output;
string curr;
void clearall()
{
	int i;
	FOR(i,5)
	{
		s1[i].clear();s2[i].clear();
	}
}
void generate(int num)
{
	if(num==5) {output.insert(curr);return;}
	int i;
	set<char>::iterator it,it2;
	
		for(it=s1[num].begin();it!=s1[num].end();it++)
		{
			it2=s2[num].find(*it);
			if(it2!=s2[num].end())
			{
				curr+=*it;
				generate(num+1);	
				curr.pop_back();
			}
				
		}
	
}
int main()
{
	int t,k,i,j;
	set<string>::iterator it;
	string in,ans;
	cin>>t;
	while(t--)
	{
		cin>>k;
		clearall();curr.clear();
		output.clear();
		FOR(i,6)
		{
			cin>>in;
			FOR(j,in.size())
				s1[j].insert(in[j]);
		}
		FOR(i,6)
		{
			cin>>in;
			FOR(j,in.size())
				s2[j].insert(in[j]);
		}
		generate(0);
		for(it=output.begin(),j=1;it!=output.end();it++,j++)
		{
			if(j==k){ans=*it;break;}
		}
		if(it==output.end())cout<<"NO\n";
		else cout<<ans<<endl;
	}
	return 0;
}