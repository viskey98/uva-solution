#include<iostream>
#include<queue>
#include<stack>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int N;
queue<int>q[100];
stack<int>s;
int allempty()
{
	int count=0,i;
	FOR(i,N){if(q[i].empty()==1)count++;}
	if(count==N && s.empty()==1)
		return 1;
	else return 0;
}
int main()
{
	
	int set,n,S,Q,i,j,temp,time;
	cin>>set;
	while(set--)
	{
		
		cin>>N>>S>>Q;
		FOR(i,N)
		{
			cin>>n;
			FOR(j,n){cin>>temp;q[i].push(temp);}
		}
		i=0;time=0;
		while(allempty()==0)
		{
			while((q[i].size()<Q&&s.empty()!=1)||(s.empty()!=1&&s.top()==i+1))
			{
			   if(s.top()==i+1){s.pop();time+=1;}
			   else {q[i].push(s.top());s.pop();time+=1;}
			}
			while(s.size()<S&&q[i].empty()!=1)
			{
				s.push(q[i].front());q[i].pop();time+=1;
			}
			time+=2;i++;
			if(i==N)i=0;
		
		} 
		time-=2;
		cout<<time<<endl;
	}
	return 0;
}