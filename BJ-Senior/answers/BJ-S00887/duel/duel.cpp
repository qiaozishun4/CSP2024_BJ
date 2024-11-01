#include<iostream>
#include<algorithm>
using namespace std;
int n, r[100005];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int ans = n;
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	sort(r + 1, r + n + 1);
	int j = 1;
	for (int i = 1; i <= n; i++) {
		for (j = max(j, i + 1); j <= n; j++) {
			if (r[j] > r[i]) {
				ans--;
				j++;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}