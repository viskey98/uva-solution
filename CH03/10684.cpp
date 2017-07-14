#include<iostream>
#include<vector>
#define FOR(i,n) for(i=0;i<n;i++)
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
int main()
{
	int N,i,temp,sum,ans;
	vector<int>in;
	while(true)
	{
		cin>>N;
		in.clear();
		if(!N)break;
		FOR(i,N)		
		{scanf("%d",&temp);in.push_back(temp);}
	    sum=0;ans=0;
	     FOR(i,N)
		 {
			 sum+=in[i];
			 ans=MAX(ans,sum);
			 if(sum<0)sum=0;
		 }
		if(ans>0)
        printf("The maximum winning streak is %d.\n",ans);	
	    else printf("Losing streak.\n");
	}
	return 0;
}