#include <bits/stdc++.h>

using namespace std;

int n, c[4][20], ans;

void solve(int pos, char ch) {
	if (ch <= '9')
		c[pos][ch - '0']++;
	else if (ch == 'A')
		c[pos][1]++;
	else if (ch == 'T')
		c[pos][10]++;
	else if (ch == 'J')
		c[pos][11]++;
	else if (ch == 'Q')
		c[pos][12]++;
	else
		c[pos][13]++;
}

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		if (s[0] == 'D')
			solve(0, s[1]);
		else if (s[0] == 'C')
			solve(1, s[1]);
		else if (s[0] == 'H')
			solve(2, s[1]);
		else
			solve(3, s[1]);
	}
	for (int i = 0; i <= 3; i++)
		for (int j = 1; j <= 13; j++)
			if (c[i][j] == 0)
				ans++;
	printf("%d\n", ans);
	return 0;
}
