#include<iostream>
#include<vector>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
	int i,n,m,k,v,temp,temp2;
	while(cin>>n)
	{
		vector<vector<int>> graph(1000000);
		cin>>m;
		FOR(i,n)
		{
			cin>>temp;
			graph[temp-1].push_back(i);
		}
		FOR(i,m)
		{
			cin>>temp>>temp2;
			if(temp>graph[temp2-1].size())
			cout<<"0\n";
		    else 
			{cout<<graph[temp2-1][temp-1]+1;
		    cout<<endl;}
		}
	}
	return 0;
}