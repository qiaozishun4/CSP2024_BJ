#include<bits/stdc++.h>
using namespace std;

int n, a[300005], b[20], ans = -1;

void dfs(int now) {
    if(now == n) {
        int qa = 0, qb = 0, cnt = 0;
        for(int i = 1;i <= n;i++) {
            if(b[i] == 0) {
                if(qa != 0) {
                    if(a[qa] == a[i]) cnt += a[i];
                }
                qa = i;
            }else if(b[i] == 1) {
                if(qb != 0) {
                    if(a[qb] == a[i]) cnt += a[i];
                }
                qb = i;
            }
        }
        ans = max(ans, cnt);
        return;
    }
    b[now + 1] = 0;
    dfs(now + 1);
    b[now + 1] = 1;
    dfs(now + 1);
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        ans = -1;
        scanf("%d", &n);
        for(int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
        }
        dfs(0);
        printf("%d\n", ans);
    }
    return 0;
}

