#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int ini[8],step,Min;
bitset <8>r;
bitset<15>ld,rd;
void backtrack(int j)
{
	int i;
	if(j==8){
		if(step<Min)Min=step;
	}
	else 
    for(i=0;i<8;i++)
	{
		if(r[i]!=1&&ld[7+i-j]!=1&&rd[i+j]!=1)
		{
			r[i]=1;ld[7+i-j]=1;rd[i+j]=1;
			if(ini[j]!=i)
			step++;
			backtrack(j+1);
			r[i]=0;ld[7+i-j]=0;rd[i+j]=0;
			if(ini[j]!=i)
			step--;
		}
	}
}
int main()
{
	int n=0,tmp;
	string input;
    while(cin>>ini[0])
	{
		ini[0]--;
		n++;
		r.reset();ld.reset();rd.reset();
		step=0;Min=10000;
		for(int j=1;j<8;j++)
		{
			cin>>ini[j];ini[j]--;
		}
		backtrack(0);
		printf("Case %d: %d\n",n,Min);
	}
	return 0;
}