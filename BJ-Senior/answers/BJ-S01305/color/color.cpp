#include <iostream>
using namespace std;

int t, n, ans, a[200005];
bool plan[200005];
// true->red false->blue

void dfs(int x)
{
	if(x == n + 1)
	{
		int res = 0;
		for(int i = 2; i <= n; i++)
		{
			int pos = -1;
			for(int j = i - 1; j >= 1; j--)
				if(plan[i] == plan[j])
				{
					pos = j;
					break;
				}
			if(pos != -1 && a[i] == a[pos])
				res += a[i];
		}
		ans = max(ans, res);
		return ;
	}
	plan[x] = true, dfs(x + 1);
	plan[x] = false, dfs(x + 1);
	return ;
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		ans = 0, dfs(1);
		cout << ans << endl;
	}

	return 0;
}