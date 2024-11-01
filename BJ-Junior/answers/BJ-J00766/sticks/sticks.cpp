#include<bits/stdc++.h>
using namespace std;
int t,n,ans,i;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%7 == 0)
		{
			n/=7;
			for(i = 1;i<=n;i++)
			{
				cout<<8;
			}
		}
		else if(n%7 == 1)
		{
			n-=8;
			if(n<0)
			{
				cout<<-1;
			}
			else
			{
				cout<<10;
				n/=7;
				for(i = 1;i<=n;i++)
				{
					cout<<8;
				}
			}
		}
		else if(n%7 == 2)
		{
			n-=2;
			if(n<0)
			{
				cout<<-1;
			}
			else
			{
				cout<<1;
				n/=7;
				for(i = 1;i<=n;i++)
				{
					cout<<8;
				}
			}
		}
		else if(n%7 == 3)
		{
			if(n == 3)
			{
				cout<<7<<'\n';
				continue;
			}
			if(n == 10)
			{
				cout<<22<<'\n';
				continue;
			}
			n-=17;
			if(n<0)
			{
				cout<<-1;
			}
			else
			{
				cout<<200;
				n/=7;
				for(i = 1;i<=n;i++)
				{
					cout<<8;
				}
			}
		}
		else if(n%7 == 4)
		{
			if(n == 4)
			{
				cout<<4<<'\n';
				continue;
			}
			n-=11;
			if(n<0)
			{
				cout<<-1;
			}
			else
			{
				cout<<20;
				n/=7;
				for(i = 1;i<=n;i++)
				{
					cout<<8;
				}
			}
		}
		else if(n%7 == 5)
		{
			n-=5;
			if(n<0)
			{
				cout<<-1;
			}
			else
			{
				cout<<2;
				n/=7;
				for(i = 1;i<=n;i++)
				{
					cout<<8;
				}
			}
		}
		else if(n%7 == 6)
		{
			n-=6;
			if(n<0)
			{
				cout<<-1;
			}
			else
			{
				cout<<6;
				n/=7;
				for(i = 1;i<=n;i++)
				{
					cout<<8;
				}
			}
		}
		cout<<'\n';
	}
}