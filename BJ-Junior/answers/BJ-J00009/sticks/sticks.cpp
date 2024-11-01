#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ls[]={6,2,5,5,4,5,6,3,7,6};
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
		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		int x=n%7;
		if(!x)
		{
			for(int i=1;i<=n/7;i++) printf("8");
			printf("\n");
		}
		else if(x==1)
		{
			printf("10");
			for(int i=1;i<=(n-8)/7;i++) printf("8");
			printf("\n");
		}
		else if(x==2)
		{
			printf("1");
			for(int i=1;i<=(n-2)/7;i++) printf("8");
			printf("\n");
		}
		else if(x==3)
		{
			if(n==3)
			{
				printf("7\n");
				continue;
			}
			printf("22");
			for(int i=1;i<=(n-10)/7;i++) printf("8");
			printf("\n");
		}
		else if(x==4)
		{
			if(n==4)
			{
				printf("4\n");
				continue;
			}
			printf("20");
			for(int i=1;i<=(n-11)/7;i++) printf("8");
			printf("\n");
		}
		else if(x==5)
		{
			printf("2");
			for(int i=1;i<=(n-5)/7;i++) printf("8");
			printf("\n");
		}
		else if(x==6)
		{
			printf("6");
			for(int i=1;i<=(n-6)/7;i++) printf("8");
			printf("\n");
		}
	}
	/*
	for(int i=8;i<=13;i++)
	{
		for(int j=1;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(ls[j]+ls[k]==i) cout<<'*'<<i<<' '<<j<<k<<'\n';
			}
		}
	}*/
	return 0;
}
