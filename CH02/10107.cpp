#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long int in[10000],temp;
	int n=0,k,i;
	while(cin>>temp)
	{	
        
		k=lower_bound(in,in+n,temp)-in;
		n++;
		for(i=n-1;i>=k+1;i--)
		{
			in[i]=in[i-1];
		}
		in[k]=temp;
		if(n%2==0)
		{
			if(in[n/2]%2!=0&&in[(n/2)-1]%2!=0)
				cout<<(in[n/2]/2)+(in[(n/2)-1]/2)+1<<endl;
			else cout<<(in[n/2]/2)+(in[(n/2)-1]/2)<<endl;
		}
		else cout<<in[n/2]<<endl;
	   	
	}
	return 0;
}