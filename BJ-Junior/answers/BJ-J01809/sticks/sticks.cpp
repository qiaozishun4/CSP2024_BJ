#include<bits/stdc++.h>
using namespace std;
string s[]={"","-1","1","7","4","2","6","8","10","18","22","20","28","68","88"},ss[]={"888","108","188","200","208","288","688"};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n<=14)
		{
			cout<<s[n]<<endl;
		}
		else
		{
			cout<<ss[n%7];
			if(n%7==0)n--;
			for(int i=1;i<=n/7-2;i++)
			{
				cout<<"8";
			}
			cout<<endl;
		}
	}
	return 0;
}