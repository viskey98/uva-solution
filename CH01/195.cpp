#include<iostream>
#include<string.h>
using namespace std;
int isleft(int ele, char* arr, int size,int *used)
{
	for(int i=ele-1;i>=0;i--)
	{
		if(arr[i]==arr[ele]&&used[i]!=1)
			return 1;
	}
	 return 0;
}
void permute(char *arr,int*used,int pos,char* ar1,int size)
{
	if(pos==size)
		{
			cout<<ar1<<endl;
			
		}
	else 
	for(int ele=0;ele<size;ele++)
	{
		
		if(used[ele]!=1&&isleft(ele,arr,size,used)!=1)
		{
			ar1[pos]=arr[ele];
			used[ele]=1;
			permute(arr,used,pos+1,ar1,size);
			used[ele]=0;
		}
		
	}
}


int main()
{
	int t,used[100]={},i,j;
	char input[100],temp;
	cin>>t;
	while(t--)
	{
		input[0]='\0';
		cin>>input;
		char out[100]={};
		for(i=0;i<strlen(input);i++)
			for(j=i+1;j<strlen(input);j++)
			{
				if((input[i]>=97&&input[j]>=97)||(input[i]<=90&&input[j]<=90))
				{
					if(input[i]>input[j])
					{
						temp=input[i];
						input[i]=input[j];
						input[j]=temp;
					}
				}
                else
				{
				   if(input[i]>input[j]&&input[i]>=input[j]+32)
				   {
					   temp=input[i];
						input[i]=input[j];
						input[j]=temp; 
				   }
				   else if(input[i]<input[j]&&input[i]+32>input[j])
					   {
					   temp=input[i];
						input[i]=input[j];
						input[j]=temp;  
				   }
				}			
			}
		permute(input,used,0,out,strlen(input));
		
	}
	return 0;
}