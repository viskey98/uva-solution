#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define FOR(i,n) for(i=0;i<n;i++)
int N;
using namespace std;
vector <long int> books;
int binarysearch(int start, int end, long int J)
{
	if(start>end)return 0;
	int mid=(start+end)/2;
	if(books[mid]==J)
		return 1;
	else if(J>books[mid])
		return binarysearch(mid+1,end,J);
	else if(J<books[mid])
		return binarysearch(0,mid-1,J);
}
int main()
{
	long int temp,I,J,M;
	int i,ans,mid,low;
	vector< long int>::iterator Low;
	while(cin>>N)
	{
		books.clear();
		FOR(i,N)
		{cin>>temp;books.push_back(temp);}
	    cin>>M;
		sort(books.begin(),books.end());
		Low=lower_bound(books.begin(),books.end(),M/2);
		low=(Low-books.begin());
		for(i=low;i<N;i++)
		{
			ans=0;
			I=books[i];
			J=M-I;
			if(J>0)
			{
				if(J<I)
			    ans=binarysearch(0,low-1,J);
			    else 
				{
					if(((i-1>=0)&&books[i-1]==J)||((i+1<N)&&books[i+1]==J))
						ans=1;
				}
			}
			if(ans==1)
			{
				break;
			}
		}
		if(J<I){temp=J;
		J=I;
		I=temp;
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",I,J);
	}
	return 0;
}