#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int T, n, m, L, V;
double p[N];

struct Car
{
    int d, v, a;
    void read() {cin >> d >> v >> a;}
} car[N];

struct Segment
{
    bool flg;
    double l, r;
    bool f, g; //区间左右端点的开闭，0为开，1为闭
    void print()
    {
        cout << flg << ' ' << l << ' ' << r << ' ' << f << ' ' << g << endl;
    }
} c[N];

int num;
pair<int, int> seg[N];

int calc(int typ, double x)
{
    if(typ == 1) //找到 p 中第一个大于等于 x 的位置，没有则返回 m + 1
    {
        // if(p[m] < x) return m + 1;
        return lower_bound(p + 1, p + m + 1, x) - p;
    }
    else if(typ == 2)  //找到 p 中第一个大于 x 的位置，没有则返回 m + 1
    {
        // if(p[m] <= x) return m + 1;
        return upper_bound(p + 1, p + m + 1, x) - p;
    }
    else if(typ == 3) //找到 p 中最后一个小于等于 x 的位置，没有则返回 0
    {
        return upper_bound(p + 1, p + m + 1, x) - p - 1;
    }
    else //找到 p 中最后一个小于 x 的位置，没有则返回 0
    {
        return lower_bound(p + 1, p + m + 1, x) - p - 1;
    }
}

int mn[N];

int b[N];
int lb(int x) {return x & (-x);}
void upd(int x)
{
    for(int i = x; i <= m; i += lb(i)) b[i]++;
}
int sum(int x)
{
    if(x <= 0) return 0;
    int ans = 0;
    for(int i = x; i > 0; i -= lb(i)) ans += b[i];
    return ans;
}
int query(int l, int r)
{
    return sum(r) - sum(l - 1);
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++) car[i].read();
        for(int i = 1; i <= m; i++) cin >> p[i];
        sort(p + 1, p + m + 1);
        for(int i = 1; i <= n; i++)
        {
            int a = car[i].a, v = car[i].v, d = car[i].d;
            if(a == 0)
            {
                if(v <= V) c[i] = {0, 0, 0, 0, 0};
                else c[i] = {1, d, L, 1, 1};
            }
            else if(a > 0)
            {
                if(v > V) c[i] = {1, d, L, 1, 1};
                else c[i] = {1, 1.0 * d + 1.0 * (V * V - v * v) / (2 * a), L, 0, 1};
            }
            else
            {
                if(v <= V) c[i] = {0, 0, 0, 0, 0};
                else c[i] = {1, d, 1.0 * d + 1.0 * (V * V - v * v) / (2 * a), 1, 0};
            }
            if(c[i].l > c[i].r) c[i] = {0, 0, 0, 0, 0};
        }
        num = 0;
        for(int i = 1; i <= n; i++) if(c[i].flg == 1)
        {
            double l = c[i].l, r = c[i].r;
            bool f = c[i].f, g = c[i].g;
            int L = calc((f == 1 ? 1 : 2), l), R = calc((g == 1 ? 3 : 4), r);
            if(1 <= L && L <= m && R >= 1 && R <= m && L <= R) seg[++num] = make_pair(L, R);
        }
        sort(seg + 1, seg + num + 1);
        // for(int i = 1; i <= num; i++) cout << seg[i].first << ' ' << seg[i].second << '\n';
        mn[num + 1] = (int) 1e9;
        for(int i = num; i >= 1; i--)
        {
            mn[i] = min(mn[i + 1], seg[i].second);
        }
        for(int i = 1; i <= num; i++) if(seg[i].second < mn[i + 1])
        {
            int l = seg[i].first, r = seg[i].second;
            if(query(l, r) == 0) upd(r);
        }
        cout << num << ' ' << m - query(1, m) << '\n';
        for(int i = 1; i <= m; i++) p[i] = b[i] = 0;
    }
    return 0;
}