#include <bits/stdc++.h>
using namespace std;
int h[]={6,2,5,5,4,5,6,3,7,6};
int calc(int n)
{
	int sum=0;
	while(n)
	{
		sum+=h[n%10];
		n/=10;
	}
	return sum;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >>t;
	while(t--)
	{
		int n;
		cin >>n;
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)
			{
				cout <<8;
			}
			cout <<"\n";
			continue;
		}
		bool flag=true;
		for(int i=1;i<=200000;i++)
		{
			if(calc(i)==n)
			{
				cout <<i<<"\n";
				flag=false;
				break;
			}
		}
		if(flag)
		{
			cout <<"-1\n";
		}
	}
	return 0;
}
