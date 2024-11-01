#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const double eps = 1e-7;
struct Car{
    int l, r;
    // if there is a detector in [l, r], then the car is overspeed
}car[N], c[N];
int n, m, l, lim, det[N], cnt, ans;
bool del[N];
multiset<int> chose;

void dfs(int now, int cc){
    if (now > m){
        if (!cc) return;
        bool flg = 0;
        for (int i=1; i<=cnt; i++){
            if (chose.lower_bound(c[i].l) != chose.end() && (*chose.lower_bound(c[i].l)) <= c[i].r) continue;
            else{flg = 1; break;}
        }
        if (!flg) ans = min(ans, cc);
        return;
    }
    if (cc >= ans) return;
    dfs(now + 1, cc);
    chose.insert(det[now]);
    dfs(now + 1, cc + 1);
    chose.erase(chose.find(det[now]));
}

inline void solve(){
    scanf("%d%d%d%d", &n, &m, &l, &lim); ans = 2e9;
    int dc, vc, ac, s;
    double p = 1.0, ds;
    for (int i=1; i<=n; i++){
        scanf("%d%d%d", &dc, &vc, &ac);
        if (vc > lim && ac >= 0) car[i] = {dc, l};
        else if (vc > lim && ac < 0){
            s = (lim * lim * p - vc * vc * p) / 2.0 / (ac * p);
            if (s * ac * 2 + vc * vc == lim * lim) car[i] = {dc, min(dc + s - 1, l)};
            else car[i] = {dc, min(dc + s, l)};
        }
        else if (vc == lim && ac <= 0) car[i] = {l + 1, l + 1};
        else if (vc == lim && ac > 0) car[i] = {dc + 1, l};
        else if (vc < lim && ac <= 0) car[i] = {l + 1, l + 1};
        else if (vc < lim && ac > 0){
            s = (lim * lim * p - vc * vc * p) / 2.0 / (ac * p);
            if (dc + s + 1 > l) car[i] = {l + 1, l + 1};
            else car[i] = {dc + s + 1, l};
        }
    }
    for (int i=1; i<=m; i++) scanf("%d", &det[i]); det[m + 1] = l + 1;
    int ans1 = 0, t = 0; cnt = 0;
    //for (int i=1; i<=n; i++) printf("car %d will be detected overspeed in [%d, %d]\n", i, car[i].l, car[i].r);
    for (int i=1; i<=n; i++){
        if (car[i].l == l + 1 && car[i].r == l + 1) continue;
        if (det[lower_bound(det + 1, det + m + 1, car[i].l) - det] <= car[i].r) ans1++, c[++cnt] = car[i]; //printf("car %d is detected by detector.\n", i);
    }
    dfs(1, 0);
    printf("%d %d\n", ans1, m - ans);
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--){
        solve();
        //if (T) init();
    }
    return 0;
}
