#include <iostream>
#include <vector>
using namespace std;
//only one person and one round

int t, n, k, q, r, c, l, f[1000005];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
	while(t--)
	{
		cin >> n >> k >> q >> l;
		for(int i = 1; i <= n; i++)
        {
            int s[200005];
            for(int j = 1; j <= l; j++)
			{
			    cin >> s[j];
			}
			int v = 0;
			for(int j = 1; j <= l; j++)
			{
			    if(s[j] == 1) v = j;
			    if(j - v + 1 > k) v = 0;
			    if(v != 0) f[s[j]] = 1;
			}

        }

		while(q--)
		{
			cin >> r >> c;
			if(f[c] == true) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}
