#include <iostream>

using namespace std;

const int maxn = 1e5 + 10;

int T;
int n;
int a[] = { -1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888 };

void solve()
{
	cin >> n;
	if (n <= 21) { cout << a[n] << "\n"; return; }
	int p = n, num = 0;
	while (p > 21) p -= 7, num++;
	if (p == 0 || p == 1) p += 7, num--;
	cout << a[p];
	for (int i = 1; i <= num; i++) cout << "8";
	cout << "\n";
	return;
}
int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);

	cin >> T;
	while (T--) solve();
	return 0;
}
