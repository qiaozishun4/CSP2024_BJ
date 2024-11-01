#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, ans, lst, card[N];
bool vis[N];
int main ()
{
	freopen ("duel.in", "r", stdin);
	freopen ("duel.out", "w", stdout);
	cin >> n;
	ans = n;
	for (int i = 1; i <= n; i++)
		cin >> card[i];
	sort (card + 1, card + 1 + n);
	lst = n - 1;
	for (int i = n; i >= 1; i--)
	{
		lst --;
		while (card[i] <= card[lst] && lst > 0)
			lst --;
		if (lst == 0)
			break;
		if (card[i] > card[lst])
		{
			ans --, vis[lst] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}