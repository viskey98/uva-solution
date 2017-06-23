#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int i,j,n,m,x,y,count,nw,na,wake[26],years;
	char a,b,c;
	while(cin>>n)
	{
		vector<vector<int>> v(26);
		vector<int>stat;
		stat.assign(26,-1);
		cin>>m;
		cin>>a>>b>>c;
		stat[a-'A']=stat[b-'A']=stat[c-'A']=1;
		while(m--)
		{
			cin>>a>>b;
			x=a-'A';y=b-'A';
			if(stat[x]!=1)stat[x]=0;
			if(stat[y]!=1)stat[y]=0;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		years=0;
		while(1)
		{
			nw=0;
			na=0;
		  for(i=0;i<26;i++)
		  {
			  count=0;
			  if(stat[i]==0)
			  {
				  for(j=0;j<v[i].size();j++)
					  if(stat[v[i][j]]==1)count++;
				  if(count>=3){wake[nw]=i;nw++;}
			  }
 			  else if(stat[i]==1)na++;
		  }
		  if(na<n&&nw==0){cout<<"THIS BRAIN NEVER WAKES UP\n";break;}
		  else {
			  if(nw==0&&na==n){cout<<"WAKE UP IN, "<<years<<", YEARS\n";break;}
			  else{
				  for(i=0;i<nw;i++){stat[wake[i]]=1;}years++;
			  }
		  }
		}
		cin.ignore();
	}
	return 0;
}