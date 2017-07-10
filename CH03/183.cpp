#include<iostream>
using namespace std;
int bmap[202][202],r,c,cur;
string out,in;
int prcsmap(int ri,int rf,int ci,int cf)
{
	int n0=0,n1=0;
	for(int i=ri;i<=rf;i++)
		for(int j=ci;j<=cf;j++)
		{
			if(bmap[i][j]==1)n1++;
			else n0++;
		}
		if(n1==0)return 0;
		else if(n0==0)return 1;
		else return -1;
}
void BtoD(int ri,int rf,int ci,int cf)
{
	
	int rsize,csize,rmid,cmid;
	int color=prcsmap(ri,rf,ci,cf);
	if(color==1)out.push_back('1');
	else if(color==0)out.push_back('0');
	else 
	{
		out.push_back('D');
		rsize=(rf-ri+1);
		csize=(cf-ci+1);
		if(rsize!=1&&csize!=1)
		{
		if(rsize%2==0)rmid=ri+(rsize/2)-1;
		else rmid=ri+(rsize/2);
		if(csize%2==0)cmid=ci+(csize/2)-1;
		else cmid=ci+(csize/2);
		BtoD(ri,rmid,ci,cmid);
		BtoD(ri,rmid,cmid+1,cf);
		BtoD(rmid+1,rf,ci,cmid);
		BtoD(rmid+1,rf,cmid+1,cf);
		}
		else 
		{
		   if(rsize==1)
		   {
			 	if(csize%2==0)cmid=ci+(csize/2)-1;
		         else cmid=ci+(csize/2);	
 				 BtoD(ri,rf,ci,cmid);
				 BtoD(ri,rf,cmid+1,cf);
		   }
		   else 
		   {
			   if(rsize%2==0)rmid=ri+(rsize/2)-1;
		        else rmid=ri+(rsize/2);
				BtoD(ri,rmid,ci,cf);
				BtoD(rmid+1,rf,ci,cf);
		   }
		}
	}
	
}
void paint(int c,int ri,int rf,int ci,int cf)
{
	for(int i=ri;i<=rf;i++)
	 for(int j=ci;j<=cf;j++)
		 bmap[i][j]=c;
}
void process(int ri,int rf,int ci,int cf)
{
	int rsize,csize,rmid,cmid;
	
	rsize=rf-ri+1;
	csize=cf-ci+1;
    if(rsize%2==0)rmid=ri+(rsize/2)-1;
		else rmid=ri+(rsize/2);
	if(csize%2==0)cmid=ci+(csize/2)-1;
		else cmid=ci+(csize/2);
	if(in[cur]=='1')
	{paint(1,ri,rf,ci,cf);cur++;}
	else if(in[cur]=='0')
	{paint(0,ri,rf,ci,cf);cur++;}
    else if(rsize!=1&&csize!=1)
	{
		cur++;
	    process(ri,rmid,ci,cmid);
		process(ri,rmid,cmid+1,cf);
		process(rmid+1,rf,ci,cmid);
		process(rmid+1,rf,cmid+1,cf);
	}
	else
	{
		cur++;
		if(rsize==1)
		{
			process(ri,rf,ci,cmid);
			process(ri,rf,cmid+1,cf);
		}
		else 
		{
			process(ri,rmid,ci,cf);
			process(rmid+1,rf,ci,cf);
		}
	}
   
}

int main()
{
	int i,j,count;
	string temp;
	char f,inp;
	cin>>f;
	cin>>r>>c;
	while(1)
	{
        if(f=='#') break;
		if(f=='B')
		{
			for(i=0;i<r;i++)
			   for(j=0;j<c;j++)
			   { cin>>inp;bmap[i][j]=inp-'0';}
		       cin>>f;
			   out.clear();
			   BtoD(0,r-1,0,c-1);
			   cout<<"D";
			   if(r/10==0)
				   cout<<"   ";
			   else cout<<"  ";
			   cout<<r;
			   if(c/10==0)
				   cout<<"   ";
			   else cout<<"  ";
			   cout<<c<<endl;
			   for(i=0,count=0;i<out.size();i++)
			   {
				   cout<<out[i];
				   count++;
				   if(count==50){cout<<endl;count=0;}
				   
			   }
			   cout<<endl;
		}
	    else if(f=='D')
		{
			f='0';
			in.clear();
			while(true)
			{
				cin>>temp;
				if(temp=="D"||temp=="B"||temp=="#"){f=temp[0];break;}					
				in+=temp;
				if(temp.size()<50)break;
			}
		    cur=0;
        	process(0,r-1,0,c-1);
			count =0;
			cout<<"B";
			   if(r/10==0)
				   cout<<"   ";
			   else cout<<"  ";
			   cout<<r;
			   if(c/10==0)
				   cout<<"   ";
			   else cout<<"  ";
			   cout<<c<<endl;
            for(i=0;i<r;i++)
              for(j=0;j<c;j++)
			  {
				  cout<<bmap[i][j];
				  count++;
				  if(count==50){count=0;cout<<endl;}
			  }	
			    if(count!=0)cout<<endl;
            	if(f=='0')cin>>f;		
		}

		if(f=='#')break;
		cin>>r>>c;
	}
    return 0;	
}