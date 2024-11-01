#include<bits/stdc++.h>
using namespace std;
                 //0, 1, 2, 3, 4, 5, 6, 7, 8, 9
const int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int t, n, ans=1000000000, f[8];
int solve (int x) {
	int ans = 0, cnt = 2;
	while (x) {
		ans += (x%10) * cnt++;
		x /= 10;
	}
	return ans;
}
int getans (int x) {
	int ans = 0, cnt = 2;
	bool flag = false;
	while (x) {
		f[cnt++] = x % 10;
		x /= 10;
	}
	if (f[2] == 0 && f[3] == 0 && f[4] == 0 && f[5] == 0) flag = true;
	while (f[2]) {
		ans += 1;
		ans *= 10;
		f[2]--;
	}
	while (f[3]) {
		ans += 7;
		ans *= 10;
		f[3]--;
	}
	while (f[4]) {
		ans += 4;
		ans *= 10;
		f[4]--;
	}
	while (f[5]) {
		ans += 2;
		ans *= 10;
		f[5]--;
	}
	while (f[6]) {
		ans += flag?6:0;
		ans *= 10;
		flag = false;
		f[6]--;
	}
	while (f[7]) {
		ans += 8;
		ans *= 10;
		f[7]--;
	}
	return ans / 10;
}
int ups (int x) {
	int res = 0, cnt = 0;
	memset(f, 0, sizeof(f));
	while (x) {
		f[cnt++] = x % 10;
		x /= 10;
	}
	sort(f, f+cnt);
	if (f[0] != 6)
		for (int i = 0; i < cnt; i++)
			if (f[i] == 6) f[i] = 0;
	if (!f[0])
		for (int i = 0; i < cnt; i++)
			if (f[i]&&f[i]<6) {
				swap(f[0], f[i]);
				break;
			}
	if (!f[0]) f[0] = 6;
	for (int i = 0; i < cnt; i++) {
		res += f[i];
		res *= 10;
	}
	return res / 10;
}
int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 1000000000;
		cin >> n;
		if (n < 2) {
			cout << "-1\n";
			continue;
		}
		if (n == 2) ans = 1;
		for (int i = 2; i <= 999999; i++)
			if (solve(i) == n) ans = min(getans(i), ans);
		ans = ups(ans);
		cout << ans << '\n';
	}
	return 0;
}
