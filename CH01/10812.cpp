#include<iostream>
using namespace std;
int main()
{
	int n;
	int in1,in2;
	float temp;
	int out1,out2;
	cin>>n;
	while(n--)
	{
		cin>>in1>>in2;	
		out1=(in1-in2)/2;
		if((in1-in2)%2!=0)
			out1=-1;
		out2=in1-out1;
		if(out1<0||out2<0)
		{
			cout<<"impossible"<<endl;
			continue;
		}
		else 
		{
			cout<<out2<<" "<<out1<<endl;
		}
		
	}
	return 0;
}