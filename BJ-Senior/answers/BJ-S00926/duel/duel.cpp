#include <bits/stdc++.h>
using namespace std;

int a[100005];
int b[100005];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	int last = a[1], cur = 1;
	b[cur] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] == last)
		{
			b[cur]++;
		}
		else 
		{
			cur++;
			b[cur]++;
		}
		last = a[i];
	}
	int dbt = b[1], dd = 0;; 
	for (int i = 2; i <= cur; i++)
	{
		if (b[i] >= dbt)
		{
			dd += dbt;
			dbt = b[i];
		}
		else
		{
			dd += b[i];
		}
	}
	cout << n - dd << endl;
	return 0;
}
