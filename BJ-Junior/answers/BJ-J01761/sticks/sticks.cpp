#include<bits/stdc++.h>
using namespace std;
int a[15]={0,-1,1,7,4,2,6,8};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,k,l;
		cin>>n;
		if(n<=7)
		{
			cout<<a[n]<<'\n';
			continue;
		}
		k=n%7,l=n/7;
		if(k==0) 
		{
			for(int i=1;i<=l;i++) 
				cout<<8;
		}
		else if(k==1)
		{
			cout<<10;
			for(int i=1;i<=l-1;i++)
				cout<<8;
		}
		else if(k==2)
		{
			cout<<1;
			for(int i=1;i<=l;i++)
				cout<<8;
		}
		else if(k==3)
		{
			if(n==10) cout<<22;
			else
			{
				cout<<206;
				for(int i=1;i<=l-2;i++)
					cout<<8;
			}
		}
		else if(k==4)
		{
			cout<<20;
			for(int i=1;i<=l-1;i++)
				cout<<8;
		}
		else if(k==5)
		{
			cout<<2;
			for(int i=1;i<=l;i++)
				cout<<8;
		}
		else if(k==6)
		{
			cout<<6;
			for(int i=1;i<=l;i++)
				cout<<8;
		}
		cout<<'\n';
	}
	return 0;
}
