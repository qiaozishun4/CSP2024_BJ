#include<bits/stdc++.h>
using namespace std;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[10005];
int j;
char c;
string calc(string s, int x)
{
	c = x + '0';
	s = s + c;
	j = s.size() - 1;
	if(x != 0)
	{
		while(j > 0 && s[j] < s[j - 1])
		{
			swap(s[j], s[j - 1]);
			j --;
		}
	}
	else
	{
		while(j > 1 && s[j] < s[j - 1])
		{
			swap(s[j], s[j - 1]);
			j --;
		}
	}
	return s;
}
int i;
string mn(string s1, string s2)
{
	if(s1 == "") return s2;
	if(s1.size() != s2.size())
	{
		if(s1.size() < s2.size()) return s1;
		else return s2;
	}
	for(i = 0; i < s1.size(); i ++)
	{
		if(s1[i] < s2[i]) return s1;
		if(s1[i] > s2[i]) return s2;
	}
	return s1;
}
signed main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	dp[2] = "1";
	dp[3] = "7";
	dp[4] = "4";
	dp[5] = "2";
	dp[6] = "6";
	dp[7] = "8";
	int i, j;
	for(i = 8; i <= 8000; i ++)
	{
		for(j = 0; j <= 9; j ++)
		{
			if(i - a[j] >= 0)
			{
				if(dp[i - a[j]] == "") continue;
				dp[i] = mn(dp[i], calc(dp[i - a[j]], j));
			}
		}
	}
	int t, n, m;
	cin >> t;
	while(t --)
	{
		cin >> n;
		m = n / 7;
		m = max(0, m - 1000);
		if(dp[n - m * 7] == "") cout << -1 << endl;
		else
		{
			cout << dp[n - m * 7];
			for(int k = 1; k <= m; k ++) cout << 8;
			cout << endl;
		}
	}
	return 0;
}
