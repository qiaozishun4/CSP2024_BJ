#include<bits/stdc++.h>
using namespace std;
long long d[100010], v[100010], a[100010], p[1000010], b[100010], c[3010][3010], e[100010];
long long count(long long v1, long long v0, long long a, int x){
    long long ans = (v1*v1-v0*v0) / (2*a);
    if (x == 1 && (v1*v1-v0*v0) % (2*a) != 0) ans++; // 向上取整
    return ans;
}
struct node{
    long long l, r;
} l[100010];
bool cmp(node x, node y){
    return x.l < y.l;
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    long long T, n, m, L, V, x, ans1, ans2, pos;
    cin >> T;
    while (T--){
        memset(p, 0, sizeof(p));
        memset(e, 0, sizeof(e));
        memset(c, 0, sizeof(c));
        ans1 = 0;
        ans2 = 0;
        pos = 0;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
        for (int i = 1; i <= m; i++){
            cin >> b[i];
            p[b[i]]++;
        }
        for (int i = 1; i <= L; i++) p[i] += p[i-1];
        for (int i = 1; i <= n; i++){
            if (v[i] <= V && a[i] <= 0) continue; //始终没有超速
            if (v[i] > V && a[i] >= 0){ //始终超速
                if (p[L]-p[d[i]-1]){ // 有摄像头
                    ans1++;
                    l[++pos] = node{d[i], L};
                }
                continue;
            }
            if (v[i] > V && a[i] < 0){ // 超速并慢慢减速
                long long x = min(d[i]+count(V, v[i], a[i], 0), L); // 不超速位置
                if (p[x]-p[d[i]-1]){ // 有摄像头
                    ans1++;
                    l[++pos] = node{d[i], x};
                }
                continue;
            }
            if (v[i] <= V && a[i] > 0){ // 不超速并慢慢加速
                long long x = d[i]+count(V, v[i], a[i], 1); // 超速位置
                if (x > L) continue;
                if (p[L]-p[x-1]){ // 有摄像头
                    ans1++;
                    l[++pos] = node{x, L};
                }
                continue;
            }
        }
        sort(b+1, b+n+1);
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= pos; j++){
                if (b[i] >= l[j].l && b[i] <= l[j].r){
                    c[i][j]++;
                    e[j]++;
                }
            }
        }
        //for (int i = 1; i <= pos; i++) cout << e[i] << ' ';
        for (int i = 1; i <= m; i++){
            bool f = 1;
            for (int j = 1; j <= pos; j++){
                if (e[j]-c[i][j] < 1){
                    f = 0;
                    break;
                }
            }
            if (f){
                ans2++;
                for (int j = 1; j <= pos; j++) e[j]-=c[i][j];
            }
        }
        cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}
