#include<bits/stdc++.h>
using namespace std;
int T,n;
string s;
int f(int x)
{
	if(x==6) return 6;
	if(x==5) return 2;
	if(x==4) return 4;
	if(x==3) return 7;
	if(x==2) return 1;
	return -1;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--)
	{
		s="";
		cin>>n;
			if(n<7) cout<<f(n)<<endl;
			else
			{
				if(n%7==0)
				{
					for(int i=n;i>0;i-=7) cout<<8;
					cout<<endl;
				}
				else if(n%7==1)
				{
					cout<<10;
					for(int i=n-8;i>0;i-=7) cout<<8;
					cout<<endl;
				}
				else if(n%7==2)
				{
					cout<<1;
					for(int i=n-2;i>0;i-=7) cout<<8;
					cout<<endl;
				}
				else if(n%7==3)
				{
					if(n==10) cout<<22;
					else cout<<200;
					for(int i=n-17;i>0;i-=7) cout<<8;
					cout<<endl;
				}
				else if(n%7==4)
				{
					cout<<20;
					for(int i=1;i<=(n-11)/7;i++) cout<<8;
					cout<<endl;
				}
				else if(n%7==5)
				{
					cout<<2;
					for(int i=n-5;i>0;i-=7) cout<<8;
					cout<<endl;
				}
				else
				{
					cout<<6;
					for(int i=n-6;i>0;i-=7) cout<<8;
					cout<<endl;
				}
		}
	}
	return 0;
}
