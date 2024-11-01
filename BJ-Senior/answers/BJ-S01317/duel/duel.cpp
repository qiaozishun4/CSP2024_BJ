#include<bits/stdc++.h>
using namespace std;
int r[100005];
bool vis[100005];
int main () {
    freopen ("duel.in", "r", stdin);
    freopen ("duel.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }
    sort(r, r + n);
    int cnt = n;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (r[i] > r[j] && !vis[j]) {
                cnt--;
                vis[j] = true;
                break;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}