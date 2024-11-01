#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int cnt[N];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n, i, x, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		ans = max(ans, ++cnt[x]);
	}
	printf("%d\n", ans);
	return 0;
}