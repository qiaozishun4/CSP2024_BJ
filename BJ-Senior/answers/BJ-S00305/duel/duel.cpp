#include <bits/stdc++.h>
using namespace std;

int n,r[100005],cnt[100005],num[100005],x=-1,y=-1;
int mx = 0;

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> r[i];
		cnt[r[i]]++;
		num[r[i]]++;
		mx = max(r[i],mx);
	}
	for (int i = 0;i <= mx;i++)
	{
		if (cnt[i] != 0)
		{
			if (x == -1) x = i;
			else if (y == -1) y = i;
		}
	}
	if (y == -1) 
	{
		cout << n;
		return 0;
	}
	while (y <= mx)
	{
		cnt[x]--;
		num[y]--;
		if (cnt[x] == 0) 
		{
			x++;
			while (x <= mx && cnt[x] == 0) x++;
			if (x < y) continue;
			y++;
			while (y <= mx && num[y] == 0) y++;
		}
		if (num[y] == 0)
		{
			y++;
			while (y <= mx && num[y] == 0) y++;
		}
	}
	int ans = 0;
	for (int i = 0;i <= mx;i++)
	{
		ans += cnt[i];
	}
	cout << ans;
	
	return 0;
}
