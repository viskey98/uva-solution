#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t,l,k,i,j,T;
	string s1;
	cin>>t;
	scanf("%*c");
	for(T=0;T<t;T++)
	{
     	getline(cin,s1);
		string s2,s3;
		int pal=1;	
		for(i=0;i<s1.length();i++)
		{
			if(s1[i]>='a'&&s1[i]<='z'||s1[i]>='A'&&s2[i]<='Z')
				s2.append(s1,i,1);
		}
		l=s2.length();
		k=sqrt(l);
		if(k*k!=l)
			pal=0;
		else
		{
			for(i=0;i<l/2;i++)
			{
				if(s2[i]!=s2[l-i-1])
				{
					pal=0;
					break;
				}
			}
			if(pal)
			{
				for(i=0;i<k;i++)
				{
					for(j=0;j<k;j++)
						s3.append(s2,k*j+i,1);
				}
				if(s2!=s3)
					pal=0;
				else
				{
				   for(i=0;i<l;i++)
				   {
					   if(s3[i]!=s3[l-i-1])
					   {
						   pal=0;
						   break;
					   }
				   }					   
				}	
					
				
			}
			
		}
		   cout<<"Case #"<<T+1<<":"<<endl;	
		    if(pal) 
			cout<<k<<endl;
			else cout<<"No magic :("<<endl;
		
		
	}
}
