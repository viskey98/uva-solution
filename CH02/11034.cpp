#include<iostream>
#include<queue>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int main()
{
	queue<int> left,right;
	int i,c,m,ans,temp,cur;
	float l,x;
	string in;
	cin>>c;
	while(c--)
	{
		cin>>l>>m;
		while(m--)
		{
			cin>>temp>>in;
			if(in=="left")left.push(temp);
			else right.push(temp);
		}
		ans=0;
		while(left.empty()!=1||right.empty()!=1)
		{
			x=l;
			while(left.empty()!=1)
			{
				cur=0;
				x-=((float)left.front()/100);
				if(x>=0)left.pop();
				else break;
				
			}
			ans+=1;x=l;
			if(left.empty()!=1)cur=1;
			while(right.empty()!=1)
			{
				cur=1;
				x-=((float)right.front()/100);
				if(x>=0)right.pop();
				else break;
				
			}
			if(cur==1)ans+=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}