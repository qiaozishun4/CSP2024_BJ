#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 10;

int n;
int a[maxn], b[maxn];
int mp[maxn];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1);
	int cnt = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++) 
		a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b, mp[a[i]]++;
	int pre = mp[1];
	// for (int i = 1; i <= cnt; i++) cout << mp[i] << " ";
	// 	cout << "\n";
	for (int i = 2; i <= cnt; i++)
		if (pre < mp[i])
			pre = mp[i];
	cout << pre << "\n";
	return 0;
}