#include<iostream>
#include<cmath>
using namespace std;
int p,q,r,s,t,u;
double f(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*(x*x)+u;
}
int main()
{
	double ans,mid,start,end;
	while(cin>>p)
	{
		start=0;end=1;
		cin>>q>>r>>s>>t>>u;
		if(f(0)==0)
			ans=0;
		else if(f(0)<0||f(0)*f(1)>0)ans=-1;
		else 
		for(int i=0;i<30;i++)  // to get a precision upto 10^9 its enough to do maximum log2((1-0)/10^9)~30 iterations.
		{
			mid=(start+end)/2.0;
			ans=f(mid);
			if(ans>0)
			   start=mid;
		    else
 				end=mid;
		}
		if(ans==-1)
		cout<<"No solution\n";
        else if(ans==0)
		printf("%.4lf\n",ans);
        else 	
		printf("%.4lf\n",mid);
		
	}
	return 0;
}