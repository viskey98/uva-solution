#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
int main()
{
	int k,N,M,*x,*y,i,j=0;
	std::vector <std::string> output;
	do{ 
		std::cin>>k;
		if(k==0)
			break;
	    x=(int*)calloc(k,sizeof(int));
	    y=(int*)calloc(k,sizeof(int));
		std::cin>>N>>M;
	    for(i=0;i<k;i++)
		   std::cin>>x[i]>>y[i];
	   for(i=0;i<k;i++,j++)
	    {
		 if((x[i]-N)==0||(y[i]-M)==0)
         output.push_back("divisa");
         else if((x[i]-N)>0&&(y[i]-M)>0)
	     output.push_back("NE");
		 else if((x[i]-N)<0&&(y[i]-M)>0)
		 output.push_back("NO");
		 else if((x[i]-N)<0&&(y[i]-M)<0)
		 output.push_back("SO");
		 else if((x[i]-N)>0&&(y[i]-M)<0)
         output.push_back("SE");
	    }
	   
	  }while(k!=0);
	  for(i=0;i<output.size();i++)
	  {
		  std::cout<<output[i]<<"\n";
	  }
	  return 0;
}