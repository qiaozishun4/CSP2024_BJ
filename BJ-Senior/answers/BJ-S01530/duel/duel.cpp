#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100005];
int cnt[100005] = {0}, x = 0;
map<int, int> mp;
signed main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int maxn = 0;
    for(auto it : mp) {
        maxn = max(maxn, it.second);
    }
    cout << maxn;
    return 0;
}
