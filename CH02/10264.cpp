#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
int main()
{
	vector <int> v,v1,v2;
	vector <int>::iterator it;
	bitset<14> b[17000];
	int i,j,n,temp,sum,max;
	while(cin>>n)
	{
		
		v.clear();v1.clear();v2.clear();
		for(i=0;i<pow(2,n);i++)
		{
			cin>>temp;
			b[i]=i;
			v.push_back(temp);
		}
		for(i=0;i<pow(2,n);i++)
		{   sum=0;
			for(j=0;j<n;j++)
			{
				if(b[i][j]==0)
				{
					sum+=v[i+pow(2,j)];
				}
				else 
				{
					sum+=v[i-pow(2,j)];
				}
			}
			v1.push_back(sum);
		}
		for(i=0;i<pow(2,n);i++)
		{
			
			for(j=0;j<n;j++)
			{
				if(b[i][j]==0)
				{
					v2.push_back(v1[i]+v1[i+pow(2,j)]);
				}
				
			}
		}
		max=*v2.begin();
		for(it=v2.begin();it<v2.end();it++)
		{
			if(*it>max)
				max=*it;
		}
		cout<<max<<endl;
		
	}
	return 0;
}
