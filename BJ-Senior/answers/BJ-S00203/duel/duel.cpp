#include<bits/stdc++.h>
using namespace std;

// #define My_Debug

const int maxn = 1e5 + 10;
int r[maxn], n;
bool vis[maxn];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> r[i];
	sort(r + 1, r + n + 1);
	int p0 = 1, p1 = -1;
	for(p1 = 1; p1 <= n; ++p1) if(r[p1] != r[p0]) break;
	#ifdef My_Debug
	cout << p0 << ' ' << p1 << '\n';
	#endif
	memset(vis, true, sizeof(vis));
	while(p0 <= n && p1 <= n)
		if(r[p0] < r[p1])	vis[p0] = false, ++p0, ++p1;
		else	++p1;
	int ans = 0;
	for(int i = 1; i <= n; ++i) if(vis[i]) ++ans;
	cout << ans << '\n';
	return 0;
}
