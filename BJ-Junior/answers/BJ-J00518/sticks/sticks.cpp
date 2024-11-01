#include <bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,i,j,k,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n%7==0)
		{
			for(i=1;i<=n/7;i++) cout<<8;
		}
		else if(n%7==1)
		{
			cout<<10;
			for(i=1;i<=n/7;i++) cout<<8;
		}
	}

}