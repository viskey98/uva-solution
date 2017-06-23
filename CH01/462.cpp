#include<iostream>
using namespace std;
void eval(char a,char b,int*K,int*Q,int*J,int*A,int*cards,char*suit)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(suit[i]==b)
			break;
	}
	cards[i]++;
	if(a=='K')
		K[i]++;
	else if(a=='J')
		J[i]++;
	else if(a=='Q')
		Q[i]++;
	else if(a=='A')
		A[i]++;
}
int main()
{
	int i,stop,score,out;
	string input;
	while(getline(cin,input))
	{
		int K[4]={},Q[4]={},J[4]={},A[4]={},pts[4]={},cards[4]={};
		char suit[4]={'S','H','D','C'};
		for(i=0;i<input.length();i+=3)
		{
			eval(input.at(i),input.at(i+1),K,Q,J,A,cards,suit);
		}
		score=0;
		for(i=0;i<4;i++)
		{
			if(K[i]==1)
				pts[i]+=3;
			if(Q[i]==1)
				pts[i]+=2;
			if(A[i]==1)
				pts[i]+=4;
			if(J[i]==1)
				pts[i]+=1;
			if(K[i]==1&&cards[i]==1)
				pts[i]-=1;
			if(Q[i]==1&&cards[i]<=2)
				pts[i]-=1;
			if(J[i]==1&&cards[i]<=3)
				pts[i]-=1;
			score+=pts[i];
		}
		stop=0;
		for(i=0;i<4;i++)
		{
			if(A[i]==1||(K[i]==1&&cards[i]>=2)||(Q[i]==1&&cards[i]>=3))
				stop++;
		}
		if(score>=16&&stop==4)
		{
			out=-2;
		}
		else
		{
			score=0;
			for(i=0;i<4;i++)	
			{
				if(cards[i]==2)
                    pts[i]++;
                else if(cards[i]==1)
                    pts[i]+=2;
                else if(cards[i]==0)	
                    pts[i]+=2;
				score+=pts[i];                				
			}
			if(score>=14)
			{
				out=0;
				for(i=0;i<4;i++)
				{
					if(cards[out]<cards[i])
						out=i;
				}
			}
			else out=-1;
            			
		}
		if(out>=0)
			cout<<"BID "<<suit[out]<<endl;
        else if(out==-1)		
		     cout<<"PASS"<<endl;
        else if(out==-2)
             cout<<"BID NO-TRUMP"<<endl;		
		input.clear();
	}
    return 0; 	
}