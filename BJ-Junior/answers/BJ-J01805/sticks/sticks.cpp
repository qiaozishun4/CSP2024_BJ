#include<bits/stdc++.h>
using namespace std;
int dp[100010][2];
int ans[100010][2];
int sticks[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	dp[0][0] = 1;
	dp[0][1] = 1;
	for(int i = 1; i <= 100000; i++)
	{
		for(int j = 1; j < 10; j++)
		{
			if(i < sticks[j])
			{
				continue;
			}
			if((i + 6) / 7 - 1 != (i - sticks[j] + 6) / 7)
			{
				continue;
			}
			if(dp[i - sticks[j]][0])
			{
				ans[i][1] = j;
				dp[i][1] = 1;
				break;
			}
		}
		for(int j = 0; j < 10; j++)
		{
			if(i < sticks[j])
			{
				continue;
			}
			if((i + 6) / 7 - 1 != (i - sticks[j] + 6) / 7)
			{
				continue;
			}
			if(dp[i - sticks[j]][0])
			{
				ans[i][0] = j;
				dp[i][0] = 1;
				break;
			}
		}
	}
	while(t--)
	{
		int x;
		cin >> x;
		if(dp[x][1] == 0)
		{
			cout << "-1" << endl;
		}
		else
		{
			int y = 1;
			while(x)
			{
				cout << ans[x][y];
				x -= sticks[ans[x][y]], y = 0;
			}
			cout << endl;
		}
	}
	return 0;
}