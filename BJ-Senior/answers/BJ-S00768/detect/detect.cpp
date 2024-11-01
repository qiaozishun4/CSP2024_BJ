/*#include <bits/stdc++.h>
using namespace std;
int r[100005], a[100005];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    bool flag = 1;
    for (int i = 1;i <= n;i++)
    {
        cin >> r[i];
        a[i] = 1;
        if (r[i] > 2) flag = 0;
    }
    if (flag) {
        int sum = 0, sum2 = 0;
        for (int i = 1;i <= n;i++) {
            if (r[i] == 2) {
                sum++;
            }
            if (r[i] == 1) {
                sum2++;
            }
        }
        cout << max(sum, sum2) << endl;
        return 0;
    }
    sort(r + 1, r + n + 1);
    for (int i = 2;i <= n+1;i++) {
        for (int j = 1;j <= i;j++) {
            if (r[j] < r[i] && a[j] != -1 && a[i] != 0)
            {
                a[j] = -1;
                a[i] = 0;
            }
        }
    }
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] != -1) sum++;
    }
    cout << sum << endl;
    for (int i = 1;i <= n;i++) {
        cout << r[i] << " ";
    }
    cout << endl;
    for (int i = 1;i <= n;i++) {
        cout << a[i] << " ";
    }
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
int d[100005], v[100005], a[100005], c[100005];
int f[10005][10005] = {-1};
int num[100005];
bool flag[100005] = {1};
int cnt2;
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        int n, m, l, V;
        cin >> n >> m >> l >> V;
        for (int j = 1;j <= n;j++) {
            cin >> d[j] >> v[j] >> a[j];
        }
        for (int j = 1;j <= m;j++) {
            cin >> c[j];
        }
        //输入完成
        int cnt = 0;
        for (int j = 1;j <= n;j++) {
            if (a[j] == 0 && v[j] == V) continue;
            if (a[j] < 0 && v[j] <= V) continue;
            if (a[j] >= 0 && v[j] >= V) {
                cnt++;
                for (int k = 1;k <= m;k++) {
                    if (c[k] > d[j]) {
                        f[j][k] = 1;
                    }
                }

            }
            //1
            double s = d[j] + 0.5 * (V * V - v[j] * v[j]) / a[j];
            bool flag2;
            if (v[j] > V && a[j] < 0) {
                for (int k = 1;k <= m;k++) {
                    if (c[k] < s && c[k] >= d[j]) {
                        f[j][k] = 1;
                        flag2 = true;
                    }
                }
                if (flag2) cnt++;
                flag2 = 0;
            }
            if (v[j] < V && a[j] > 0) {
                for (int k = m;k >= 1;k--) {
                    if (c[k] > s) {
                        f[j][k] = 1;
                        flag2 = 1;
                    }
                }
                if (flag2) cnt++;
                flag2 = 0;
            }
            /*cout << j << " " << s << " " << cnt << endl;
            for (int j = 1;j <= n;j++) {
                for (int k = 1;k <= m;k++) {
                    cout << f[j][k] << " ";
                }
                cout << endl;
            }
            cout << endl;*/
        }
        cout << cnt << " ";
        //2
        /*nt cc = 0;
        for (int j = 1;j <= n;j++) {
            cc = 0;
            for (int k = 1;k <= m;k++) {
                if (f[j][k] != 0) {
                    num[cnt2+1] = f[j][k];
                    cc++;
                }
                if (cc > 1) {
                    num[cnt2+1] = 0;
                    break;
                }
            }
            if (cc = 1) {
                cnt2++;
                flag[j] = 0;
            }
            if (cc = 0) {
                flag[j] = 0;
            }
        }
        for (int j = 1;j <= n;j++) {
            for (int k = 1;k <= m;k++) {
                yes(j, k);
            }
        }
        for (int z = 1;z <= m;z++) {
            for (int j = 1;j <= n;j++) {
                if (flag[j] == 0) continue;
                for (int k = 1;k <= m;k++) {

                }
            }
        }*/
        int sum = 0;
        for (int j = 1;j <= n;j++) {
            sum = 0;
            for (int k = 1;k <= m;k++) {
                sum += f[j][k];
            }
            if (sum == 0) {
                for (int k = 1;k <= m;k++) {
                    f[j][k] = 1;
                }
            }
        }
        /*int times[100005] = {0};
        for (int j = 1;j <= n;j++) {
            for (int k = 1;k <= m;k++) {
                times[j] += f[j][k];
            }
        }
        for (int j = 1;j <= m;j++) {
            for (int k = 1;k <= n;k++) {
                if (f[k][j] == 1 && times[k] >1) {
                    times[k]--;
                }
            }
        }*/
        int summ = 0, ans = 0;
        bool fin = 0;
        for (int j = 1;j <= m;j++) {
            for (int k = 1;k <= m;k++) {
                summ = 0;
                for (int l = 1;l <= n;l++) {
                    if (j == k) break;
                    summ += f[k][l];
                }
                if (summ == 0) {
                    break;
                    fin = 1;
                }
            }
            if (!fin) {
                ans++;
                //cout << j << " ";
                //cout << ans << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
