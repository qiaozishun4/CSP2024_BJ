#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	cin>>T;
	for(int x=1;x<=T;x++)
	{
		cin>>n;
		if(n==1) 
		{
			cout<<-1<<endl;
			continue;
		}
		if(n==3) 
		{
			cout<<7<<endl;
			continue;
		}
		if(n==4)
		{
			cout<<4<<endl;
			continue;
		}
		if(n==5)
		{
			cout<<2<<endl;
			continue;
		}
		if(n%7==0) 
		{
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==1)
		{
			cout<<10;
			for(int i=1;i<(n-1)/7;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==2)
		{
			cout<<1;
			for(int i=1;i<=(n-2)/7;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==3)
		{
			cout<<22;
			for(int i=1;i<(n-3)/7;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==4)
		{
			cout<<20;
			for(int i=1;i<(n-4)/7;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==5)
		{
			cout<<28;
			for(int i=1;i<(n-5)/7;i++)cout<<8;
			cout<<endl;
		}
		else if(n%7==6)
		{
			cout<<6;
			for(int i=1;i<=(n-6)/7;i++)cout<<8;
			cout<<endl;
		}
	}
	
	return 0;
}
