#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
void makeline(char *a)
{
	int k=0;
	char* b=(char*)calloc(strlen(a)+1,sizeof(char));
	for(int i=0;i<strlen(a);i++)
		if(a[i]!=' '&&a[i]!='.'&&a[i]!=','&&a[i]!='!'&&a[i]!='?')
		{if(a[i]<=90&&a[i]>=65)
				b[k]=a[i]+32;
            else
                b[k]=a[i];
			k++;
		}
    b[k]='\0';
    strcpy(a,b);	
}
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
int main()
{
	
	char input[10000];
	int output[10000];
	int k=0;
	while(1)
	{
		int i=0;
		while (1) {
          scanf("%c", &input[i]);
          if (input[i] == '\n') {
           break;
                }
          else  {
            i++;
          }
        }
        input[i]='\0';
		if(strcmp(input,"DONE")==0)
			break;
		makeline(input);
		if(ispalin(input)==1)
			output[k]=1;
		else 
			output[k]=0;
		k++;
	}
	for(int i=0;i<k;i++)
		if(output[i]==1)
			cout<<"You won't be eaten!\n";
		else 
			cout<<"Uh oh..\n";
		return 0;
	
}