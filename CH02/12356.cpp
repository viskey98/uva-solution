#include<iostream>
using namespace std;
int main()
{
	int i,S,B,l,r,x,y;
    int na[100003],pa[100003];
	while(1)
	{
		cin>>S>>B;
		if(S==0&&B==0) break;
		
			for(i=0;i<S+2;i++)
			{
				na[i]=i;pa[i]=i;
			}
		
		while(B--)
		{
			cin>>l>>r;
			x=na[r+1];y=pa[l-1];
			while(x!=na[x])x=na[x];
			while(y!=pa[y])y=pa[y];
			na[l]=na[r]=x;
			pa[l]=pa[r]=y;
			if(pa[l]<1)cout<<"* ";
			else cout<<pa[l]<<" ";
			if(na[r]>S)cout<<"*"<<endl;
			else cout<<na[r]<<endl;
			
		}
		cout<<"-"<<endl;
	}
}
 