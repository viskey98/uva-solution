#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m,ans;
	while(1)
	{
	cin>>n>>m;
	if(n!=0||m!=0)
	   {
		if(n==0||m==0)
            ans=0;
        else if(n==1||m==1)
		{
			if(n==1)
				ans=m;
			else 
				ans=n;
		}
	   else if(n==2||m==2)
        {
			if(n==2)
			{
				if(m%4==0)
					ans=m;
				else if(m%4==1)
					ans=((m/4)*4)+2;
				else if(m%4==2)
					ans=((m/4)*4)+4;
				else if(m%4==3)
					ans=((m/4)*4)+4;
			}
			else 
			{
				if(n%4==0)
					ans=n;
				else if(n%4==1)
					ans=((n/4)*4)+2;
				else if(n%4==2)
					ans=((n/4)*4)+4;
				else if(n%4==3)
					ans=((n/4)*4)+4;
			}
		}
        else
        {
			ans=ceil(((float)m*n)/2);
		}
        cout<<ans<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;		
	   }
	   else break;
	   
	}
	return 0;
}