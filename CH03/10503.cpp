#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int m,t,n,us;
vector <int> l,r,curr;
vector <vector<int> > piece;
bool start;
bitset <14> used;
void backtrack()
{
	vector <int> pr;
   
    if(start)return;
    if(t==n)
    {
       if(curr[1]==r[0])
       {cout<<"YES\n";start=true;return;}
    }
   
    for(int i=0;i<m;i++)
    {
       if(start)return;
       if(used[i]!=1&&(curr[1]==piece[i][0]||curr[1]==piece[i][1]))
       {
          pr.clear();pr.push_back(curr[0]);pr.push_back(curr[1]);
          if(curr[1]==piece[i][0])
           us=0;
          else us=1;
          curr.clear(); curr.push_back(piece[i][us]);curr.push_back(piece[i][1-us]);
          used[i]=1;
          t++;
          backtrack();
          t--;
          used[i]=0;
          curr.clear();curr.push_back(pr[0]);curr.push_back(pr[1]);
       }
    }
}  
       
int main()
{
    while(1)
    {
       
       int temp1,temp2;
       cin>>n;
       if(n==0)break;
       cin>>m;
       piece.clear();used.reset();piece.clear();start=false;
       t=0;
       cin>>temp1>>temp2;
       l.clear();
       l.push_back(temp1);l.push_back(temp2);
       cin>>temp1>>temp2;
       r.clear();
       r.push_back(temp1);r.push_back(temp2);
       for(int i=0;i<m;i++)
       {curr.clear();cin>>temp1;cin>>temp2;
        curr.push_back(temp1);curr.push_back(temp2);
        piece.push_back(curr);
       }
       curr.clear();curr.push_back(l[0]);curr.push_back(l[1]);
       us=0;
       backtrack();
       if(!start)cout<<"NO\n";
    }
    return 0;
}