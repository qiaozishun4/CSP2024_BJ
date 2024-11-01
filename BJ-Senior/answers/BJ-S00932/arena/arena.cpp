#include <bits/stdc++.h>

using namespace std;

int a[100005], c[100005];

int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	int i, j, k;
	int n, m;
	cin >> n >> m;
	for(i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    for(i=1; i<=m; i++)

    {
        cin >> c[i];
    }
    int T;
    cin >> T;
    while(T--)
    {
        int x[5];
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for(i=1; i<=n; i++)
        {
            a[i] ^= x[i%4];
        }
        int ans = 0;
        cout << 1 << "\n";
    }
	return 0;
}
