#include<iostream>
#include<string.h>
using namespace std;
int main()
{ 
    string pro[1000],output[1000],req[1000],req1[1000];
    int n,p,i,k=0,j,r,oprice,oi;
	float ocm,comp,d;
	while(1)
    {
		cin>>n>>p;
		if(n==0&&p==0)
			break;
		scanf("%*c");
		
		for(i=0;i<n;i++)
		{   
           getline(cin,req[i]);
		}
		
	    
		for(i=0;i<p;i++)
			getline(cin,pro[i]);
		{
			cin>>d>>r;
			comp=(float)r/n;
			if(i==0)
			{
				oi=i;
				oprice=d;
				ocm=comp;
			}
			else if(comp>ocm)
			{
				ocm=comp;
				oi=i;
				oprice=d;
			}	
			else if(comp==ocm)
			{
				if(d<oprice)
				{
					ocm=comp;
					oi=i;
					oprice=d;
				}
			}
			
	    scanf("%*c");
		for(j=0;j<r;j++)
		 getline(cin,req1[j]);
		}
		output[k]=pro[oi];
		k++;
	}
	for(i=0;i<k;i++)
	{cout<<"RFP #"<<i+1<<"\n"<<output[i]<<"\n";
      if(i!=k-1)
		  cout<<"\n";
	}
	return 0;
}