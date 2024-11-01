#include <bits/stdc++.h>

using namespace std;

int t, car[100001][3];
double speed[100001];
bool use[100001];

struct px{
    int l, r;
}p[100001];

inline px h(const px& a, const px& b){
    px ans;
    ans.l = -1, ans.r = -2;
    if (a.r < b.l || a.l > b.r)
        return ans;
    ans.l = max(a.l, b.l), ans.r = min(a.r, b.r);
    return ans;
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while (t--){
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++)
            use[i] = false;
        int cnt = n;
        for (int i = 1; i <= n; i++)
            cin >> car[i][0] >> car[i][1] >> car[i][2];
        for (int i = 1; i <= m; i++)
            cin >> speed[i];
        for (int i = 1; i <= n; i++){
            double a = car[i][2], v = car[i][1], b = car[i][0];
            if (a > 0){
                double t = (V - v) / a;
                double l = max(b, v * t + 0.5 * a * t * t + b);
                if (l <= speed[m])
                    p[i].l = int(upper_bound(speed + 1, speed + 1 + n, l) - speed), p[i].r = m;
                else
                    use[i] = true, cnt--;
            }
            else if (a < 0){
                double t = (V - v) / a;
                double l = max(b, v * t + 0.5 * a * t * t + b);
                if (l >= b){
                    p[i].r = int(lower_bound(speed + 1, speed + 1 + n, l) - speed), p[i].l = int(lower_bound(speed + 1, speed + 1 + n, b) - speed);
                    if (speed[p[i].r] >= l)
                        p[i].r--;
                    if (p[i].r < p[i].l)
                        use[i] = true, cnt--;
                }
                else
                    use[i] = true, cnt--;
            }
            else {
                if (v > V)
                    p[i].l = int(upper_bound(speed + 1, speed + 1 + n, b) - speed), p[i].r = m;
                else
                    use[i] = true, cnt--;
            }
        }
        cout << cnt << " ";
        int cnt2 = 0;
        for (int i = 1; i <= n; i++){
            px q = p[i], ans;
            int dis, y;
            if (use[i])
                continue;
            use[i] = true;
            do {
                dis = 0, y = 0;
                for (int i = 1; i <= n; i++)
                    if (!use[i]){
                        px x = h(q, p[i]);
                        if (x.r - x.l > dis)
                            ans = x, dis = x.r - x.l + 1, y = i;
                    }
                
                if (y != 0)
                    q = ans, use[y] = true;
            } while (dis != 0);
            cnt2++;
        }
        cout << m - cnt2 << endl;
    }
    return 0;
}
