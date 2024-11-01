#include<bits/stdc++.h>
using namespace std;
int main()
{
	
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int K=1;K<=T;K++)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(n==2)
		{
			cout<<1<<endl;
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
		if(n==6)
		{
			cout<<6<<endl;
			continue;
		}
		if(n==7)
		{
			cout<<8<<endl;
			continue;
		}
		int d=n/7-1;
		int x=n%7+7;
		if(x==10)
		{
			d--;
			cout<<20;
			for(int i=1;i<=d;i++)
			{
				cout<<8;
			}
			cout<<0;
		}
		else
		{
			
			if(x==8)
			{
				cout<<10;
			}
			if(x==9)
			{
				cout<<18;
			}
			if(x==11)
			{
				cout<<20;
			}
			if(x==12)
			{
				cout<<28;
			}
			if(x==13)
			{
				cout<<68;
			}
			if(x==14)
			{
				cout<<88;
			}
			for(int i=1;i<=d;i++)
			{
				cout<<8;
			}
		}
		cout<<endl;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
