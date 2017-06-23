#include<iostream>
#include<set>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
	long int i,n,m,temp,ans;
	set<long int> s;
	while(1)
	{
		cin>>n>>m;
		if(n==0)break;
		s.clear();
		ans=0;
		FOR(i,n)
		{
			cin>>temp;
			s.insert(temp);
		}
		FOR(i,m)
		{
			cin>>temp;
			if(s.find(temp)!=s.end())
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}