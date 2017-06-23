#include<iostream>
#include<vector>
#define FOR(i,n) for(i=0;i<n;i++)
#define left(p) 2*p
#define right(p) 2*p+1
#define MAX(a,b,c) ((a>b)?((a>c)?a:c):((b>c)?b:c))
using namespace std;
typedef vector<int> vi;
vi A,st;
void build(int p,int L,int R)
{
	if(L==R)st[p]=L;
	else 
	{
		build(left(p),L,(L+R)/2);
		build(right(p),(L+R)/2 +1,R);
		int p1=st[left(p)],p2=st[right(p)];
		st[p]=(A[p1]>=A[p2]? p1:p2);
	}
}
int RMQ(int p,int L,int R,int i,int j)
{
	if(L>j||R<i)return -1;
	if(L>=i&&R<=j)return st[p];
	
	int p1=RMQ(left(p),L,(L+R)/2,i,j);
	int p2=RMQ(right(p),(L+R)/2 +1,R,i,j);
	if(p1==-1)return p2;
	if(p2==-1)return p1;
	return (A[p1]>=A[p2]?p1:p2);
}
int main()
{
	int a,b,c,n,num,j,i,q,k,tmp,ele,lc,rc,ans,l,r;
	vi arr,start,stop;
	while(1)
	{
		cin>>n;if(n==0)break;
		cin>>q;
	    st.assign(4*n,0);
		A.clear();arr.clear();
		stop.clear();start.clear();
		FOR(i,n){cin>>tmp;arr.push_back(tmp);}
		for(i=0;i<arr.size();)
		{
			ele=arr[i];
			j=i;num=0;
			while(arr[j]==ele)
			{num++;j++;}
			for(k=0;k<num;k++)
			{
				A.push_back(num);
				start.push_back(i);
				stop.push_back(i+num-1);
			}
			i+=num;
		}
		build(1,0,n-1);
	    FOR(i,q)
		{
			cin>>l>>r;
			l--;r--;
			if(start[l]==start[r])
				ans=r-l+1;
			else 
			{
				lc=0;rc=0;ans=0;
				if(start[l]<l)
				{lc=stop[l]-l+1;l=stop[l]+1;}
			    if(stop[r]>r)
				{
					rc=r-start[r]+1;r=start[r]-1;
				}
				if(l<=r)
				{
					ans=A[RMQ(1,0,n-1,l,r)];
				}
				ans=MAX(ans,lc,rc);
			}
			cout<<ans<<endl;	
		}
			
		
	}
	return 0;
}