#include <bits/stdc++.h>
using namespace std;

int a[10]={0,1,2,3,4,5,6,7,8,9};
int h[10]={6,2,5,0,4,0,6,3,7,0};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>x;
		int v=x/7+(x%7!=0);
		int v1=v*7-x,j=0;
		for(int j1=1;j1<=v;j1++)
		{
			s+='8';
		}
		if(x<7)
		{
			if(x==6)
			{
				cout<<6<<endl;
			}
			else if(x==5)
			{
				cout<<2<<endl;
			}
			else if(x==4)
			{
				cout<<4<<endl;
			}
			else if(x==3)
			{
				cout<<7<<endl;
			}
			else if(x==2)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<-1<<endl;
			}
			continue;
		}
		if(v1>=5)
		{
			s[0]='1';
			v1-=5;
		}
		else if(v1>=2)
		{
			s[0]='2';
			v1-=2;
		}
		else if(v1>=1)
		{
			s[0]='6';
			v1-=1;
		}
		while(v1>0)
		{
			if(v1>=5)
			{
				s[++j]='1';
				v1-=5;
			}
			else if(v1>=2)
			{
				s[++j]='2';
				v1-=2;
			}
			else if(v1>=1)
			{
				s[++j]='0';
				v1-=1;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
