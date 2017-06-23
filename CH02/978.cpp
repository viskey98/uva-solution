#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#define MIN(a,b,c) ((a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c)))
#define FOR(i,n)  for(i=0;i<n;i++)
using namespace std;
int main()
{
	int i,n,bat,nb,ng,temp,size,f1,f2;
	multiset<int>sb,sg;
	multiset<int>::iterator it1,it2,it3;
	vector<int>b,g;
	cin>>n;
	while(n--)
	{
		sb.clear();sg.clear();
		cin>>bat>>ng>>nb;
	    FOR(i,ng)
		{
			cin>>temp;
			sg.insert(temp);
		}
		FOR(i,nb)
		{
			cin>>temp;
			sb.insert(temp);
		}
		
		while(sg.size()>0&&sb.size()>0)
	    {
			size=MIN(bat,sg.size(),sb.size());
			b.clear();g.clear();
		it1=sg.end();it1--;
		it2=sb.end();it2--;
		FOR(i,size)
		{
			f1=*it1;it3=it1;it3--;
			sg.erase(it1);it1=it3;
			f2=*it2;it3=it2;it3--;
			sb.erase(it2);it2=it3;
			if(f1>f2){f1-=f2;f2=0;}
			else if(f2>f1){f2-=f1;f1=0;}
			else {f1=0;f2=0;}
			g.push_back(f1);
			b.push_back(f2);
				
		} 	
		FOR(i,size)
		{
			if(g[i]>0)sg.insert(g[i]);
			if(b[i]>0)sb.insert(b[i]);
		}
		
		}
		if(sb.size()==0&&sg.size()==0)
			cout<<"green and blue died\n";
		else if(sg.size()==0)
		{
			cout<<"blue wins\n";
			it1=sb.end();it1--;
			FOR(i,sb.size())
			{cout<<*it1<<endl;it1--;}
		}
		else 
		{
			cout<<"green wins\n";
			it2=sg.end();it2--;
			FOR(i,sg.size())
			{cout<<*it2<<endl;it2--;}
		}
		if(n)
		cout<<endl;
		
	}
	return 0;
}