#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll a[1001000];
ll n, sum;

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	cout << n / 2;
	return 0;
}
