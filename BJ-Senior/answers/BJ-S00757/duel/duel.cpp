#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n, a[100005];
struct node {
	int num, save, attack;
} p[100005];
int m;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (i == 1 || p[m].num != a[i]) {
			m++;
			p[m].num = a[i];
			p[m].save = 1;
			p[m].attack = 1;
		} else {
			p[m].save++;
			p[m].attack++;
		}
	}
	//for (int i = 1; i <= m; i++) cout << i << " num=" << p[i].num << " save=attack=" << p[i].save << '\n';
	int j = 1, ans = n;
	for (int i = 2; i <= m; i++) {
		while (p[i].attack && j < i) {
			if (p[i].attack >= p[j].save) {
				p[i].attack -= p[j].save;
				ans -= p[j].save;
				p[j].save = 0;
				j++;
			} else {
				p[j].save -= p[i].attack;
				ans -= p[i].attack;
				p[i].attack = 0;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
