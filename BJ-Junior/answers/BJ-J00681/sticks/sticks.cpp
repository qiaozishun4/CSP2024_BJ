#include <bits/stdc++.h>
using namespace std;

int n,a[10001];
int maxn = 1;

int find (int x)
{
	int i = 1;
	while(a[i] != 0)
	{
		if (a[i] == x)
		{
			return a[i];
		}
		i++;
	}
	return -1;
}

int stick(int num)
{
	int sum = 0;
	while (num > 0)
	{
		if (num % 10 == 6 || num % 10 == 9 || num % 10 == 0) sum += 6;
		else if (num % 10 == 1) sum += 2;
		else if (num % 10 == 2 || num % 10 == 5 || num % 10 == 3) sum += 5;
		else if (num % 10 == 4) sum += 4;
		else if (num % 10 == 8) sum += 7;
		else sum += 3;
		num /= 10;
	}
	return sum;
}

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int x;
		cin >> x;
		if (x == 1 || x == 0)
		{
			cout << "-1" << endl;
			continue;
 		}
		if (find(x) != -1)
		{
			cout << find(x) << endl;
		}
		else
		{
			int j;
			j = maxn - 1;
			while(a[j] != x)
			{
				j++;
				a[j] = stick(j);
			}
			maxn = j;
			cout << j << endl;
		}
	}
	return 0;
}