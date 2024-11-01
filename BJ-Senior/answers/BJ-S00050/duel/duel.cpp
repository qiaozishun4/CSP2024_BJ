#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int n;
int r[MAXN];
int bin1[MAXN]; // Defend
int bin2[MAXN]; // Attack

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
		bin1[r[i]]++;
		bin2[r[i]]++;
	}
	int res = 0;
	int cur = 1;
	for (int i = 2; i <= MAXN; i++) {
		while (cur < i && !bin1[cur]) {
			cur++;
		}
		while (cur < i && bin2[i]) {
			if (bin1[cur] > bin2[i]) {
				bin1[cur] -= bin2[i];
				res += bin2[i];
				// printf("%d Attack %d for %d\n", i, cur, bin2[i]);
				bin2[i] = 0;
			} else {
				res += bin1[cur];
				bin2[i] -= bin1[cur];
				// printf("%d Attack %d for %d\n", i, cur, bin1[cur]);
				bin1[cur] = 0;
			}
			while (cur < i && !bin1[cur]) {
				cur++;
			}
		}
	}
	cout << n - res << endl;
	return 0;
}
