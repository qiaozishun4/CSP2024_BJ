#include<iostream>
#include<algorithm>
using namespace std;
int n, a[200005];
char plan[200005];
int ans = -2e9;
void dfs(int x)
{
	if (x == n + 1) {
		int anss = 0;
		int lr = 0;
		int lb = 0;
		for (int i = 1; i <= n; i++) {
			if (plan[i] == 'r')
				anss += (a[i] == a[lr] ? a[i] : 0), lr = i;
			else if (plan[i] == 'b')
				anss += (a[i] == a[lb] ? a[i] : 0), lb = i;
		}
		ans = max(ans, anss);
		return ;
	}
	plan[x] = 'r';
	dfs(x + 1);
	plan[x] = 'b';
	dfs(x + 1);
}
int T;
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ans = -2e9;
		dfs(1);
		cout << ans << "\n";
	}
	return 0;
}