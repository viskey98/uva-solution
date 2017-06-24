#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> curr,in;
bool start;
int t,sum,n;
bitset<12>used;
void Print()
{
   start=true;
   for(int i=0;i<curr.size();i++)
    {
        if(i)cout<<'+';
        cout<<curr[i];
    }
    cout<<endl;
 
}
int isleft(int a,int i)
{
   for(i--;i>=0;i--)
   if(in[i]==a&&used[i]==0)
   break;
   if(i==-1)
   return 0;
   else return 1;
}
int backtrack(int i)
{
    int j,tmp;
    for(j=i;j<n;j++)
    {
        if(used[j]!=1&&!isleft(in[j],j))
        {
           if(sum+in[j]>t)
           continue;
           if(sum+in[j]==t)
           {
           sum+=in[j];
           curr.push_back(in[j]);
           Print();
           curr.pop_back();
           sum-=in[j];
           }
           else
           {
             curr.push_back(in[j]);
             used[j]=1;
             sum+=in[j];
             backtrack(j+1);
             curr.pop_back();
             used[j]=0;
             sum-=in[j];
           }
        }
        
    }
    
}
int main()
{

    int i,temp;
    while(1)
    {
       in.clear();sum=0;start=false;used.reset();
       curr.clear();
       cin>>t>>n;
       if(t==0)break;
       for(i=0;i<n;i++)
          {cin>>temp;in.push_back(temp);}
       printf("Sums of %d:\n",t);
       backtrack(0);
       if(!start)cout<<"NONE"<<endl;   
    }
    return 0;
}




