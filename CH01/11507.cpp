#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int l,i,k=0;
	char input[100000][3],ans[3];
	char output[1000][3];
	while(1)
	{   strcpy(ans,"+x");
		cin>>l;
		if(l==0)
			break;
		
		for(i=0;i<l-1;i++)
		{	cin>>input[i];
            if(strcmp(input[i],"No")!=0)
			{	
	        if(ans[1]=='z')
			{
				if(input[i][1]!='y')
				{
					if(input[i][0]==ans[0])
						strcpy(ans,"-x");
					else
						strcpy(ans,"+x");
				}	
			}
			else if(ans[1]=='y')
			{
				if(input[i][1]!='z')
				{
					if(input[i][0]==ans[0])
						strcpy(ans,"-x");
					else
						strcpy(ans,"+x");
				}
			}
			else if(ans[1]=='x')
			{
				if(ans[0]=='+')
					strcpy(ans,input[i]);
				else
				{
					if(input[i][0]=='-')
				    input[i][0]='+';
				    else
					input[i][0]='-'; 
					strcpy(ans,input[i]);
				}
			}
		    }		
	    }
        strcpy(output[k],ans);
		k++;
    }
	for(i=0;i<k;i++)
			cout<<output[i][0]<<output[i][1]<<"\n";
	return 0;
}