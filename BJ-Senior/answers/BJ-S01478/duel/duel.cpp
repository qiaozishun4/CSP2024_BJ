#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], ans;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	int it = 0;
	for (int i = 2; i <= n; i++)
		if (a[i] > a[it + 1])
		{
			ans++;
			it++;
		}
	cout << n - ans << endl;
	return 0;
}