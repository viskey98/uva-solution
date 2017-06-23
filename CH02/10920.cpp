#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long int sz,p,n,rel,line,col,temp;
	while(true)
	{
		cin>>sz>>p;
		if(sz==0&&p==0)break;
		n=ceil(sqrt(p));if(n%2==0)n++;
		rel=p-((n-2)*(n-2));
		if(n==1)
		{line=1;col=1;}
		else
		{
			temp=rel/(n-1);
			if(temp==0)
			{
				line=n;
				col=n-rel;
			}
			else if(temp==1)
			{
				line=2*n-1-rel;
				col=1;
			}
			else if(temp==2)
			{
				col=rel-(2*n-3);
				line=1;
			}
			else 
			{
				line =rel-(3*n-4);
				col=n;
			}
		}	
		line+=(sz-n)/2;
		col+=(sz-n)/2;
		cout<<"Line = "<<line<<", column = "<<col<<"."<<endl;

	}
	return 0;
}