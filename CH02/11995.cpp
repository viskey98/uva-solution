#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{	
	
	int n,op,ele,flag1,flag2,flag3;
	while(cin>>n)
	{
		flag1=1;flag2=1;flag3=1;
		stack<int> s;
	    queue<int> q;
	    priority_queue<int> pq;
		while(n--)
		{
			cin>>op>>ele;
			if(op==1)
			{
				s.push(ele);q.push(ele);pq.push(ele);
			}
			else if(op==2)
			{
				if(s.empty())flag1=0;
				else {if(s.top()!=ele)flag1=0;s.pop();}
				if(q.empty())flag2=0;
				else {if(q.front()!=ele)flag2=0;q.pop();}
				if(pq.empty())flag3=0;
				else {if(pq.top()!=ele)flag3=0;pq.pop();}
			}
		}
		if(flag1==1&&flag2==0&&flag3==0)
			cout<<"stack\n";
		else if(flag1==0&&flag2==1&&flag3==0)
			cout<<"queue\n";
		else if(flag1==0&&flag2==0&&flag3==1)
			cout<<"priority queue\n";
		else if(flag1==0&&flag2==0&&flag3==0)
			cout<<"impossible\n";
		else cout<<"not sure\n";
	}
    return 0;	
}