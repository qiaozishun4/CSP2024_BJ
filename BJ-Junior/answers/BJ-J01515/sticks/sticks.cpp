#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	int tt=1;
	while(tt<=T)
	{
		cin>>n;
		int tmp=n/7;
		if(n%7==0)
		{
			if(n==0)
			{
				cout<<-1<<endl;
			}
			else
			{
				for(int i=1;i<=tmp;i++)
				{
					cout<<8;
				}
				cout<<endl;
			}
		}
		else if(n%7==1)
		{
			if(n==1)
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<1<<0;
				for(int i=1;i<=tmp-2;i++)
				{
					cout<<8;
				}
				cout<<endl;
			}
		}
		else if(n%7==2)
		{
			cout<<1;
			for(int i=1;i<=tmp-1;i++)
			{	
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==3)
		{
			cout<<7;
			for(int i=1;i<=tmp-1;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==4)
		{
			cout<<4;
			for(int i=1;i<=tmp-1;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==5)
		{
			cout<<2;
			for(int i=1;i<=tmp-1;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==6)
		{
			cout<<6;
			for(int i=1;i<=tmp-1;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		tt++;
	}
	return 0;
}