#include<bits/stdc++.h>
using namespace std;
int t,n;
int f[15]={0,-1,1,7,4,2,6,8,10,18,22};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<=10)
		{
			cout<<f[n]<<endl;
			continue;
		}
		if(n%7==1)
		{
			cout<<10;
			for(int i=1;i<=n/7-1;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==2)
		{
			cout<<1;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==3)
		{
			cout<<200;
			for(int i=1;i<=n/7-2;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==4)
		{
			cout<<20;
			for(int i=1;i<=n/7-1;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==5)
		{
			cout<<2;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==6)
		{
			cout<<6;
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}
	}
	return 0;
}
