#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
	int i,B,S,temp,t=0;
	multiset<int>bach,spin;
	multiset<int>::iterator it,it1,it2,it0;
	while(true)
	{
		t++;
		bach.clear();spin.clear();
		cin>>B>>S;
		if(!B)break;
		FOR(i,B)
		{cin>>temp;bach.insert(temp);}
        FOR(i,S)
		{cin>>temp;spin.insert(temp);}
	     it0=bach.end();
		 it0--;
	    while(spin.size()&&bach.size())
		{
			it=it0;
			if(it0!=bach.begin())
			it0--;
			it1=spin.lower_bound(*it);
			it2=it1;
			if(it1!=spin.begin())
			it2--;
			if(it1==spin.end()){spin.erase(it2);bach.erase(it);}
			else 
			{
				if(abs(*it1-*it)>abs(*it2-*it))
				{
					spin.erase(it2);
					bach.erase(it);
				}
				else {spin.erase(it1);bach.erase(it);}
				
			}
				
		}
		printf("Case %d: %d",t,bach.size());
		if(bach.size())cout<<" "<<*bach.begin()<<"\n";
		else cout<<endl;
		
	}
	return 0;
}