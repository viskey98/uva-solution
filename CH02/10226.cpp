#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<string,int>m1;
	map<string,int>::iterator i1;
	string input;
	int n,total;
	float ans;
	cin>>n;
	cin.ignore();cin.ignore();
	while(n--)
	{   
		 total=0; m1.clear();
		while (1){
		input.clear();
		getline(cin,input);
		if(input=="")break;
		total++;
		i1=m1.find(input);
		if(i1==m1.end())
			m1[input]=1;
		else i1->second++;
		}
		for(i1=m1.begin();i1!=m1.end();i1++)
		{
			ans=100*((float)i1->second)/total;
			cout<<i1->first<<" ";
			printf("%.4f\n",ans);
			
		}
        if(n)		
		cout<<endl;	
	}
	
	return 0;
}