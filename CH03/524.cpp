#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bitset<16>used;
int n;
vector<int>output;
int isprime(int i)
{ 
    int j;
	int s=sqrt(i);
	for(j=2;j<=s;j++)
		if(i%j==0)break;
	if(j==s+1)return 1;
	else return 0;
}
void backtrack (int i)
{
	
	if((used==((1<<n)-1))&&output[n-1]%2==0)
	{
		if(isprime(output[n-1]+1)){
			cout<<output[0]<<" ";
		for(int k=1;k<n;k++)
		{cout<<output[k];if(k!=n-1)cout<<" ";}
	    cout<<endl;
		}
		
	}
	
	for(int j=1;j<=n;j++)
	{
		if(i+j%2!=0&&used[j-1]==0)
		if(isprime(i+j))
		{
			used[j-1]=1;
			output.push_back(j);
			backtrack(j);
			used[j-1]=0;
			output.pop_back();
		}
			
	}
}
int main()
{
	int t=0;
	while(cin>>n)
	{
		if(t)cout<<endl;
		t++;used.reset();output.clear();
		printf("Case %d:\n",t);
		output.push_back(1);
		used[0]=1;
		backtrack(1);
			
		
	}
	return 0;
}