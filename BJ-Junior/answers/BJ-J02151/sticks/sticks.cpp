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
		bool flag=false;
		if(n==1)
		{
			cout<<-1<<endl;
			flag=true;
		}
		if(n%7==0&&flag==false)
		{
			for(int i=1;i<=n/7;i++)cout<<8;
			cout<<endl;
			flag=true;
		}
		else if(n%7==1&&flag==false)
		{
			cout<<"10";
			for(int i=1;i<=(n-8)/7;i++)cout<<8;
			cout<<endl;
			flag=true;
		}
		else if(n%7==2&&flag==false)
		{
			cout<<1;
			for(int i=1;i<=(n-2)/7;i++)cout<<8;
			cout<<endl;
			flag=true;
		}
		else if(n%7==3&&flag==false)
		{
			cout<<"7";
			for(int i=1;i<=(n-10)/7;i++)cout<<8;
			cout<<endl;
			flag=true;
		}
		else if(n%7==4&&flag==false)
		{
			cout<<"20";
			for(int i=1;i<=(n-11)/7;i++)cout<<8;
			cout<<endl;
			flag=true;
		}
		else if(n%7==5&&flag==false)
		{
			cout<<2;
			for(int i=1;i<=(n-5)/7;i++)cout<<8;
			cout<<endl;
			flag=true;
		}
		else if(n%7==6&&flag==false)
		{
			cout<<6;
			for(int i=1;i<=(n-6)/7;i++)cout<<8;
			cout<<endl;
			flag=true;
		}
	}
	return 0;
}
//5 1 2 3 6 18