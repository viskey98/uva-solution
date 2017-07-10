#include<iostream>
using namespace std;
int n,m,c[1001];
bool check(long cap)
{
	int nc=1,cur=0;
	for(int i=0;i<n;i++)
	{
		if(c[i]>cap)return false;
		if(cur+c[i]>cap){cur=0;nc++;}
		cur+=c[i];
		if(nc>m)return false;
	}
	return true;
}
int main()
{
		while(cin>>n)
		{
			cin>>m;
			for(int i=0;i<n;i++)
				cin>>c[i];
		    long high=1000000000,low=1,mid;
			while(high-low>0)
			{
				mid=(high+low)/2;
				if(check(mid))
				high=mid;
			    else low=mid+1;
			}
			cout<<high<<endl;
		}
		return 0;
}