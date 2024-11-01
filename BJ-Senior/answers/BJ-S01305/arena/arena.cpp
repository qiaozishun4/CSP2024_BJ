#include <iostream>
#include <cstring>
using namespace std;

int t, n, m, cnt, x[4], a[100005], st[100005], c[100005], d[25][100005];

int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> st[i];
	for(int i = 1; i <= m; i++) cin >> c[i];
	int k;
	for(k = 1; k <= 20; k++)
		if((1 << k) >= n)
			break;
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= 1 << (k - i); j++)
			scanf("%1d", &d[i][j]);
	cin >> t;
	while(t--)
	{
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		for(int i = 1; i <= n; i++)
			a[i] = st[i] ^ x[i % 4];
	}

	return 0;
}