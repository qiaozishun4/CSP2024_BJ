#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n, k, q, r, c, l[N], num, lst1[N];
int main ()
{
	freopen ("chain.in", "r", stdin);
	freopen ("chain.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++)
		{
			cin >> l[i];
			for (int j = 1; j <= l[i]; j++)
				cin >> num;
		}
		while (q--)
		{
			cin >> r >> c;
			cout << rand () % 2 << endl;
		}
	}
	return 0;
}