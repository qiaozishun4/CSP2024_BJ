#include <bits/stdc++.h>
using namespace std;

vector<int> red, blue;
const int N = 2e5 + 10;
int a[N], ans = -1, n;

void choose(int i) {
	if(i == n + 1) {
		int anst = 0;
		for(int i = 1; i < red.size(); i++) {
			if(red[i] == red[i - 1]) anst += red[i];
		}
		for(int i = 1; i < blue.size(); i++) {
			if(blue[i] == blue[i - 1]) anst += blue[i];
		}
		ans = max(anst, ans);
		return;
	}
	red.push_back(a[i]);
	choose(i + 1);
	red.pop_back();
	blue.push_back(a[i]);
	choose(i + 1);
	blue.pop_back();
}

void solve() {
	ans = -1;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	choose(1);
	printf("%d\n", ans);
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}