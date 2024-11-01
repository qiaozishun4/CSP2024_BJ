/*
Glory Glory Man United
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
const double eps = 1e-7;
struct node
{
    double start, end;
    bool fs, fe;
}car[N], car2[N];
int n, m, L;
double V;
double p[N];
int sum[N], vis[N];

bool cmp(node x, node y)
{
    if (x.start  - y.start< eps) return 1;
    else if (x.start == y.start && x.fs - y.fs > eps) return 1;
    else if (x.start == y.start && x.fs == y.fs && (x.end - y.end < eps || (x.end == y.end && x.fe - y.fe < eps))) return 1;
    return 0;
}

bool cmp2(node x, node y)
{
    if (x.end - y.end < eps) return 1;
    else if (x.end == y.end && x.fe - y.fe < eps) return 1;
    else if (x.end == y.end && x.fe == y.fe && (x.start - y.start < eps || (x.start == y.start && x.fs - y.fs > eps))) return 1;
    return 0;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%lf", &n, &m, &L, &V);
        for (int i = 1; i <= m; i++) sum[i] = 0, vis[i] = 0;
        int tot = 0;
        int ff = 1;
        for (int i = 1; i <= n; i++)
        { 
            double d, v0;
            int a;
            scanf("%lf%lf%d", &d, &v0, &a);
            if (a != 0) ff = 0;
            if (a <= 0 && v0 <= V) continue;
            tot++;
            if (a >= 0 && v0 > V) car[tot].start = d, car[tot].end = L, car[tot].fs = 1, car[tot].fe = 1;
            else if (a > 0 && v0 < V) car[tot].start = d + (V * V - v0 * v0) / (2.0 * a), car[tot].end = L, car[tot].fs = 0, car[tot].fe = 1;
            else if (a < 0 && v0 > V) car[tot].start = d, car[tot].end = d + (V * V - v0 * v0) / (2.0 * a), car[tot].fs = 1, car[tot].fe = 0;
        }
        int maxnp = 0;
        for (int i = 1; i <= m; i++) scanf("%lf", &p[i]), maxnp = max(maxnp, (int)p[i]);
        if (ff == 1)
        {
            if (tot == 0) cout << "0 " << m << endl;
            else
            {
                int cntans = 0;
                for (int i = 1; i <= tot; i++)
                {
                    if (maxnp > car[i].start || (maxnp > car[i].start && car[i].fs == 1)) cntans++;
                }
                cout << cntans << " ";
                if (cntans != 0) cout << m - 1 << endl;
                else cout << m << endl;
            }
        }
        else
        {
        int now = 1, cnt = 0, tot_new = 0;
            sort(car + 1, car + 1 + tot, cmp);
            sort(p + 1, p + m + 1);
            for (int i = 1; i <= tot; i++)
            {
                while (p[now] - car[i].start < eps || (p[now] == car[i].start && car[i].fs == 0)) now += 1;
                if ((car[i].start - p[now] < eps || (car[i].start == p[now] && car[i].fs == 1)) && (car[i].end - p[now] > eps || (car[i].end == p[now] && car[i].fe == 1)))
                {
                    cnt++;
                    tot_new++;
                    car2[tot_new].start = car[i].start, car2[tot_new].end = car[i].end, car2[tot_new].fs = car[i].fs, car2[tot_new].fe = car[i].fe;
                }
            }
            for (int i = 1; i <= tot; i++)
                for (int j = 1; j <= m; j++)
                {
                    if ((car2[i].start - p[j] < eps || (car2[i].start == p[j] && car2[i].fs == 1)) && (car2[i].end - p[j] > eps || (car2[i].end == p[j] && car2[i].fe == 1))) sum[j]++;
                }
            cout << cnt << " "; 
            int ans = 0;
            sort(car2 + 1, car2 + 1 + tot_new, cmp2);
            int pos = 1;
            // for (int i = 1; i <= m; i++) cout << sum[i] << " ";
            // cout << endl;
            for (int i = 1; i <= tot_new; i++)
            {
                if (vis[i]) continue; 
                int maxn = -2e9, maxn_pos = 0;
                for (pos = 1; pos <= m; pos++)
                { 
                    if (sum[pos] > maxn && ((p[pos] > car2[i].start || (p[pos] == car2[i].start && car2[i].fs == 1)) && (p[pos] < car2[i].end || (p[pos] == car2[i].end && car2[i].fe == 1)))) {maxn = sum[pos], maxn_pos = pos;}
                }
                ans++;
                for (int j = 1; j <= tot_new; j++)
                {
                    if ((p[maxn_pos] > car2[j].start || (p[maxn_pos] == car2[j].start && car2[j].fs == 1)) && (p[maxn_pos] < car2[j].end || (p[maxn_pos] == car2[j].end && car2[j].fe == 1))) vis[j] = 1;
                }
            }
            // for (int i = 1; i <= tot_new; i++) cout << vis[i] << " "; 
            cout << n - ans << endl; 
        }
    }
    return 0;
}
/*
1
5 5 15 3
0 3 0 
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/