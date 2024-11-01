#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;

int T, n, a[N], c[N]; ll ans;

void find(int k, ll s)
{
	if(k > n) {ans = max(ans, s); return; }
	c[0] = 0; for(int i = k - 1; i > 0; i--) if(c[i] == 0) {c[0] = i; break; }
	c[k] = 0; find(k + 1, s + a[k] * (a[c[0]] == a[k]));
	c[0] = 0; for(int i = k - 1; i > 0; i--) if(c[i] == 1) {c[0] = i; break; }
	c[k] = 1; find(k + 1, s + a[k] * (a[c[0]] == a[k]));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	cin >> T;
	while(T--)
	{
		cin >> n; for(int i = 1; i <= n; i++) cin >> a[i];
		find(1, 0); cout << ans << endl; ans = 0;
	}
	
	return 0;
}