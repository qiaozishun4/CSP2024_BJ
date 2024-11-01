#include<bits/stdc++.h>

using namespace std;

int t, n;

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		if (n == 0)
			printf("-1\n");
		else if (n == 1)
			printf("-1\n");
		else if (n == 2)
			printf("1\n");
		else if (n == 3)
			printf("7\n");
		else if (n == 4)
			printf("4\n");
		else if (n == 5)
			printf("2\n");
		else if (n == 6)
			printf("6\n");
		else
		{
			if (n % 7 == 1)
			{
				n -= 8;
				printf("10");
			}
			if (n % 7 == 2)
			{
				n -= 9;
				printf("18");
			}
			if (n % 7 == 3)
			{
				n -= 10;
				printf("22");
			}
			if (n % 7 == 4)
			{
				n -= 11;
				printf("20");
			}
			if (n % 7 == 5)
			{
				n -= 12;
				printf("28");
			}
			if (n % 7 == 6)
			{
				n -= 13;
				printf("80");
			}
			while (n)
				printf("8"), n -= 7;
			printf("\n");
		}
	}

	return 0;
}