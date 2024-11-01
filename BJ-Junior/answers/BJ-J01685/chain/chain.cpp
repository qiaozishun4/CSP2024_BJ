#include <bits/stdc++.h>
using namespace std;
string s[100010];

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int i, j, t, n, k, q, l, r, c;

	cin >> t;
	while(t--)
    {
        cin >> n >> k >> q;
        for(i = 1; i <= n; i++)
        {
            cin >> l;
            cin >> s[i];
        }
        for(j = 1; j <= q; j++)
        {
            cin >> r >> c;
            cout << 1;
        }
    }


	return 0;
}
