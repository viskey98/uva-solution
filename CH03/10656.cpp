#include<iostream>
using namespace std;
int main()
{
	int N,temp;
	bool start;
	cin>>N;
	while(true)
	{
		start=false;
		for(int i=0;i<N;i++)
		{cin>>temp;if(temp){if(start)cout<<" ";cout<<temp;start=true;}}
	    if(!start)cout<<"0";
		cout<<endl;
		cin>>N;
		if(!N)break;
	}
}