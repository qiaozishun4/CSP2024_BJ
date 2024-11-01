#include<bits/stdc++.h>
using namespace std;
int n, m, L, V, p[100005], d[100005], v[100005], a[100005], ans, ans1, t, cnt, mi;
pair<int, int> qz[100005];
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d", &n, &m, &L, &V); cnt = 0; ans1 = 0, ans = 1, mi = 0;
        for(int i = 1; i <= n; i++) scanf("%d%d%d", &d[i], &v[i], &a[i]);
        for(int i = 1; i <= m; i++) scanf("%d", &p[i]);
        for(int i = 1; i <= n; i++){
            if(a[i] >= 0){
                int l = 1, r = m, mid, num = -1;
                while(l <= r){
                    mid = (l + r) / 2;
                    double x;
                    if(v[i] * v[i] + 2 * a[i] * (p[mid] - d[i]) >= 0) x = sqrt(v[i] * v[i] + 2 * a[i] * (p[mid] - d[i]));
                    else x = 0;
                    if(p[mid] < d[i]) l = mid + 1;
                    else if(x > (double)V) num = mid, r = mid - 1;
                    else l = mid + 1;
                }if(num != -1) ans1++;
                mi = max(mi, num);
            }else{
                int l = 1, r = m, mid, num = -1, num1 = -1;
                while(l <= r){
                    mid = (l + r) / 2;
                    double x;
                    if(v[i] * v[i] + 2 * a[i] * (p[mid] - d[i]) >= 0) x = sqrt(v[i] * v[i] + 2 * a[i] * (p[mid] - d[i]));
                    else x = 0;
                    if(p[mid] < d[i]) l = mid + 1;
                    else if(x > (double)V) num = mid, l = mid + 1;
                    else r = mid - 1;
                }if(num != -1){
                    num1 = lower_bound(p+1, p+1+m, d[i]) - p;
                    ans1++; qz[++cnt] = {num1, num};
                }
            }
            //printf("%d %d\n", i, num);
        }if(mi != 0) qz[++cnt] = {mi, m};int nl = 1, nr = m;
        sort(qz+1, qz+1+cnt);
        for(int i = 1; i <= cnt; i++){
            nl = max(nl, qz[i].first), nr = min(nr, qz[i].second);
            if(nl > nr) ans++, nl = qz[i].first, nr = qz[i].second;
        }if(ans1 == 0) ans = 0;
        printf("%d %d\n", ans1, m - ans);
    }
    return 0;
}
