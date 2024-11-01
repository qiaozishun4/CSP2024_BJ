#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	int t,n,q,r;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
		{
			cout<<"-1\n";
			continue;
		}
		q=(n-1)/7+1;
		r=q*7-n;
		for(int i=1;i<q;i++)
		{
			if(r>=1&&i!=1)
			{
				cout<<0;
				r-=1;
			}
			else if(r>=5)
			{
				cout<<1;
				r-=5;
			}
			else if(r>=2)
			{
				cout<<2;
				r-=2;
			}
			else if(r>=3)
			{
				cout<<4;
				r-=3;
			}
			else if(r>=1&&i==1)
			{
				cout<<6;
				r-=1;
			}
			else if(r>=4)
			{
				cout<<7;
				r-=4;
			}
			else
				cout<<8;
		}
		if(r==1)
		{
			if(q!=1)
				cout<<0;
			else
				cout<<6;
		}
		else if(r==2)
			cout<<2;
		else if(r==3)
			cout<<4;
		else if(r==4)
			cout<<7;
		else if(r==5)
			cout<<1;
		else
			cout<<8;
		cout<<'\n';
	}
	return 0;
}