#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

int n, a[N], lst, cur = 1, num;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	cin >> n; for(int i = 1; i <= n; i++) cin >> a[i], a[0] = max(a[0], a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= a[0]; i++)
	{
		lst = cur; while(a[cur] == i) cur++;
		num -= min(num, cur - lst), num += cur - lst;
	}
	cout << num << endl;
	
	return 0;
}