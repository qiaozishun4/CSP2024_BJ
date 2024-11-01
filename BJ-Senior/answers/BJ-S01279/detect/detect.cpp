#include<bits/stdc++.h>
using namespace std;
int p[100010];
int check[100010];

struct{
    double d, v, a;
    double over_st, over_end;
} q[100010];

int read(){
    int f = 1, x = 0;
    char s = getchar();
    while((s < '0') || (s > '9')){
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while((s >= '0') && (s <= '9')){
        x = x * 10 + s - '0';
        s = getchar();
    }

    return x * f;
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    t = read();
    for (int i = 1; i <= t; i++){
        int n, m, L, V;
        n = read();
        m = read();
        L = read();
        V = read();
        for (int j = 1; j <= n; j++)
            scanf("%lf%lf%lf", &q[j].d, &q[j].v, &q[j].a);
        for (int j = 1; j <= m; j++)
            p[j] = read();
        sort(p + 1, p + 1 + m);
        int ans = 0;
        memset(check, 0, sizeof(check));
        for (int j = 1; j <= n; j++){
            if (q[j].a == 0){
                if (q[j].v > n){
                    ans++;
                    check[j]++;
                }
            }
            if (((q[j].v > V) && (q[j].a > 0) && (int(q[j].d) < p[m])) || ((q[j].v < V) && (q[j].a < 0) && (int(q[j].d) > p[1])))
                continue;
            q[j].over_end = (V * V + q[j].v * q[j].v) / (2 * q[j].a);
            for (int k = 1; k <= m; k++)
                if ((int(q[j].d) <= p[k]) && (int(q[j].over_end) >= p[k])){
                    ans++;
                    check[j]++;
                }
        }
        cout << ans << ' ';
        int num = 0;
        for (int j = 1; j <= n; j++)
            if (check[j])
                num += (check[j] - 1);
        cout << num << '\n';
    }

    return 0;
}