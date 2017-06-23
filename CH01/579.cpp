#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int h,m;
	float hour,mins,ans;
	string input;
	while(1)
	{
		input.clear();
		cin>>input;
		if(input=="0:00")
			break;
		if(input[2]==':')
		{
			h=(input.at(0)-'0')*10+(input.at(1)-'0');
			m=(input.at(3)-'0')*10+(input.at(4)-'0');
		}
		else
		{
			h=(input.at(0)-'0');
			m=(input.at(2)-'0')*10+(input.at(3)-'0');
		}
		hour=(float)h*30+m*0.5;
		mins=((float)m*6);
		ans=hour-mins;
		ans=ans<0?(-1*ans):ans;
		if(ans>180)
			ans=360-ans;
		cout.setf(ios::fixed,ios::floatfield);
        cout.precision(3);
        cout <<ans<< endl;
	}
	return 0;
}