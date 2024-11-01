#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,t;
	cin>>t;
	while(t--)
	{
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++) cout<<8;
		}
		else if(n%7==1)
		{
			cout<<1<<0;
			for(int i=1;i<=n/7-1;i++) cout<<8;
		}
	}
	return 0;
}
