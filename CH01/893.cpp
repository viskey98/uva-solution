#include<iostream>
using namespace std;
int m[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int y[2]={365,366};
int year,mo,d;
int isleap()
{
	if((year%4==0&&year%100!=0)||(year%400==0))
		return 1;
	else return 0;
}
void increment(long long N)
{
	int temp;
	while(N>0)
	{
		int t=isleap();
		
		if(N>=y[t])
		{
	    if(d!=1||mo!=0)
		{
		if(d!=1)
		{
			temp=(m[t][mo]-d)+1;
			N-=temp;
			d=1;mo++;if(mo>11){mo=0;year++;}
		}
        if(mo!=0)
		{
			for(int i=mo;i<12;i++)
				N-=m[t][i];
			    mo=0;year++;
		}
		}
		else {

			N-=y[t];
			year++;
		}
		
		}
		else 
		{
			if(N>=(m[t][mo]-d+1))
			{
				N-=(m[t][mo]-d+1);
				d=1;
				mo++;
				if(mo>11){mo=0;year++;}
			}
			else 
			{
				d+=N;
				N=0;
			}
			
		}
        		
	}
}
int main()
{
	long long N;
	while(1)
	{
	   cin>>N>>d>>mo>>year;
	   if(N==0)break;
	   mo--;
	   increment(N);
	   ++mo;
	   cout<<d<<" "<<mo<<" "<<year<<endl;
	}
	return 0;
}