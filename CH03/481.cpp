//TLE O(n^2) approach		
#include<iostream>
#include<vector>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
    vector <long> out,in,back,LIS;
	long temp,j,i,curr,maxi,mlen;
	while(cin>>temp)
	{in.push_back(temp);}
    LIS.assign(in.size(),0);
	back.assign(in.size(),0);
    mlen=0;
	FOR0(i,in.size())
	{
		curr=0;
		if(i==0)LIS[i]=1;
		else{
			FOR0(j,i)
			{
				if(in[j]<in[i])
				if(LIS[j]>=curr){curr=LIS[j];back[i]=j;}
			}
		}
		LIS[i]=curr+1;
		if(LIS[i]>=mlen){mlen=LIS[i];maxi=i;}
	}
	for(i=0,j=maxi;i<mlen;i++,j=back[j])
	{
		out.push_back(in[j]);
		if(j==0)break;
	}
	printf("%d\n-\n",mlen);
	for(i=mlen-1;i>=0;i--)printf("%d\n",out[i]);
}	