#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,m,k;
	int value[100],ans;
	char ch[100];
	string in;
	cin>>n;
	while(n--)
	{
		int no[100]={};
		cin>>k;
		for(int i=0;i<k;i++)
		{cin>>ch[i]>>value[i];     
		}
		cin>>m;
		cin.ignore();
		for(int i=0;i<m;i++)
		{
			in.clear();
			getline(cin,in);	
			for(int j=0;j<in.length();j++)
			{
				
					for(int l=0;l<k;l++)
					{
						if(in.at(j)==ch[l])
							no[l]++;
					}
			}
		}
		ans=0;
		for(int i=0;i<k;i++)
		{
			ans+=(value[i])*(no[i]);
		}
		printf("%d.%02d$\n", ans/100, ans%100);
	}
	return 0;
	
}