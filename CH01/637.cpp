#include<iostream>
using namespace std;
int main()
{
	int n,i,k,j;
	int p[100];
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		cout<<"Printing order for "<<n<<" pages:\n";
		for(i=1;;i++)
		{
			if(4*i-n>=0)
			{
				k=4*i;
				break;
			}
		}
		for(i=0;i<k;i++)
		{
			if(i<n)
			p[i]=i+1;
	        else p[i]=0;
		}
		for(i=0,j=0;i<k/2;i++)
		{
			if(p[i]!=0||p[k-i-1]!=0)
			{
				if(i%2==0)
				{
					cout<<"Sheet "<<j+1<<", front: ";
					if(p[k-i-1]!=0)cout<<p[k-i-1]<<", ";
					else cout<<"Blank, ";
					cout<<p[i]<<"\n";
				}
				else
				{
					cout<<"Sheet "<<j+1<<", back : ";
					cout<<p[i]<<", ";					
					if(p[k-i-1]!=0)
					cout<<p[k-i-1]<<"\n";
				    else cout<<"Blank"<<"\n";
					j++;
				}
			}
		}
	}
	return 0;
}