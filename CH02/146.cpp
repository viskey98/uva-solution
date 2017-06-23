#include<iostream>
using namespace std;
int main()
{
	int i,j,k,l,size;
	char input[55],temp,c;
	while(1)
	{
		 l=0;
        while (c=getchar(), c!='\n'&&c!=EOF)
        {
            input[l]=c;
            l++;
        }
		
		if(input[0]=='#')
			break;
		size=l;
		for(i=size-1;i>0;i--)
		{
			if(input[i]>input[i-1])
				break;
		}
		if(i==0)cout<<"No Successor"<<endl;
		else{
			for(j=i,k=0;j<((size-i)/2)+i;j++,k++)
			{
				temp=input[j];
				input[j]=input[size-k-1];
				input[size-k-1]=temp;
			}
			i--;j=i+1;
			while(input[i]>=input[j])
				j++;
		    temp=input[i];
			input[i]=input[j];
			input[j]=temp;
			for(i=0;i<size;i++)
				cout<<input[i];
			cout<<endl;
		}
	}
	return 0;
}