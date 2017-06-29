#include<iostream>
#include<vector>
using namespace std;
long int s,d,sum;
vector<long int> output;
long int sum5(int j)
{
	 long int sm=0;
	for(int i=0;i<5;i++,j--)
	{
		sm+=output[j];
	}
	return sm;
}
void build5()
{
	int i;
	for(i=0;i<5;i++)
		output.push_back(s);
	for(i=4;i>=0;i--)
	{
		output[i]=d;
		if(sum5(4)<0)break;
	}
	sum+=sum5(4);
}

void backtrack(int j)
{
	if(j==11)
		return;
	output.push_back(s);
	if(sum5(j+1)<0)
	{
		sum+=s;
	    backtrack(j+1);
	}
	else 
	{
		output.pop_back();
		output.push_back(d);
		sum+=d;
		backtrack(j+1);
	}
}
int main()
{
	while(cin>>s)
	{
		output.clear();
		sum=0;
		cin>>d;
		d=(-1)*d;
		build5();
		backtrack(4);
		if(sum>0)cout<<sum<<endl;
		else cout<<"Deficit\n";
	}
	return 0;
}