#include<bits/stdc++.h>
using namespace std;
int cnt[100010], cnt2[100010];
signed main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	int max1 = -1e9, max2 = -1e9;
	for(int i = 1; i <= n; i++)
	{
		int r;
		cin >> r;
		cnt[r]++;
		cnt2[r]++;
		if(max1 < r)
		{
			max2 = max1;
			max1 = r;
		}
		else if(max2 < r)
		{
			max2 = r;
		}
	}
	int x = 0, y = 0;
	for(int i = 1; i <= 100000; i++)
	{
		if(cnt[i] >= x)
		{
			cnt[i] -= x;
			x = 0;
			y = i;
		}
		else
		{
			x -= cnt[i];
			cnt[i] = 0;
		}
		x += cnt[i];
	}
	int ans = 0;
	for(int i = 1; i <= 100000; i++)
	{
		ans += cnt[i];
	}
	cout << ans << endl;
	return 0;
}