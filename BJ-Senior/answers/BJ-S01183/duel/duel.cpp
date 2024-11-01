#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100005

#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif

using namespace std;

int n, cnt[maxn], a, ans;

signed main() {
    fopen("duel");
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a; 
        cnt[a]++;
        ans = max(ans, cnt[a]);
    }
    cout << ans << '\n';
}