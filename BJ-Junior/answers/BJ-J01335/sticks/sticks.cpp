#include <iostream>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	while (t--)
	{
		scanf("%d",&n);
		if (n==1) printf("-1\n");
		else if (n==3) printf("7\n");
		else if (n==4) printf("4\n");
		else if (n%7==0)
		{
			for (int i=7;i<=n;i+=7)
			{
				putchar('8');
			}
			putchar('\n');
		}
		else if (n%7==1)
		{
			putchar('1');
			putchar('0');
			n-=8;
			for (int i=7;i<=n;i+=7)
			{
				putchar('8');
			}
			putchar('\n');
		}
		else if (n%7==2)
		{
			putchar('1');
			n-=2;
			for (int i=7;i<=n;i+=7)
			{
				putchar('8');
			}
			putchar('\n');
		}
		else if (n%7==3)
		{
			putchar('2');
			putchar('2');
			n-=10;
			for (int i=7;i<=n;i+=7)
			{
				putchar('8');
			}
			putchar('\n');
		}
		else if (n%7==4)
		{
			putchar('2');
			putchar('0');
			n-=11;
			for (int i=7;i<=n;i+=7)
			{
				putchar('8');
			}
			putchar('\n');
		}
		else if (n%7==5)
		{
			putchar('2');
			n-=5;
			for (int i=7;i<=n;i+=7)
			{
				putchar('8');
			}
			putchar('\n');
		}
		else if (n%7==6)
		{
			putchar('6');
			n-=6;
			for (int i=7;i<=n;i+=7)
			{
				putchar('8');
			}
			putchar('\n');
		}
	}
	return 0;
}