#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], c[N], ans, logs[N];
char s[30][N];

int solve(int len)
{
	vector<int> cur, lst;
	for (int i = 1; i <= len; i++)
		lst.push_back(i);
	for (int i = logs[len]; i > 0; i--)
	{
		int tl = 1 << (i - 1);
		for (int j = 0; j < tl; j++)
		{
			if (s[i][j] == '0')
				cur.push_back(a[lst[j * 2]] >= (logs[len] - i + 1) ? lst[j * 2] : lst[j * 2 + 1]);
			else
				cur.push_back(a[lst[j * 2 + 1]] < (logs[len] - i + 1) ? lst[j * 2] : lst[j * 2 + 1]);
		}
		swap(lst, cur);
		cur.clear();
	}
	return lst[0];
}

int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	logs[1] = 0;
	for (int i = 2; i <= 1e5; i++)
		logs[i] = logs[i >> 1] + 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", c + i);
	int k = logs[n];
	for (int i = k; i >= 0; i--)
	{
		scanf("%s", s[k]);
	}
	int T;
	cin >> T;
	int x[5];
	for (int i = 0; i <= 3; i++)
		scanf("%d", x + i);
	for (int i = 1; i <= n; i++)
		a[i] = a[i] ^ x[i % 4];
	for (int i = 1; i <= m; i++)
		ans ^= solve(c[i]) * i;
	cout << ans << endl;
	return 0;
}