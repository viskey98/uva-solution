#include<iostream>
using namespace std;
int main()
{
	int h,u,d,f,i,k=0;
	float up,net;
	int output[100];
	while(1)
	{
		net=0;
		cin>>h;
		if(h==0)
			break;
		cin>>u>>d>>f;
		for(i=0;;i++)
		{
 		  	 if(i==0)
			 up=u;
			else
			up=up-((float)f/100)*u;
		    
			if(up>=0)	
			net+=up;
			
		if(net>h)
		{
			output[k]=i+1;
			break;
		}
		net-=d;
		if(net<0)
		{
			output[k]=-1*(i+1);
			break;
		}
		}
		k++;
	}
	for(i=0;i<k;i++)
	{
		if(output[i]>0)
		cout<<"success on day "<<output[i]<<"\n";
	    else
		cout<<"failure on day "<<-1*output[i]<<"\n";
	}
	return 0;
}