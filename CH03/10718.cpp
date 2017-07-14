#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
	bitset<33>N,ans,temp;
    unsigned long int n,l,u;
	int i,size;
	while(cin>>n)
	{
		cin>>l>>u;
	    N.reset();ans.reset();
		N=n;
		ans=0;
		for(i=31;i>=0;i--)
		{
			if(N[i]==1)
			{	
		        ans[i]=0;
				temp=ans;
				int j=i-1;
				while(j>=0)
				{temp[j]=1;j--;}
				if(temp.to_ulong()<l)
			    ans[i]=1;
			}
			if(N[i]==0)
			{
				ans[i]=1;
				if(ans.to_ulong()>u)
					ans[i]=0;
			}
		}
        	
		cout<<ans.to_ulong()<<endl;
	} 	
	return 0;
}