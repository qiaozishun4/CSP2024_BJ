#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];
struct node {
	int first;
	mutable int hit, second;
	node(int a, int b, int c) {first = a, hit = b, second = c;}
};
vector<node> v;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n, ans = 0, st = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	v.push_back(node(a[1], 1, 1));
	for(int i = 2; i <= n; i++) {
		if(v.back().first == a[i]) v.back().second++, v.back().hit++;
		else {
			v.push_back(node(a[i], 1, 1));
		}
	}
	// for(auto i : v) {
		// printf("%d %d\n", i.first, i.second);
	// }
	int tp;
	for(int i = 1; i < v.size(); i++) {
		while(st != i && v[i].hit != 0) {
			ans += tp = min(v[i].hit, v[st].second);
			v[st].second -= tp;
			v[i].hit -= tp;
			if(v[st].second == 0) st++;
		}
	}
	printf("%d", n - ans);
	return 0;
}