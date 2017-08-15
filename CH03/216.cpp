#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
using namespace std;
int n,X[10],Y[10];
float table[10][300];
float dp(int index,int visited)
{
	float ans=1000000,temp;
	int i;
	if(visited==((1<<n)-1))return 0;
	if(table[index][visited]!=0)return table[index][visited];
	for(i=0;i<n;i++)
	{
		if(!((1<<i)&(visited)))
		{
			temp = (16+sqrt(((X[index]-X[i])*(X[index]-X[i]))+((Y[index]-Y[i])*(Y[index]-Y[i])))+dp(i,visited|(1<<i)));
			ans=MIN(ans,temp);
		}
		
	}
	return table[index][visited]=ans;
}
int main()
{
    int i,prev,visited,mini,minv;
    float ans;	
	vector<int>sol;
	for(int k=1;;k++)
	{
		cin>>n;if(!n)break;
		sol.clear();
		memset(table,0,sizeof table);
		FOR0(i,n)
		cin>>X[i]>>Y[i];
		float min;
		min=dp(0,1);
		mini=0;minv=1;
		FOR(i,1,n)
		{
			if(min>dp(i,1<<i))
			{min=dp(i,1<<i);mini=i;minv=1<<i;}
		}
		prev=mini;visited=minv;
		sol.push_back(mini);
		while(1)
		{
			FOR0(i,n)
			{
				if(!((1<<i)&(visited)))
				{
					float dis=sqrt(((X[prev]-X[i])*(X[prev]-X[i]))+((Y[prev]-Y[i])*(Y[prev]-Y[i])));
					if((int)((table[prev][visited])*100)==(int)((16+dis+table[i][visited|1<<i])*100))
					{
						sol.push_back(i);
						prev=i;visited=visited|(1<<i);
						break;
					}
				}
			}
			if(visited==((1<<n)-1))break;
		}
		printf("**********************************************************\n");
		printf("Network #%d\n",k);
		FOR(i,1,sol.size())
		{
			ans=16+sqrt(((X[sol[i]]-X[sol[i-1]])*(X[sol[i]]-X[sol[i-1]]))+((Y[sol[i]]-Y[sol[i-1]])*(Y[sol[i]]-Y[sol[i-1]])));
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",X[sol[i-1]],Y[sol[i-1]],X[sol[i]],Y[sol[i]],ans);
		}
		printf("Number of feet of cable required is %.2f.\n",dp(mini,minv));
		
	}
}