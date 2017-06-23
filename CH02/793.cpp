#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;
class UnionFind{
	private: vi p,rank;
	public:
     	UnionFind(int N){
		rank.assign(N,0);p.assign(N,0);
	     for(int i=0;i<N;i++)p[i]=i;}
		int findSet(int i){return (p[i]==i)?i:(p[i]=findSet(p[i]));}
		bool isSameSet(int i,int j){return (findSet(i)==findSet(j));}
		void UnionSet(int i, int j){
			if(!isSameSet(i,j))
			{
			    int x=findSet(i),y=findSet(j);
				if(rank[x]>rank[y])p[y]=x;
				else {p[x]=y;
				       if(rank[x]==rank[y])rank[y]++;
				}
			}
		}
		
	};
int main()
{
	int t,n,sa,ua,a,b;
	char c;
	cin>>t;
	while(t--)
	{
		sa=0;ua=0;
		scanf("%d",&n);
		cin.ignore();
		UnionFind U(n);
		while(1)
		{
		c=getchar();
		if(c=='\n'||c==-1)break;
		cin>>a>>b;
		cin.ignore();
		if(c=='c')
		{
			U.UnionSet(a-1,b-1);
		}
		else
		{
			if(U.isSameSet(a-1,b-1))
				sa++;
			else ua++;
		}
		}
		cout<<sa<<","<<ua<<endl;
		if(t)cout<<endl;
	}
	return 0;
}