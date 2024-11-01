//LMY bao you zheng jie bie gua!!!~~~
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
//log2(MAXN)=17
int n, m, len;
int vl; //v limit
int p[MAXN];
struct Car{
    int d, v0, a;
}c[MAXN];
struct Node{
    int l, r;
}q[MAXN];
int up(int x, int y){
    return (x - 1) / y + 1;
}
int maxn[MAXN], f[MAXN], dp[MAXN][20], logn[MAXN];
int query(int l, int r){
    if (l > r) return 0;
    int s = logn[r - l + 1];
    return max(dp[l][s], dp[r - (1 << s) + 1][s]);
}
void test(){
    int cur = 0;
    cin >> n >> m >> len >> vl;
    logn[1] = 0, logn[2] = 1;
    for (int i = 3; i <= n; i++){
        logn[i] = logn[i / 2] + 1;
    }
    memset(maxn, 0, sizeof maxn);
    memset(f, 0x3f, sizeof f);
    //you need to be > VL!!!
    for (int i = 1; i <= n; i++){
        cin >> c[i].d >> c[i].v0 >> c[i].a;
    }
    for (int i = 1; i <= m; i++){
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++){
        int d = c[i].d, v0 = c[i].v0, a = c[i].a;
        if (a == 0){
            //const
            if (v0 > vl){
                int pos = lower_bound(p + 1, p + m + 1, d) - p;
                if (pos <= m){
                    cur++;
                    q[cur] = (Node){pos, m};
                }
            }
        }
        else if (a > 0){
            //faster
            if (v0 > vl){
                int pos = lower_bound(p + 1, p + m + 1, d) - p;
                if (pos <= m){
                    cur++;
                    q[cur] = (Node){pos, m};
                }
            }
            else if (v0 == vl){
                int pos = lower_bound(p + 1, p + m + 1, d + 1) - p;
                if (pos <= m){
                    cur++;
                    q[cur] = (Node){pos, m};
                }
            }
            else if (v0 < vl){
                int tmp1 = (vl * vl - v0 * v0) / (2 * a);
                int tmp2 = up(vl * vl - v0 * v0, 2 * a);
                int tmp = d;
                if (tmp1 == tmp2) tmp += tmp1 + 1;
                else tmp += tmp2;
                int pos = lower_bound(p + 1, p + m + 1, tmp) - p;
                if (pos <= m){
                    cur++;
                    q[cur] = (Node){pos, m};
                }
            }
        }
        else if (a < 0){
            //slower
            if (v0 > vl){
                int tmp1 = (v0 * v0 - vl * vl) / (-2 * a);
                int tmp2 = up(v0 * v0 - vl * vl, -2 * a);
                int tmp = d;
                if (tmp1 == tmp2) tmp += tmp2 - 1;
                else tmp += tmp1;
                tmp = min(tmp, len);
                if (d <= tmp){
                    int pos1 = lower_bound(p + 1, p + m + 1, d) - p;
                    if (pos1 <= m){
                        int pos2 = upper_bound(p + 1, p + m + 1, tmp) - p - 1;
                        if (pos1 <= pos2){
                            cur++;
                            q[cur] = (Node){pos1, pos2};
                        }
                    }
                }
            }
        }
    }
    int L = 0;
    for (int i = 1; i <= cur; i++){
        int l = q[i].l, r = q[i].r;
        maxn[r] = max(maxn[r], l);
        L = max(L, l);
    }
    for (int i = 1; i <= m; i++){
        dp[i][0] = maxn[i];
    }
    for (int j = 1; j <= 17; j++){
        for (int i = 1; i <= n - (1 << j) + 1; i++){
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
        }
    }
    f[0] = 0;
    for (int i = 1; i <= m; i++){
        int l = 0, r = i - 1, pos = 0;
        while (l <= r){
            int mid = l + r >> 1;
            if (query(mid + 1, i - 1) <= mid){
                pos = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        f[i] = min(f[i], f[pos] + 1);
    }
    int ans = INF;
    for (int i = L; i <= m; i++){
        ans = min(ans, f[i]);
    }
    cout << cur << ' ' << m - ans << endl;
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        test();
    }
    return 0;
}
