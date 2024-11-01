#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int anp[100005];
int box[100005];
int vis[100005];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> anp[i];
		box[anp[i]]++;
	}
	int ans = n;
	int it = 0;
	for (int i = 1; i <= 100005; i++)
	{
		if (box[i] != 0)
		{
			ans -= min(box[it], box[i]);
			it = i;
		}
	}
	cout << ans << endl;
	return 0;
}