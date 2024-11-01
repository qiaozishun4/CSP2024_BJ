#include<bits/stdc++.h>
using namespace std;
int a[20]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		bool flag=false;
		long long ans=0;
		for(int i=0;i<=int(1e6*1.5);i++)
		{
			long long sum=0;
			int d=i;
			while(d)
			{
				sum+=a[d%10];
				d/=10;
			}
			if(sum==n)
			{
				flag=true;
				ans=i;
				break;
			}
		}
		if(!flag)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<ans<<endl;
		}
	}
	return 0;
}
