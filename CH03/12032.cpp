#include<iostream>
using namespace std;
long r[100000],n;
bool simulate(long a)
{
	long b;
	for(int i=0;i<n;i++)
	{
		if(i==0)b=r[i];
		else b=r[i]-r[i-1];
		if(a==b)a--;
		else if(a<b)return false;
	}
	return true;
}
int main()
{
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		long max,ans;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>r[i];
			if(i==0)
			max=r[i];
		    else 
			if((r[i]-r[i-1])>max)max=r[i]-r[i-1];
            		
		}
		if(simulate(max))ans=max;
		else ans=max+1;
		printf("Case %d: %d\n",j+1,ans);	
	}
	return 0;
}