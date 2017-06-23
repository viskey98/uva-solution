#include<iostream>
using namespace std;
int main()
{
	int input[5],i,j,count1,count2,temp,sol,flag;
	while(1)
	{
		count1=0;count2=0;
		for(i=0;i<5;i++)
			cin>>input[i];
		if(input[0]==0)
			break;
		for(i=0;i<3;i++)
		{
			for(j=i+1;j<3;j++)
				if(input[i]>input[j])
				{
					temp=input[i];
					input[i]=input[j];
					input[j]=temp;
				}
		}
		if(input[3]>input[4])
		{
			temp=input[3];
			input[3]=input[4];
			input[4]=temp;
		}
		for(i=0;i<3;i++)
		{
			if(input[i]<input[3])
				count1++;
			if(input[i]<input[4])
				count2++;
		}
	    if(count1+count2>=4||count1==3||count2==3)
		{
			if(count1+count2==6)
				sol=0;
			else{
				if(input[3]<input[1])
					sol=input[2];
				else sol=input[1];
			}
		}
		else sol=52;
		for(i=sol+1;i<=52;i++)
		{
			for(j=0,flag=0;j<5;j++)
			{
				if(input[j]==i)
				{
					flag=1;
					break;
				}
			}
			if(flag!=1)
				break;
		}
		if(i>52)
			cout<<-1<<endl;
		else 
			cout<<i<<endl;
	}
	return 0;
}