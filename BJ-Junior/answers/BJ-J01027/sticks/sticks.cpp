#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)
	{
		memset(a,0,sizeof(a));
		int n,pos=0,cnt=0;
		scanf("%d",&n);
		if (n==1)
		{
			printf("-1\n");
			continue;
		}
		if (n==n/7*7+1)
		{
			if (n==8)
			{
				printf("10\n");
				continue;
			}
			printf("10");
			n-=8;
			while (n!=0)
			{
				printf("8");
				n-=7;
			}
			printf("\n");
			continue;
		}
		while (n>=7)
		{
			if (2*7>n&&n%7!=0)
			{
				break;
			}
			n-=7;
			pos++;
			a[pos]=8;
		}
		while (n>=6)
		{
			n-=6;
			cnt++;
		}
		while (n>=5)
		{
			n-=5;
			pos++;
			a[pos]=2;
		}
		while (n>=4)
		{
			n-=4;
			pos++;
			a[pos]=4;
		}
		while (n>=3)
		{
			n-=3;
			pos++;
			a[pos]=7;
		}
		while (n>=2)
		{
			n-=2;
			pos++;
			a[pos]=1;
		}
		while (n>=7)
		{
			n-=7;
			pos++;
			a[pos]=8;
		}
		while (n>=6)
		{
			n-=6;
			cnt++;
		}
		while (n>=5)
		{
			n-=5;
			pos++;
			a[pos]=2;
		}
		while (n>=4)
		{
			n-=4;
			pos++;
			a[pos]=4;
		}
		while (n>=3)
		{
			n-=3;
			pos++;
			a[pos]=7;
		}
		while (n>=2)
		{
			n-=2;
			pos++;
			a[pos]=1;
		}
		if (n!=0)
		{
			printf("-1\n");
			continue;
		}
		sort(a+1,a+pos+1);
		if (a[1]>6)
		{
			if (cnt!=0)
			{
				printf("6");
				for (int i=1;i<=cnt;i++)
				{
					printf("0");
				}
				for (int i=1;i<=pos;i++)
				{
					printf("%d",a[i]);
				}
				printf("\n");
			}
			else
			{
				for (int i=1;i<=pos;i++)
				{
					printf("%d",a[i]);
				}
				printf("\n");
			}
		}
		else
		{
			if (a[1]==0)
			{
				a[1]=6;
				cnt-=1;
			}
			printf("%d",a[1]);
			for (int i=1;i<=cnt;i++)
			{
				printf("0");
			}
			for (int i=2;i<=pos;i++)
			{
				printf("%d",a[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
