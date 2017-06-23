#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;
int main()
{
	bitset<31>a,b;
	unsigned long int n,l,i,j,a1,b1;
	int ind[31];
	while(1)
	{
		a.reset();b.reset();
		cin>>n; if(n==0)break;
		bitset<31>c(n);
		l=log2(n);l++;
		for(i=0,j=0;i<l;i++)
		{
			if(c[i]==1){ind[j]=i;j++;}
		}
		for(i=0;i<j;i+=2)
			a[ind[i]]=1;
        for(i=1;i<j;i+=2)		
		    b[ind[i]]=1;
		a1=a.to_ulong();
		b1=b.to_ulong();
		cout<<a1<<" "<<b1<<endl;
	}
	return 0;
}