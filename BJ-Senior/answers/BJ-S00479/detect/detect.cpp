#include <bits/stdc++.h>
using namespace std;
int T, n, m;
int d[200005], v[200005], a[200005], p[200005], ans = 0;
bool vis[105][105], cnt[105], f[105];
int  cnt1;
void dfs(int step, int num) {
    if(step == m + 1) {
        int t = 0, vis2[105][105];
        for(int j = 1;j <= m;j++) {
            if(f[j])
                for(int i = 1;i <= n;i++)
                    vis2[i][j] = 0;
            else
                for(int i = 1;i <= n;i++)
                    vis2[i][j] = vis[i][j];
        }
        for(int i = 1;i <= n;i++) {
            int flag = 0;
            for(int j = 1;j <= n;j++) {
                if(vis2[i][j] == 1)
                    flag = 1;
            }
            if(flag)
                t++;
        }
        if(t == cnt1)
            ans = max(ans, num);
        return ;
    }
    f[step] = 1;
    dfs(step + 1, num + 1);
    f[step] = 0;
    dfs(step + 1, num);
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while(T--) {
        memset(vis, 0, sizeof(vis));
        int L, V, maxp = 0, minp = 1e9;
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++)
            cin >> d[i] >> v[i] >> a[i];
        for(int i = 1;i <= m;i++) {
            cin >> p[i];
            maxp = max(maxp, p[i]);
            minp = min(minp, p[i]);
        }
        bool A = 1, B = 1, C = 1;
        for(int i = 1;i <= n;i++) {
            if(a[i] > 0)
                A = 0, C = 0;
            if(a[i] == 0)
                B = 0, C = 0;
            if(a[i] < 0)
                A = 0, B = 0;
        }
        sort(p + 1, p + n + 1);
        if(A) {
            int num = 0;
            for(int i = 1;i <= n;i++) {
                if(v[i] > V && d[i] <= maxp)
                    num++;
            }
            cout << num << ' ' << m - 1 << endl;
        }
        else if(B) {
            int num = 0;
            for(int i = 1;i <= n;i++) {
                if(d[i] > maxp)
                    continue;
                int s = maxp - d[i];
                int v1 = v[i] * v[i] + 2 * a[i] * s;
                if(v1 > V * V)
                    num++;
            }
            cout << num << ' ' << m - 1 << endl;
        }
        else {
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= m;j++) {
                    if(d[i] > p[j])
                        continue;
                    int s = p[j] - d[i];
                    int v1 = v[i] * v[i] + 2 * a[i] * s;
                    if(v1 > V * V){
                        cnt[i] = 1;
                        vis[i][j] = 1;
                    }
                }
            }
            cnt1 = 0;
            for(int i = 1;i <= n;i++) {
                if(cnt[i] != 0){
                    cnt1 += 1;
                }
            }
            cout << cnt1 << ' ';
            ans = 0;
            dfs(1, 0);
            cout << ans << endl;
        }
    }
    return 0;
}