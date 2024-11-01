#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
map<string ,int >mp;
int main()
{
	freopen("sticks.in","w",stdin);
	freopen("sticks.out","r",stdout);
	int t,n;
	//XD how to judge similary,only by code?cant someyone think together?
	cin>>t;
	while(t--)
	{
		cin>>n;
		if((n-1)%7==0)
		{
			cout<<10;
			for(int i=1;i<=(n-8)/7;i++)
				cout<<8;
		}
		else if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)
				cout<<8;
		}
		else
		{
			cout<<-1;
		}
		cout<<endl;
		
	}


	return 0;
}
