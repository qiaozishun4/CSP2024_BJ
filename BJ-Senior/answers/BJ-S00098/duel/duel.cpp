#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, ans = n;
	for(int i = 1; i <= n; i ++)
	{
		if(a[i] > a[l])
		{
			l ++;
			ans --;
		}
	}
	cout << ans;
	return 0;
}
