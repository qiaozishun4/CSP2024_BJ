#include<bits/stdc++.h>
//#define int long long
using namespace std;
int t,n,l;
signed main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(cin>>t;t;t--)
	{
		cin>>n;
		l=n/7;
		if(n==1)
		{
			cout<<"-1\n";
		}
		else if(n==2)
		{
			cout<<"1\n";
		}
		else if(n==3)
		{
			cout<<"7\n";
		}
		else if(n==4)
		{
			cout<<"4\n";
		}
		else if(n==5)
		{
			cout<<"2\n";
		}
		else if(n==6)
		{
			cout<<"6\n";
		}
		else if(n%7==0)
		{
			for(int i=1;i<=l;i++)
			{
				cout<<"8";
			}
			cout<<"\n";
		}
		else if(n%7==1)
		{
			cout<<"10";
			for(int i=1;i<l;i++)
			{
				cout<<"8";
			}
			cout<<"\n";
		}
		else if(n%7==2)
		{
			cout<<"1";
			for(int i=1;i<=l;i++)
			{
				cout<<"8";
			}
			cout<<"\n";
		}
		else if(n%7==3)
		{
			cout<<"22";
			for(int i=1;i<l;i++)
			{
				cout<<"8";
			}
			cout<<"\n";
		}
		else if(n%7==4)
		{
			cout<<"20";
			for(int i=1;i<l;i++)
			{
				cout<<"8";
			}
			cout<<"\n";
		}
		else if(n%7==5)
		{
			cout<<"2";
			for(int i=1;i<=l;i++)
			{
				cout<<"8";
			}
		}
		else
		{
			cout<<"6";
			for(int i=1;i<=l;i++)
			{
				cout<<"8";
			}
		}
	}
	exit(0);
}