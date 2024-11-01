#include<bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n==1)
		{
			cout<<-1<<'\n';
		}
		else
		{
			if(n%7==0)
			{
				for(int i=1;i<=n/7;i++)
				{
					cout<<8;
				}
				cout<<'\n';
			}
			if(n%7==1)
			{
				cout<<10;
				for(int i=1;i<=(n-8)/7;i++)
				{
					cout<<8;
				}
				cout<<'\n';
			}
			if(n%7==2)
			{
				cout<<;
				for(int i=1;i<=(n-3)/7;i++)
				{
					cout<<8;
				}
				cout<<'\n';
			}
			if(n%7==3)
			{
				cout<<7;
				for(int i=1;i<=(n-)/7;i++)
				{
					cout<<8;
				}
				cout<<'\n';
			}
			if(n%7==4)
			{
				cout<<4;
				for(int i=1;i<=(n-4)/7;i++)
				{
					cout<<8;
				}
				cout<<'\n';
			}
			if(n%7==5)
			{
				cout<<2;
				for(int i=1;i<=(n-5)/7;i++)
				{
					cout<<8;
				}
				cout<<'\n';
			}
			if(n%7==6)
			{
				cout<<6;
				for(int i=1;i<=(n-6)/7;i++)
				{
					cout<<8;
				}
				cout<<'\n';
			}
		}
	}
	return 0;
}