#include <bits/stdc++.h>
using namespace std;
int sticks[17]={0,6,2,5,5,4,5,6,3,7,6};
const int Nmax=1e5+7;
int a[Nmax];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=1)
		{
			cout<<"-1"<<endl;
		}
		else if(a[i]==2)
		{
			cout<<"1"<<endl;
		}
		else if(a[i]==3)
		{
			cout<<"7"<<endl;
		}
		else if(a[i]==4)
		{
			cout<<"4"<<endl;
		}
		else if(a[i]==5)
		{
			cout<<"3"<<endl;
		}
		else if(a[i]==6)
		{
			cout<<"6"<<endl;
		}
		else if(a[i]%7==0)
		{
			for(int j=1;j<=a[i]%7;j++)
			{
				cout<<8<<endl;
			}
		}
		else 
		{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}