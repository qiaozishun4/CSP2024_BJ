#include <bits/stdc++.h>
using namespace std;
int n, ans, a[100005], b[100005], vis[100005];
bool ok = 1;
void task(){
    for (int i = 1;i <= n;i++) if (a[i] == 2) ans++;
    cout << ans;
} int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i], ok &= (a[i] <= 2);
    if (ok){task(); return 0;}
    sort(a + 1, a + n + 1);
    b[1] = 1;
    for (int i = 2;i <= n;i++) b[i] = b[i - 1] + (a[i] != a[i - 1]);
    for (int i = 1;i <= n;i++){
        if (vis[i]) continue;
        int j = i;
        while (j && (b[i] <= b[j] || vis[j])) j--;
        if (j) vis[j] = 1;
    }  for (int i = 1;i <= n;i++) if (!vis[i]) ans++;
    cout << ans;
}
