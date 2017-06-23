#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector <int>v;
	int temp,n,i,j,k,size,h,m,s,count;
	while(1)
	{
		v.clear();
		cin>>temp;
		if(temp==0)break;
		else v.push_back(temp);
		while(1)
		{
			cin>>temp;
			if(temp==0)break;
			else v.push_back(temp);
		}
		sort(v.begin(),v.end());
		size=v.size();
		for(i=2*v.at(0),j=0;i+j<=18000;j++)
		{
			count=0;
			for(k=1;k<size;k++)
			{
				if(((i+j)%(2*v.at(k)))<v.at(k)-5)
					count++;
			}
			if(count==size-1)
				break;
			if(i+j>18000)break;
			if(j==v.at(0)-6)
			{	j=-1;i+=2*v.at(0);
			}
		}
		if((i+j)>18000)
			cout<<"Signals fail to synchronise in 5 hours"<<endl;
		else 
		{
			h=(i+j)/3600;
			temp=(i+j)%3600;
			m=temp/60;
			s=temp%60;
			if(h>=5&&(m>0||s>0)) cout<<"Signals fail to synchronise in 5 hours"<<endl;
			else{
			if(h<10)
				cout<<"0"<<h<<":";
 			else cout<<h<<":";
			if(m<10) cout<<"0"<<m<<":";
			else cout<<m<<":";
			if(s<10)cout<<"0"<<s<<endl;
			else cout<<s<<endl;
			}
		}
	}
	return 0;
}
