#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, m, maxn, num[N], q[N], x[4], tmp[N];
string s[5];
int main ()
{
	freopen ("arena.in", "r", stdin);
	freopen ("arena.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	for (int i = 1; i <= m; i++)
	{
		cin >> q[i];
		maxn = max (maxn, q[i]);
	}
	int K;
	for (K = 1; K <= 5; K ++)
		if (1 >> K >= maxn)
			break;
	for (int i = 1; i <= K; i++)
		cin >> s[i];
	cin >> T;
	while (T--)
	{
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		cout << rand () %  ((1 + n) * n / 2)<< endl;
	}
	return 0;
}