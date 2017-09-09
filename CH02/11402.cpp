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
string ar;
int st[4500000];
int lazy[45000000];
int left(int i)
{
	return (i<<1);
}
int right(int i)
{
	return (i<<1)+1;
}
void build(int p, int l,int r)
{
	if(l==r)
	{
		st[p]=ar[l]-'0';
		return ;
	}
	int mid= (l+r)/2;
	build(left(p),l,mid);
	build(right(p),mid+1,r);
	st[p]=st[left(p)]+st[right(p)];
}
int rsq(int p,int l,int r, int i, int j)
{
	int mid=(l+r)/2;
	if(lazy[p]!=0){
		if(lazy[p]==-1)
		st[p]=(r-l+1)-st[p];
	    else if (lazy[p]==-3)
			st[p]=0;
		else st[p]=(r-l+1);
		if(l!=r)
		{
			if(lazy[left(p)]!=0)
			{
				if(lazy[p]==-3||lazy[p]==1)
					lazy[left(p)]=lazy[p];
				else 
				{   if(lazy[left(p)]==-3)
						lazy[left(p)]=1;
				
					else if(lazy[left(p)]==1)
						lazy[left(p)]=-3;
					else lazy[left(p)]=0;
				}		
			}
			else lazy[left(p)]=lazy[p];
			if(lazy[right(p)]!=0)
			{
				if(lazy[p]==-3||lazy[p]==1)
					lazy[right(p)]=lazy[p];
				else 
				{   if(lazy[right(p)]==-3)
						lazy[right(p)]=1;
				
					else if(lazy[right(p)]==1)
						lazy[right(p)]=-3;
					else lazy[right(p)]=0;
				}
			}
			else lazy[right(p)]=lazy[p];
		}
		lazy[p]=0;
	}
	if(i>r||j<l)
		return 0;
	if(i<=l&&j>=r)
	{
		return st[p];
	}
	int ans= rsq(left(p),l,mid,i,j)+rsq(right(p),mid+1,r,i,j);
	return ans;
}
void update(int p, int l ,int r, int i , int j, int diff)
{
	int mid=(l+r)/2;
	if(lazy[p]!=0){
		if(lazy[p]==-1)
		st[p]=(r-l+1)-st[p];
	    else if (lazy[p]==-3)
			st[p]=0;
		else st[p]=(r-l+1);
		if(l!=r)
		{
			if(lazy[left(p)]!=0)
			{
				if(lazy[p]==-3||lazy[p]==1)
					lazy[left(p)]=lazy[p];
				else 
				{   if(lazy[left(p)]==-3)
						lazy[left(p)]=1;
				
					else if(lazy[left(p)]==1)
						lazy[left(p)]=-3;
					else lazy[left(p)]=0;
				}		
			}
			else lazy[left(p)]=lazy[p];
			if(lazy[right(p)]!=0)
			{
				if(lazy[p]==-3||lazy[p]==1)
					lazy[right(p)]=lazy[p];
				else 
				{   if(lazy[right(p)]==-3)
						lazy[right(p)]=1;
				
					else if(lazy[right(p)]==1)
						lazy[right(p)]=-3;
					else lazy[right(p)]=0;
				}
			}
			else lazy[right(p)]=lazy[p];
		}
		lazy[p]=0;
	}
	if(l>j||r<i)return;
	if(l>=i&&r<=j)
	{
		if(diff==-1)
		st[p]=(r-l+1)-st[p];
	    else if (diff==-3)
			st[p]=0;
		else st[p]=(r-l+1);
		if(l!=r)
		{
			if(lazy[left(p)]!=0)
			{
				if(diff==-3||diff==1)
					lazy[left(p)]=diff;
				else 
				{   if(lazy[left(p)]==-3)
						lazy[left(p)]=1;
				
					else if(lazy[left(p)]==1)
						lazy[left(p)]=-3;
					else lazy[left(p)]=0;
				}		
			}
			else lazy[left(p)]=diff;
			if(lazy[right(p)]!=0)
			{
				if(diff==-3||diff==1)
					lazy[right(p)]=diff;
				else 
				{   if(lazy[right(p)]==-3)
						lazy[right(p)]=1;
				
					else if(lazy[right(p)]==1)
						lazy[right(p)]=-3;
					else lazy[right(p)]=0;
				}
			}
			else lazy[right(p)]=diff;
		}
		return ;
	}
	 update(left(p),l,mid,i,j,diff);
	 update(right(p),mid+1,r,i,j,diff);
	 st[p]=st[left(p)]+st[right(p)];
}
int main()
{
	int i,t,j,testcases,n,m,q,a,b,k;
	char com;
	string input;
	cin>>testcases;
	FOR0(k,testcases)
	{
		ar.clear();
		int x=0;
		printf("Case %d:\n",k+1);
		cin>>m;
		FOR0(i,m)
		{
			cin>>t>>input;
			FOR0(j,t)
			ar+=input;
		}
		n=ar.size();
		build(1,0,n-1);
		cin>>q;
		FOR0(i,q)
		{
			cin>>com>>a>>b;
			if(com=='F')
				update(1,0,n-1,a,b,1);

			else if(com=='E')
				update(1,0,n-1,a,b,-3);
			else if(com=='I')
				update(1,0,n-1,a,b,-1);
			else 
			 {printf("Q%d: %d\n",++x,rsq(1,0,n-1,a,b));}
		}
		FOR0(i,4*n+1) lazy[i]=0;
	}
	return 0;
}
