#include<iostream>
#include<string.h>
using namespace std;
char chr[21]={'A','E','H','I','J','L','M','O','S','T','U','V','W','X','Y','Z','1','2','3','5','8'};
char rev[21]={'A','3','H','I','L','J','M','O','2','T','U','V','W','X','Y','5','1','S','E','Z','8'};
int ispalin(char* a)
{
	int i=0;
	char *b=(char*)calloc(strlen(a)+1,sizeof(char));
	for(i=0;i<strlen(a);i++)
		b[strlen(a)-i-1]=a[i];
	if(strcmp(a,b)==0)
		return 1;
	else return 0;
}
int ismirror(char* a)
{
	int i=0,j;
	char *b=(char*)calloc(strlen(a)+1,sizeof(char));
	for(i=0;i<strlen(a);i++)
	{
		for(j=0;j<21;j++)
        {if(chr[j]==a[i])
            b[i]=rev[j];
		}		
	}
	char *c=(char*)calloc(strlen(b)+1,sizeof(char));
    for(i=0;i<strlen(b);i++)
		c[strlen(b)-i-1]=b[i];
	if(strcmp(c,a)==0)
		return 1;
	else return 0;
}
int main()
{
	int output[10000],i,k=0;
	char input[10000][100];
	while(!cin.eof())
	{
		cin>>input[k];
		if(ispalin(input[k])==1&&ismirror(input[k])==1)
			output[k]=4;
		else if(ispalin(input[k])==1)
		{
			output[k]=2;
		}
		else if(ismirror(input[k])==1)
		{
			output[k]=3;
		}
		else{
			output[k]=1;
		}
		k++;
	}
	k--;
	for(i=0;i<k;i++)
	{
		switch(output[i])
		{
			case 1: cout<<input[i]<<" -- "<<"is not a palindrome.\n";
			          break;
		    case 2: cout<<input[i]<<" -- "<<"is a regular palindrome.\n";
			          break;
		    case 3: cout<<input[i]<<" -- "<<"is a mirrored string.\n";
			          break;
			case 4: cout<<input[i]<<" -- "<<"is a mirrored palindrome.\n";
			          break;
		}
		
			cout<<"\n";
	}
	return 0;
}
