#include <bits/stdc++.h>
using namespace std;

string s[100005];
int vis[100005];
int ls1[100005];
int ls2[100005];
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t, n, k, q, l, a;
	char b;
	char c;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> k >> q;
		for (int j = 1; j <= n; j++)
		{
			cin >> l;
			for (int o = 1; o <= l; o++)
			{
				cin >> c;
				s[i] += c;
			}
		}
		for (int j = 1; j <= q; j++)
		{
			cin >> a >> b;
			if (a == 1)
			{
				int minnn = 2e5;
				for (int os = 1; os <= n; os++)
				{
					int ls = s[os].size();
					for (int p = 0; p < ls; p++)
					{
						if (s[os][p] == b)
						{
							ls1[++ls1[0]] = p;
						}
						if (s[os][p] == '1')
						{
							ls2[++ls2[0]] = p;
						}
					}
					int z1 = 1, z2 = 1, minn = s[os].size();
					for (int p = 1; p <= ls1[0]; p++)
					{
						while(ls2[z2 + 1] < ls1[z1] && z2 < ls2[0])
						{
							z2++;
						}
						minn = min(minn, ls1[z1] - ls2[z2] + 1);
						z1++;
					}
					minnn = min(minnn, minn);
				}
				if (minnn <= k)
				{
					cout << 1 << endl;
				}
				else 
				{
					cout << 0 << endl;
				}
			}
			else
			{
				cout << 1 << endl;
			}
		}
	}			 
	return 0;
}
