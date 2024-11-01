#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,d[]={0,0,1,7,4,2,6,8},b[]={6,2,5,5,4,5,6,3,7,6},w,m,x,y;
signed main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(cin>>t;t;--t)
	{
		cin>>n;
		if(n==1) cout<<-1;
		else if(n/7==0)
		{
			printf("%lld",d[n]);
		}
		else if(n%7==0)
		{
			for(int i=1;i<=n/7;++i)
			{
				printf("%d",8);
			}
		}
		else if(n%7==1)
		{
			printf("%d",10);
			for(int i=1;i<=n/7-1;++i) printf("%d",8);
		}
		else if(n%7==3)
		{
			if(n/7==1) printf("%d",22);
			else
			{
				printf("%d",200);
				for(int i=1;i<=n/7-2;++i) printf("%d",8);
			}
		}
		else if(n%7==4)
		{
			printf("%d",20);
			for(int i=1;i<=n/7-1;++i) printf("%d",8);
		}
		else if(n%7==2)
		{
			printf("%d",1);
			for(int i=1;i<=n/7;++i)
			{
				printf("%d",8);
			}
		}
		else if(n%7==5)
		{
			printf("%d",2);
			for(int i=1;i<=n/7;++i)
			{
				printf("%d",8);
			}
		}
		else if(n%7==6)
		{
			printf("%d",6);
			for(int i=1;i<=n/7;++i)
			{
				printf("%d",8);
			}
		}
		cout<<endl;
	}
	return 0;
}