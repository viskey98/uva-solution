#include<iostream>
#include<set>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
	long int n,i,k,j,temp,ans;
	multiset<long int>s;
	multiset<long int>::iterator it1,it2;
	while(1)
	{
		cin>>n;
		if(n==0)break;
		s.clear();
        ans=0;		
		FOR(i,n)
		{
			cin>>k;
			FOR(j,k)
			{
				cin>>temp;
				s.insert(temp);
			}
			it1=s.end();it1--;
			it2=s.begin();
			ans+=*it1-*it2;
			s.erase(it1);s.erase(it2);
		}
		cout<<ans<<endl;
	}
	return 0;
}