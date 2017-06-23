#include<iostream>
using namespace std;
void rotate90(char a1[][100],char a2[][100],int n)
{
	for(int i=0,y=0;i<n;i++,y++)
		for(int j=0,x=n-1;j<n;j++,x--)
			a2[i][j]=a1[x][y];
}
int Count(char b1[][100],char a[][100],int N,int n)
{
	int i,j,x,y,count1=0,count2;
	for(i=0;i+n-1<N;i++)
			for(j=0;j+n-1<N;j++)
			{
				count2=0;
				for(x=0;x<n;x++)
					for(y=0;y<n;y++)
					{
						if(b1[x+i][y+j]==a[x][y])
						count2++;
					}
					if(count2==n*n)count1++;
			}
		return count1;
}
int main()
{
	int N,n,i,j,x,y,t;
	char a1[100][100],a2[100][100],b1[100][100];
	while(1)
	{
		cin>>N>>n;
		if(N==0&&n==0)break;
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				cin>>b1[i][j];
		for(i=0;i<n;i++)
   			for(j=0;j<n;j++)
				cin>>a1[i][j];
		cout<<Count(b1,a1,N,n)<<" ";
		rotate90(a1,a2,n);
		cout<<Count(b1,a2,N,n)<<" ";
		rotate90(a2,a1,n);
		cout<<Count(b1,a1,N,n)<<" ";
		rotate90(a1,a2,n);
		cout<<Count(b1,a2,N,n)<<endl;
	}
	return 0;
	
}