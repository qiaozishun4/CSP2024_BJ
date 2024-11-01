#include <cstdio>
#include <cmath>
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d",&T);
    while (T--){
        int n, m, L, V, flagA = 0, flagB = 0, flagC = 0;
        scanf("%d%d%d%d",&n,&m,&L,&V);
        int d[100005] = {0}, v0[100005] = {0}, a[100005] = {0}, c[100005] = {0};
        for (int i = 1; i <= n; i++){
            scanf("%d%d%d",&d[i],&v0[i],&a[i]);
            if (a[i] != 0){
                flagA = 1;
            }
            if (a[i] <= 0){
                flagB = 1;
            }
            if (a[i] >= 0){
                flagC = 1;
            }
        }
        int p[100005] = {0}, t = 1;
        for (int i = 1; i <= m; i++){
            scanf("%d",&p[i]);
        }
        if (flagA == 0){
            int cnt = 0;
            for (int i = 1; i <= n; i++){
                if (v0[i] > V && d[i] <= p[m]){
                    cnt++;
                }
            }
            printf("%d %d\n", cnt, m - 1);
            continue;
        }
        if (flagB == 0){
            int cnt = 0;
            double s[100005];
            for (int i = 1; i <= n; i++){
                s[i] = d[i];
                if (v0[i] < V){
                    s[i] += (double)(V * V - v0[i] * v0[i]) / (2 * a[i]);
                }
                if (s[i] < p[m]){
                    cnt++;
                }
            }
            printf("%d %d\n", cnt, m - 1);
            continue;
        }
        if (flagC == 0){
            int cnt = 0;
            double s[100005];
            for (int i = 1; i <= n; i++){
                s[i] = d[i];
                if (v0[i] > V){
                    s[i] += (double)(V * V - v0[i] * v0[i]) / (2 * a[i]);
                }
                for (int j = 1; j <= n; j++){
                    if (p[j] < s[i] && d[i] <= p[j]){
                        cnt++;
                        break;
                    }
                }
            }
            printf("%d %d\n", cnt, cnt);
            continue;
        }
        long long v[100005];
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (p[i] >= d[j]){
                    v[j] = (v0[j] * v0[j]) + 2 * a[j] * (p[i] - d[j]);
                    if (v[j] > V * V){
                        c[j]++;
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (c[i] != 0){
                cnt++;
            }
        }
        printf("%d %d\n",cnt, cnt);
    }
    return 0;
}
