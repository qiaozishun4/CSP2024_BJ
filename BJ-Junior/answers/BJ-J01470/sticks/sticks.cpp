#include <bits/stdc++.h>
using namespace std;
int a[]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,408,208,288,688};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(x%7==0)
		{
			for(int i=1;i<=x/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else if(x%7==1)
		{
			cout<<10;
			for(int i=2;i<=x/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else if(x<=20)
		{
			cout<<a[x]<<endl;
		}
		else if(x%7==2)
		{
			cout<<1;
			for(int i=1;i<=x/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else if(x%7==3)
		{
			cout<<40;
			for(int i=2;i<=x/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else if(x%7==4)
		{
			cout<<20;
			for(int i=2;i<=x/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else if(x%7==5)
		{
			cout<<2;
			for(int i=1;i<=x/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else
		{
			cout<<6;
			for(int i=1;i<=x/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}