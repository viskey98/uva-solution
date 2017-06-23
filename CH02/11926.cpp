#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	bitset<1000001>b;
	long int n,m,inter,j,k,l,r,i,flag;
	while(true)
	{
		flag=0;
		b.reset();
		cin>>n>>m;
		if(n==0&&m==0)break;
		for(i=0;i<n;i++)
		{
			cin>>l>>r;
			for(j=l;j<r;j++){
				if(b[j]==0)b[j]=1;
				else if(b[j]==1){flag=1;break;}
			}
		}
		
		for(i=0;i<m;i++)
		{
			cin>>l>>r>>inter;
			k=0;
			for(j=l,n=0;k<=1000000;j++)
			{
				k=j+n*inter;
				if(k>1000000)break;
				if(b[k]==0)b[k]=1;
				else if(b[k]==1){flag=1;break;}
				if(j==r-1)
				{n++;j=l-1;}
			}
		}
		if(flag==0)cout<<"NO CONFLICT"<<endl;
		else cout<<"CONFLICT"<<endl;
			
	}
	return 0;
}