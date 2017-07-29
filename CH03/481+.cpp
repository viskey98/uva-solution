//O(nlog(k))+O(n) approach
#include<iostream>
#include<vector>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
	vector<long>in,L,Li,out,prev;
	long temp,i,j,pos;
	while(cin>>temp)
	{
		in.push_back(temp);
	}
	prev.assign(in.size(),0);
	FOR0(i,in.size())
	{
			 pos =lower_bound(L.begin(),L.end(),in[i])-L.begin();
			
			if(pos==L.size())
			{
				L.push_back(in[i]);Li.push_back(i);
			}	
			else 
			{
				L[pos]=in[i];Li[pos]=i;
			}
			if(pos)prev[i]=Li[pos-1];
			
	}
	printf("%d\n-\n",L.size());
	for(j=Li[Li.size()-1],i=0; j>=0,i<Li.size(); i++,j=prev[j])
	{
	     out.push_back(in[j]);
	}
	for(i=out.size()-1;i>=0;i--)
		printf("%ld\n",out[i]);
	
}