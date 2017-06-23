#include<iostream>
#include<string.h>
using namespace std;
int score(char a)
{
	int i;
	i=a-'0';
	if(a=='X')
		return 10;
	else if(a=='/')
		return 10;
	else 
	{
		return i;
	}
}
void makeline(char* a)
{
	int k=0;
	char *b;
	b=(char*)calloc(strlen(a)+1,sizeof(char));
	for(int i=0;i<strlen(a);i++)
		if(a[i]!=' ')
		{
                b[k]=a[i];
			     k++;
		}
    b[k]='\0';	
    strcpy(a,b);
    free(b);	
    
}
int main()
{
	char input[100];
	int output=0;
	int i,j,k=0,count;
	while(1)
	{	
		output=0;	
		cin.getline(input,100);
		if(strcmp("Game Over",input)==0)
			break;
	
		count=0;
		makeline(input);
		for(j=0;j<strlen(input);)
		{
			if(count!=9)
			{
			if(input[j]!='X'&&input[j+1]!='/')
			{
				output+=score(input[j])+score(input[j+1]);
                count++;
                j+=2;				
			}
			else if(input[j]=='X')
			{
				if(input[j+2]!='/')
				{
					output+=score(input[j])+score(input[j+1])+score(input[j+2]);
					j++;
					count++;
				}
				else 
				{
					output+=score(input[j])+score(input[j+2]);
					j++;
					count++;
				}
				
			}
			else if(input[j+1]=='/')
			{
				output+=score(input[j+1])+score(input[j+2]);
				j+=2;
				count++;
			}
				
			}
			else
			{
				if(input[j]=='X')
			    {
				if(input[j+2]!='/')
				{
					output+=score(input[j])+score(input[j+1])+score(input[j+2]);
					break;
				
				}
				else
				{
					output+=score(input[j])+score(input[j+2]);
					break;
				}
								
			    }
				else if(input[j+1]=='/')
				{
					output+=score(input[j+1])+score(input[j+2]);
					break;
				}
				else
				{
					output+=score(input[j])+score(input[j+1]);
                    break;					
				}
			}
	    }
		cout<<output<<endl;
	}
	
	return 0;
}