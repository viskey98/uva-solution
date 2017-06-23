#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef vector<int> vi;
class UnionFind{

	public:
	    vi p,rank,count;
     	UnionFind(int N){
		rank.assign(N,0);p.assign(N,0);count.assign(N,1);
	     for(int i=0;i<N;i++)p[i]=i;}
		int findSet(int i){return (p[i]==i)?i:(p[i]=findSet(p[i]));}
		bool isSameSet(int i,int j){return (findSet(i)==findSet(j));}
		void UnionSet(int i, int j){
			if(!isSameSet(i,j))
			{
			    int x=findSet(i),y=findSet(j);
				if(rank[x]>rank[y]){p[y]=x;count[x]+=count[y];}
				else {p[x]=y;count[y]+=count[x];
				       if(rank[x]==rank[y])rank[y]++;
				     
				}
			}
		}
		
	};
int main()
{
	
	int i,t,n,num,x;
	string i1,i2;
	map<string,int> m;
	map<string,int>::iterator it1,it2;
	cin>>t,n;
	while(t--)
	{
		UnionFind U(0);
		m.clear();
		num=0; 
		cin>>n;
		while(n--)
		{
			cin>>i1>>i2;
			it1=m.find(i1);
			if(it1==m.end()){
				m[i1]=num;
				U.p.push_back(num);
				U.rank.push_back(0);
				U.count.push_back(1);
				num++;
			}
			it2=m.find(i2);
			if(it2==m.end()){
				m[i2]=num;
				U.p.push_back(num);
				U.rank.push_back(0);
				U.count.push_back(1);
				num++;
			}
			U.UnionSet(m[i1],m[i2]);
			x=U.findSet(m[i1]);
			cout<<U.count[x]<<endl;
		}
		
	}
	return 0;
}
