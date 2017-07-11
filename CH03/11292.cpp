#include<iostream>
#include<set>
#include<algorithm>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
	int i,n,m,dr[20001],temp,ans;
	multiset<int>kn;
	multiset<int>::iterator it;
	while(true)
	{
		ans=0;kn.clear();
		cin>>n>>m;
		if(n==0)break;
		FOR(i,n)
		cin>>dr[i];
	    FOR(i,m)
		{cin>>temp;kn.insert(temp);}
        if(n>m)i=0;
		else
		FOR(i,n)
		{
			it=kn.lower_bound(dr[i]);
			if(it!=kn.end()&&(*it)>=dr[i])
			{
				ans+=*it;
				kn.erase(it);
			}
			else break;
		}
		if(i==n)
		    cout<<ans<<endl;
		else cout<<"Loowater is doomed!"<<endl;
	
	}
	return 0;
}