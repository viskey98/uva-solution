#include<iostream>
#include<queue>
#define FOR(i,n) for(i=0;i<n;i++)
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
	queue<int> car[2];
	long int i,c,n,nt,nc,t,m,time,temp,curr;
	long int ta[10000],td[10000];
	string in;
	cin>>c;
	while(c--)
	{
		cin>>n>>t>>m;
		FOR(i,m)
		{ 
			cin>>temp>>in;
			if(in=="left")car[0].push(i);
			else car[1].push(i);
			ta[i]=temp;
		}
			
		time=0;curr=0;
		while(car[0].empty()!=1||car[1].empty()!=1)
		{
			if(car[0].empty()==1)nt=ta[car[1].front()];
			else if(car[1].empty()==1)nt=ta[car[0].front()];
			else nt=MIN(ta[car[0].front()],ta[car[1].front()]);
			time=MAX(time,nt);
			nc=0;
			while(!car[curr].empty()&&time>=ta[car[curr].front()]&&nc<n)
			{
				nc++;
				td[car[curr].front()]=time+t;
				car[curr].pop();				
			}
			curr=1-curr;
			time+=t;			
		}
		FOR(i,m)cout<<td[i]<<endl;
		if(c)cout<<endl;
	}
}