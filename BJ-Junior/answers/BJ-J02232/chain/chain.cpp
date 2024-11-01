#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 100010, L = 200010;
vector<int> word[N], askr, askc;
bool ans[110][N];
int ban[110][N];

int main()
{
	ios::sync_with_stdio(false);
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t, n, ml, q, maxr;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> ml >> q;
		int cnt, num;
		for (int j = 1; j <= n; j++)
		{
			cin >> cnt;
			for (int k = 1; k <= cnt; k++)
			{
				cin >> num;
				word[j].push_back(num);
			}
		}
		maxr = -1;
		for (int j = 1; j <= q; j++)
		{
			cin >> cnt >> num;
			askr.push_back(cnt);
			askc.push_back(num);
			maxr = max(maxr, cnt);
		}
		for (int j = 0; j < maxr; j++)
		{
			for (int k = 1; k < L; k++)
			{
				ans[j][k] = false;
				ban[j][k] = -1;
			}
		}
		ans[0][1] = true;
		int u, sz;
		for (int j = 1; j <= maxr; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				sz = word[k].size();
				for (int l = 0; l < sz; l++)
				{
					if (ans[j - 1][word[k][l]] && k != ban[j][word[k][l]])
					{
						u = min(ml - 1, sz - l - 1);
						for (int m = 1; m <= u; m++)
						{
							ans[j][word[k][l + m]] = true;
							if (ban[j + 1][word[k][l + m]] == -1)
							{
								ban[j + 1][word[k][l + m]] = k;
							}
							else if (ban[j + 1][word[k][l + m]] != k)
							{
								ban[j + 1][word[k][l + m]] = 0;
							}
						}
					}
				}
			}
		}
		for (int j = 0; j < q; j++)
		{
			cout << ans[askr[j]][askc[j]] << endl;
		}
		for (int j = 1; j <= n; j++)
		{
			word[i].clear();
		}
		askr.clear();
		askc.clear();
	}
	return 0;
}