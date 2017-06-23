#include<iostream>
#include<map>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
struct con{
   int onof[9];
   int ques;
   int time[9];
};	
typedef struct con Con;
Con temp={{},9,{}};
vector<int>details(3);
int main()
{
	int n,a,b,c,s=0,k;
	char d;	
	string input,tmp;
	cin>>n;
	cin.ignore();cin.ignore();
	while(n--)
	{
		 map<int,Con>m;
		 map<int,Con>::iterator it;
		while(true)
		{	   
	       input.clear();
 	       getline(cin,input);
		   if(input.size()==0)break;
		   tmp.clear();k=0;
		   while(input[k]!=' '){tmp+=input[k];k++;}
		   a=stoi(tmp);k++;
		   tmp.clear();
		   while(input[k]!=' '){tmp+=input[k];k++;}
		   b=stoi(tmp);k++;
		   tmp.clear();
		   while(input[k]!=' '){tmp+=input[k];k++;}
		   c=stoi(tmp);k++;
		   d=input[input.size()-1];
		   it=m.find(a);
		   if(it==m.end()){m[a]=temp;}
		   if(m[a].onof[b-1]!=1)
		   {
		   if(d=='I'){m[a].time[b-1]+=20;}
		   if(d=='C'){m[a].time[b-1]+=c;m[a].ques--;m[a].onof[b-1]=1;}
		   }
		}
		if(s)cout<<endl;
		int Time;
		set<vector<int>> x;
		set<vector<int>>::iterator it2;
		for(it=m.begin();it!=m.end();it++)
		{
			Time=0;
			for(int j=0;j<9;j++)
			{
				if((*it).second.onof[j]==1)
				{
					Time+=(*it).second.time[j];
				}
			}
			details[0]=(*it).second.ques;
			details[1]=Time;
			details[2]=(*it).first;
			x.insert(details);
		}
		for(it2=x.begin();it2!=x.end();it2++)
		{
			cout<<(*it2)[2]<<" "<<9-(*it2)[0]<<" "<<(*it2)[1]<<endl;
		}
		s=1;
		
		
	}
	return 0;
}