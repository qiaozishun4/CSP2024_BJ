#include<bits/stdc++.h>
using namespace std;
int n,T;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n%7==0)
		{
			if(n==0) printf("-1");
			else for(int i=1;i<=n/7;i++) printf("8");
		}
		else if(n%7==1)
		{
			if(n==1) printf("-1");
			else
			{
				printf("10");
				for(int i=1;i<n/7;i++) printf("8");
			}
		}
		else if(n%7==2)
		{
			printf("1");
			for(int i=1;i<=n/7;i++) printf("8");
		}
		else if(n%7==3)
		{
			if(n/7>=2)
			{
				printf("200");
				for(int i=1;i<=n/7-2;i++) printf("8");
			}
			else if(n/7==1) printf("22");
			else printf("7");
		}
		else if(n%7==4)
		{
			if(n/7>=1)
			{
				printf("20");
				for(int i=1;i<n/7;i++) printf("8");
			}
			else printf("4");
		}
		else if(n%7==5)
		{
			printf("2");
			for(int i=1;i<=n/7;i++) printf("8");
		}
		else if(n%7==6&&n/7>=1)
		{
			printf("80");
			for(int i=1;i<n/7;i++) printf("8");
		}
		else printf("0");
		printf("\n");
	}
	return 0;
}
