#include<bits/stdc++.h>
using namespace std;
long long n,x;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>x;
		if(x%7==0)	
		{
			int sum=x/7;
			for(int j=1;j<=sum;j++)	cout<<8;
			cout<<endl;
		}
		if(x%7==1)
		{
			int sum=x/7;
			cout<<10;
			for(int j=2;j<=sum;j++)		cout<<8;
			cout<<endl;
		}
	}

    return 0;
}
