#include<iostream>
#include<set>
#include<vector>
#include<cmath>
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;
int main()
{
	set<vector<int>>s;
	set<vector<int>>::iterator it;
	vector<int>v;
	string input,tmp;
	int i,j,ni=0,qnum,period,t,k;
	while(1)
	{
		getline(cin,input);
		if(input=="#")break;
		tmp.clear();v.clear();
		j=9;
		while(input[j]!=' '){tmp+=input[j];j++;}j++;
		qnum=stoi(tmp);
		tmp.clear();
		for(;j<input.length();j++){tmp+=input[j];}
		period=stoi(tmp);
		v.push_back(period);v.push_back(qnum);v.push_back(period);
		s.insert(v);
		
	}
	cin>>k;
	
	FOR(i,k)
	{
		it=s.begin();
		cout<<(*it)[1]<<endl;
		v.clear();
		v.push_back((*it)[0]+(*it)[2]);v.push_back((*it)[1]);v.push_back((*it)[2]);
		s.insert(v);
		s.erase(it);
			
	}
	return 0;
}