#include<iostream>
#include<stack>
using namespace std;
int main()
{
	string input;
	int i,j,ans,n=0;
	while(1)
	{
		n++;
		stack<char>s[26];
		cin>>input;
		if(input=="end")break;
		ans=0;
		for(i=0;i<input.length();i++)
		{
			for(j=0;j<26;j++)
			{
				if(s[j].empty())
				{
					s[j].push(input[i]);
					ans++;
					break;
				}
				else 
				{
					if(input[i]<=s[j].top()){
						s[j].push(input[i]);
						break;
					}
				}
			}
		}
		cout<<"Case "<<n<<": "<<ans<<endl;
	}
	return 0;
}