#include<iostream>
using namespace std;
int main()
{
	//freopen("sticks.in","r",stdin);
	//freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			if(n%7==2)
			{
				cout<<1;
				n-=2;
			}
			if(n%7==3)
			{
				cout<<7;
				n-=3;
			}
			if(n%7==4)
			{
				cout<<4;
				n-=4;
			}
			if(n%7==5)
			{
				cout<<2;
				n-=5;
			}
			if(n%7==6 && j==1)
			{
				cout<<6;
				n-=6;
			}
			if(n%7==6 && j!=1)
			{
				cout<<0;
				n-=6;
			}
			else 
			{
				cout<<2;
				n-=5;
			}
		}
		cout<<endl;
	}
	return 0;
}
