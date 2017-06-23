#include<iostream>
using namespace std;
int ki[8]={-2,-2,-1,-1,1,1,2,2}, kj[8]={-1,1,-2,2,-2,2,-1,1}; 
void pawn(int c,int b[][8],int x, int y)
{
	
	if(c==0)
	{
		if(x+1<8&&y-1>=0)
	    	if(b[x+1][y-1]!=1)
				b[x+1][y-1]=-1;
		if(x+1<8&&y+1<8)
			if(b[x+1][y+1]!=1)
				b[x+1][y+1]=-1;		
	}
	else 
	{
		if(x-1>=0&&y-1>=0)
	    	if(b[x-1][y-1]!=1)
				b[x-1][y-1]=-1;
		if(x-1>=0&&y+1<8)
			if(b[x-1][y+1]!=1)
				b[x-1][y+1]=-1;	
	}
}
void diagonal(int b[][8], int x,int y)
{
	int i,j;
	for(i=1,j=1;;i++,j++)
	{
	    if(x+i<8&&y+j<8)
		{   if(b[x+i][y+j]!=1)
		      b[x+i][y+j]=-1;
		    else break;
		}
		else break;
	}
	for(i=-1,j=1;;i--,j++)
	{
		if(x+i>=0&&y+j<8)
		{   if(b[x+i][y+j]!=1)
		      b[x+i][y+j]=-1;
		    else break;
		}
		else break;
	}
	for(i=-1,j=-1;;i--,j--)
	{
		if(x+i>=0&&y+j>=0)
		{   if(b[x+i][y+j]!=1)
		      b[x+i][y+j]=-1;
		    else break;
		}
		else break;
	}
	for(i=1,j=-1;;i++,j--)
	{
		if(x+i<8&&y+j>=0)
		{   if(b[x+i][y+j]!=1)
		      b[x+i][y+j]=-1;
		    else break;
		}
		else break;
	}
}
void straight(int b[][8],int x,int y)
{   
    int i;
	for(i=1;;i++)
	{
		if(x+i<8)
		{ 	if(b[x+i][y]!=1)
				b[x+i][y]=-1;
			else break;
		}
		else break;
	}
	for(i=1;;i++)
	{
		if(y+i<8)
		{ 	if(b[x][y+i]!=1)
				b[x][y+i]=-1;
			else break;
		}
		else break;
	}
	for(i=-1;;i--)
	{
		if(x+i>=0)
		{ 	if(b[x+i][y]!=1)
				b[x+i][y]=-1;
			else break;
		}
		else break;
	}
	for(i=-1;;i--)
	{
		if(y+i>=0)
		{ 	if(b[x][y+i]!=1)
				b[x][y+i]=-1;
			else break;
		}
		else break;
	}
}
void king(int b[][8],int x,int y)
{
	int i,j;
	for(i=-1;i<2;i++)
	{
		for(j=-1;j<2;j++)
		{
			if(x+i>=0&&x+i<8&&y+j>=0&&y+j<8)
			{
				if(b[x+i][y+j]!=1)
					b[x+i][y+j]=-1;
			}
		}
	}
}
void knight(int b[][8],int x,int y)
{
	int i;
	for(i=0;i<8;i++)
	{
		if(x+ki[i]<8&&x+ki[i]>=0&&y+kj[i]<8&&y+kj[i]>=0)
			if(b[x+ki[i]][y+kj[i]]!=1)
				b[x+ki[i]][y+kj[i]]=-1;
	}
}
int main()
{
	int i,j,k,l,m,count;
	int temp;
    string input;
	while(getline(cin,input))
	{
		l=0;m=0;
		char a[8][8];
	    int b[8][8]={}; 
		for(i=0;i<input.length();i++)
		{    
			if(input[i]>='0'&&input[i]<='8')
			{
				temp=input.at(i)-'0';
				for(j=0;j<temp;j++)
				{
					a[m][l]='0';
					l++; 	
				}
			}
			else if((input[i]<='z'&&input[i]>='a')||(input[i]>='A'&&input[i]<='Z'))
			{
				a[m][l]=input.at(i);
				l++;
			}
			else if(input[i]=='/')
			{
				m++;
				l=0;
			}
		}
		input.clear();
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
			{
				if(a[i][j]!='0')
					b[i][j]=1;
				else 
					b[i][j]=0;
			}
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
			if(b[i][j]==1)
			{
				switch(a[i][j])
				{
					case 'p': pawn(0,b,i,j); break;
					case 'P': pawn(1,b,i,j); break;
					case 'B':
					case 'b': diagonal(b,i,j);break;
					case 'R':
					case 'r': straight(b,i,j);break;
					case 'Q':
					case 'q': straight(b,i,j);diagonal(b,i,j);break;
					case 'K': 
					case 'k': king(b,i,j);break;
					case 'N':
					case 'n': knight(b,i,j);break;
				}
			}
		count=0;
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
				if(b[i][j]==0)
					count++;
		}
		cout<<count<<endl;
        		
	}
	return 0;
}