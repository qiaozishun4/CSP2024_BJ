#include <iostream>
using namespace std;

int n, a[100005], x, sum;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x, a[x]++;
	int ans = n;
	for (int i = 1; i <= 1e5; i++)
	{
		if (a[i] == 0) continue;
		if (a[i] <= sum) ans -= a[i];
		if (a[i] > sum) ans -= sum, sum = a[i];
	}
	cout << ans << endl;
	return 0;
}