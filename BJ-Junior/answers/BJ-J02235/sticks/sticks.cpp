#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n<2) cout<<"-1";
		else if(n==3) cout<<'7';
		else if(n==4) cout<<'4';
		else if(n==5) cout<<'2';
		else if(n==6) cout<<'6';
		else if(n%7==0)
		{
			while(n)
			{
				n-=7;
				cout<<'8';
			}
		}
		else if(n%7==1)
		{
			cout<<"10";
			n-=8;
			while(n)
			{
				n-=7;
				cout<<'8';
			}
		}
		else if(n%7==2)
		{
			cout<<'1';
			n-=2;
			while(n)
			{
				n-=7;
				cout<<'8';
			}
		}
		else if(n%7==3)
		{
			cout<<"22";
			n-=10;
			while(n)
			{
				n-=7;
				cout<<'8';
			}
		}
		else if(n%7==4)
		{
			cout<<"20";
			n-=11;
			while(n)
			{
				n-=7;
				cout<<'8';
			}
		}
		else if(n%7==5)
		{
			cout<<'2';
			n-=5;
			while(n)
			{
				n-=7;
				cout<<'8';
			}
		}
		else if(n%7==6)
		{
			cout<<'6';
			n-=6;
			while(n)
			{
				n-=7;
				cout<<'8';
			}
		}
		cout<<endl;
	}
	return 0;
}