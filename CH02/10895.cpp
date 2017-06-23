#include<iostream>
#include<list>
#include<vector>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
typedef list<pair<int,int>> lii;
int main()
{
	int i,r,c,n,j,index[10001],ele[10001];
	lii::iterator it;
	while(cin>>r)
	{
		vector<lii>matrix(10001);
		cin>>c;
		
		FOR(i,r)
		{    
			cin>>n;if(n==0){cin.ignore();continue;}
			FOR(j,n)cin>>index[j];
			FOR(j,n)cin>>ele[j];
			FOR(j,n)
			{
				matrix[index[j]-1].push_back(make_pair(i,ele[j]));
			}
		}
		cout<<c<<" "<<r<<endl;
		
		FOR(i,c)
		{
			it=matrix[i].begin();
			if(it!=matrix[i].end())
			{ n=0;
	         while(it!=matrix[i].end())
			 {  n++; it++;}
		     cout<<n<<" ";
			 it=matrix[i].begin();
			 FOR(j,n)
			 {cout<<(it->first)+1;if(j!=n-1)cout<<" ";else cout<<endl;it++;}
		     it=matrix[i].begin();
			 FOR(j,n)
			 {cout<<(it->second);if(j!=n-1)cout<<" ";else cout<<endl;it++;}	 
			}
			else cout<<"0\n\n";
		}
	}
	return 0;
	
}