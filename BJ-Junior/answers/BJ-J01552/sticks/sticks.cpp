#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n>=7)
		{
			int o=n/7;
			if(n%7==0) while(o--) cout<<8;
			else
			{
				if(n%7==1) cout<<10;
				if(n%7==2) cout<<18;
				if(n%7==3) cout<<22;
				if(n%7==4) cout<<20;
				if(n%7==5) cout<<28;
				if(n%7==6) cout<<68;
				o--;
				while(o--) cout<<8;
			}
		}
		else
		{
			if(n==1) cout<<-1;
			if(n==2) cout<<1;
			if(n==3) cout<<7;
			if(n==4) cout<<4;
			if(n==5) cout<<2;
			if(n==6) cout<<6;
		}
	}
	return 0;
}
