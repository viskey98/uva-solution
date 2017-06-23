#include<iostream>
#include<stdlib.h>
using namespace std;
char killer(char a)
{
	if(a=='R')
		return 'P';
	else if(a=='P')
		return 'S';
	else if(a=='S');
	    return 'R';
}
int main()
{
	char **in,**out;
	int i,j,l,k=0,m,t,r,c,n;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>r>>c>>n;
		in=(char**)calloc(r+1,sizeof(char*));
		out=(char**)calloc(r+1,sizeof(char*));
		for(j=0;j<r;j++)
		{
			in[j]=(char*)calloc(c+1,sizeof(char));
			out[j]=(char*)calloc(c+1,sizeof(char));
		}
		for(l=0;l<r;l++)
		{
			for(m=0;m<c;m++)
			{
				cin>>in[l][m];
			}
		}
		k=0;
		while(k<n)
		{
			for(l=0;l<r;l++)
			{
				for(m=0;m<c;m++)
				{
					if(m+1<c)
					if(in[l][m+1]==killer(in[l][m]))
					{
						out[l][m]=killer(in[l][m]);
						continue;
					}
					if(l+1<r)
					if(in[l+1][m]==killer(in[l][m]))
					{
						out[l][m]=killer(in[l][m]);
						continue;
					}
					if(m-1>=0)
					if(in[l][m-1]==killer(in[l][m]))
					{
						out[l][m]=killer(in[l][m]);
						continue;
					}
					if(l-1>=0)
					if(in[l-1][m]==killer(in[l][m]))
					{
						out[l][m]=killer(in[l][m]);
						continue;
					}
					out[l][m]=in[l][m];
								
				}
			}
			for(l=0;l<r;l++)
		{
			for(m=0;m<c;m++)
			{
				in[l][m]=out[l][m];
			}
		}
			
			k++;
		}
		
		for(l=0;l<r;l++)
		{
			for(m=0;m<c;m++)
			{
				cout<<out[l][m];
			}
			cout<<endl;
		}
		if(i!=t-1)
		cout<<endl;
		free(in);
		free(out);
		
	}
	return 0;
}