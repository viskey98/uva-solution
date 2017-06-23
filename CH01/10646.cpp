#include<iostream>
using namespace std;
int value(char a)
{
	if(a-'0'>=2&&a-'0'<=9)
		return a-'0';
	else return 10;
}
int main()
{
	int t,T,i,j,x,y,l,count;	
	cin>>t;
	cin.ignore();
	string input[52];
	for(T=0;T<t;T++)
	{
		
		for(i=0;i<52;i++)
		{
			input[i].clear();
			cin>>input[i];
		}
		y=0; 
		for(i=26,j=0;j<3;j++)
		{
			x=value(input[i].at(0));
			y+=x;
			
			for(l=10-x;l>=0;l--)
			{
			    input[i].clear();
				input[i]="0";
				i-=1;
			}
			
		}
		for(j=0,count=0;count<y;j++)
		{
			if(input[j]!="0")
				count++;	
		}
		cout<<"Case "<<T+1<<": ";
		cout<<input[j-1]<<endl;
	}
	return 0;
}