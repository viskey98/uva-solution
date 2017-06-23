#include<queue>
#include<iostream>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
	long long int n,temp,i,sum,cost;
	priority_queue<int,vector<int>,greater<int> >pq;
	while(1)
	{
		cin>>n;if(n==0)break;
		FOR(i,n)
		{
			cin>>temp;
			pq.push(temp);
		}
		
		cost=0;
		while(pq.size()>1)
		{
			sum=pq.top();pq.pop();
			sum+=pq.top();pq.pop();
			pq.push(sum);
			cost+=sum;
		}
		pq.pop();
		cout<<cost<<endl;
	}
	return 0;
}
