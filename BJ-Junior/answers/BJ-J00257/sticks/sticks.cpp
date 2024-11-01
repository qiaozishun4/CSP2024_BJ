#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
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
		if(n == 1)
		{
			cout<<-1<<endl;
		}
		else if(n == 2)
		{
			cout<<1<<endl;
		}
		else if(n == 3)
		{
			cout<<7<<endl;
		}
		else if(n == 4)
		{
			cout<<4<<endl;
		}
		else if(n == 5)
		{
			cout<<2<<endl;
		}
		else if(n == 6)
		{
			cout<<6<<endl;
		}
		else if(n == 7)
		{
			cout<<8<<endl;
		}
		else
		{
			int x = n % 7;
			if(x == 0)
			{
				while(n != 0)
				{
					n -= 7;
					cout<<8;
				}
				cout<<endl;
			}
			else if(x == 1)
			{
				cout<<"10";
				while(n > 8)
				{
					n -= 7;
					cout<<8;
				}
				cout<<endl;
			}
			else if(x == 2)
			{
				cout<<"18";
				while(n > 9)
				{
					n -= 7;
					cout<<8;
				}
				cout<<endl;
			}
			else if(x == 3)
			{
				cout<<"22";
				while(n > 10)
				{
					n -= 7;
					cout<<8;
				}
				cout<<endl;
			}
			else if(x == 4)
			{
				cout<<"20";
				while(n > 11)
				{
					n -= 7;
					cout<<8;
				}
				cout<<endl;
			}
			else if(x == 5)
			{
				cout<<"28";
				while(n > 12)
				{
					n -= 7;
					cout<<8;
				}
				cout<<endl;
			}
			else if(x == 6)
			{
				cout<<"80";
				while(n > 13)
				{
					n -= 7;
					cout<<8;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
