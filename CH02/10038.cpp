#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	
	int i,a[3000],x,n,flag;
	
	while(cin>>n)
	{
        flag=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}		
		x=(n*(n-1))/2;
		for(i=1;i<n;i++)
		{
					x-=abs(a[i]-a[i-1]);
                    if(abs(a[i]-a[i-1])==0)
					{flag=1; break;}						
		} 	
		if(x==0&&flag!=1)
			cout<<"Jolly"<<endl;
		else cout<<"Not jolly"<<endl;
		
	}
	return 0;
}