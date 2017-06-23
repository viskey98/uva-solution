#include<iostream>
#include<cmath>
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;
int main()
{
	int n,m,t;
	char a;
	cin>>t;
	while(t--)
	{
		cin>>a;
		cin>>n>>m;
		switch(a)
		{
			case 'r': cout<<MIN(n,m)<<endl;break;
			case 'Q': cout<<MIN(n,m)<<endl;break;
			case 'k': cout<<ceil(((float)m*n)/2)<<endl;break;
			case 'K': cout<<ceil((float)m/2)*ceil((float)n/2)<<endl;break;
		}
		
	}
	return 0;
}