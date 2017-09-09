#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bits/stdc++.h>
#include<queue>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX2(a,b) (a)>(b)?(a):(b)
#define MAX3(a,b,c) (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c))
#define MIN2(a,b) (a)<(b)?(a):(b)	
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
map< string , int> m1;
map<int ,string> m2;
vector < set<int> > v(105);
priority_queue < int, vector<int>, greater<int> > q;

vi toposort;
int mask=-1,n;
int noin(int ele)
{
	set<int> ::iterator it,it2;
	int i,j,x,flag=0;
     FOR0(i,n)
	 {
		 if(i==mask)
			 continue;
		 it=v[i].begin();
		 it2=v[i].end();
		 for(;it!=it2;it++)
		 if(ele==*it)
		 { flag=1; break;}
	     if(flag==1)break;
	 }
	 if(i==n)return 1;
	 else return 0;
}
int main()
{
	string input,temp;
	int m,i,j,t=0,x;
	string name[105];
	set<int> ::iterator it,it2;
	while(cin>>n)
	{
		mask=-1;
		m1.clear();
		m2.clear();
		toposort.clear();
		FOR0(i,105)v[i].clear();
		FOR0(i,n)
		{
			cin>>input;
			m1[input]=i;
			m2[i]=input;
		}
		cin>>m;
		FOR0(i,m)
		{
			cin>>input>>temp;
			v[m1[input]].insert(m1[temp]);
		}
		FOR0(i,n)
		{
			if(noin(i))
			{q.push(i);}
		}
		while(!q.empty())
		{
			mask=q.top();
			q.pop();
			it=v[mask].begin();
			it2=v[mask].end();
		    for(;it!=it2;it++)
			{
				if(noin(*it))
				{q.push(*it);}
			}
			toposort.push_back(mask);
			v[mask].clear();
		}
		printf("Case #%d: Dilbert should drink beverages in this order: ",++t);
		 x=toposort.size();
		FOR0(i,x)
		{cout<<m2[toposort[i]];
		if(i!=x-1)cout<<" ";
		else cout<<".";}
		cout<<endl<<endl;
		
	}
}