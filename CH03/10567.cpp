#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string in,ss;
	cin>>in;
	bool start=false;
	long q,i,prev,pos,l;
	int a;
	vector <vector<long>> state(52);
	vector<long>::iterator it;
	for( i=0; i<in.size();i++)
	{
		if(in[i]>=97&&in[i]<=122)
			state[in[i]-97].push_back(i);
		if(in[i]>=65&&in[i]<=90)
			state[in[i]-65+26].push_back(i);	
	}
	cin>>q;
	while(q--)
	{
		start=false;
		prev=-1;
		cin>>ss;
		for( i=0 ;i<ss.size();i++)
		{
			prev++;
			if(ss[i]>=97&&ss[i]<=122)
				a=ss[i]-97;
			else a=ss[i]-65+26;
			
			it=lower_bound(state[a].begin(),state[a].end(),prev);
			pos=*it;
			if(!start){l=pos;start=true;}
			if(it!=state[a].end()&&pos>=prev)prev=pos;
			else break;
		}
		if(i==ss.size())
			printf("Matched %d %d\n",l,pos);
		else cout<<"Not matched\n";
	}
	return 0;
}