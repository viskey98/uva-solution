#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bits/stdc++.h>
#include<queue>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b, long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long ll;
int ar[100005],st[400005];
int left(int i){
	return (i<<1);
}
int right(int i)
{
	return (i<<1) +1;
}
void build(int p, int l, int r)
{
     if(l==r){
		 if(ar[l]>0) 
		 st[p]=1;
	     else if(ar[l]==0)
			 st[p]=0;
		 else st[p]=-1;
		 return ;
	 }
	 int mid = (l+r)/2;
	 build(left(p),l,mid);
	 build(right(p),mid+1,r);
	 st[p]= st[left(p)]*st[right(p)];	 
}
int rpq(int p, int l, int r,int i, int j)
{
	if(l>j||r<i)
		return 1;
	if(i<=l&&j>=r)
		return st[p];
    int mid=(l+r)/2;
	int ans=rpq(left(p),l, mid,i,j)* rpq(right(p),mid+1,r,i,j);
	return ans;
}
void update(int p, int l, int r, int pos,int val)
{
	if(l==pos&&r==pos)
	{    if(val>0) 
		 st[p]=1;
	     else if(val==0)
			 st[p]=0;
		 else st[p]=-1;
		 
		 return ;}
    if(l>pos||r<pos)
	{
		return ;
	}
	int mid=(l+r)/2;
	 update(left(p),l,mid,pos,val);
	 update(right(p),mid+1,r,pos,val);
	 st[p]=st[left(p)]*st[right(p)];
}
int main()
{
	int n, k ,i,I,J;
	char a;
	while(cin>>n)
	{
		cin>>k;
		FOR(i,1,n+1)
		cin>>ar[i];
	    build(1,1,n);
		FOR0(i,k)
		{
			cin>>a>>I>>J;
			if(a=='C')
			{
			    update(1,1,n,I,J);
			}
			else {
				
				int ans=rpq(1,1,n,I,J);
				if(ans>0)cout<<"+";
				else if(ans==0)cout<<"0";
				else cout<<"-";
			}
		}
		cout<<endl;
	}
}