#include<iostream>
#include<vector>
using namespace std;
vector <int>CD,output,curr;
int N,Max=0;
int backtrack(int sum,int i)
{
	int j;
	for(j=i+1;j<CD.size();j++)
	{if((sum+CD[j])<=N)
		{sum+=CD[j];
	     curr.push_back(CD[j]);
	     backtrack(sum,j);
		 curr.pop_back();
		 sum-=CD[j];
		}  
	}
	if(Max<sum)
	{
		Max=sum;
		output.clear();
		for(j=0;j<curr.size();j++)
		{
			
			output.push_back(curr[j]);
		}
	}
}
int main()
{
	int n,i,j,tmp;
	while(cin>>N)
	{
		Max=0;
		CD.clear();curr.clear();
		cin>>n;
		for( i=0;i<n;i++)
		{cin>>tmp;CD.push_back(tmp);}
	    backtrack(0,-1);
	    for(i=0;i<output.size();i++)
			cout<<output[i]<<" ";
		cout<<"sum:"<<Max<<endl;
	}
	return 0;
}