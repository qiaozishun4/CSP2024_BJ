#include<bits/stdc++.h>
using namespace std;
const int N = int(1e5) + 10;
int p[N];
struct car
{
    int d, v, a;
    bool chao;
} c[N];
struct seg
{
    int l, r;
    bool operator < (const seg& cmp) const {return l < cmp.l;}
} s[N];
int Divc(int x, int y) {return (x + y - 1) / y;}
void Solve()
{
    int n, m, l, mxv;
    cin >> n >> m >> l >> mxv;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i].d >> c[i].v >> c[i].a;
    }
    for(int i = 1; i <= m; i++) cin >> p[i];
    for(int i = 1; i <= n; i++)
    {
        if(c[i].a == 0) c[i].chao = (c[i].d <= p[m] && c[i].v > mxv);
        else if(c[i].a > 0)
        {
            int tmp = max((mxv * mxv - c[i].v * c[i].v) / (2 * c[i].a), 0);
            c[i].chao = ((c[i].v > mxv && c[i].d <= p[m]) || tmp + c[i].d < p[m]);
        }
        else if(c[i].v <= mxv) c[i].chao = false;
        else
        {
            int tmp = Divc(c[i].v * c[i].v - mxv * mxv, -2 * c[i].a);
            int rr = lower_bound(p + 1, p + m + 1, c[i].d + tmp) - p - 1;
            int ll = lower_bound(p + 1, p + m + 1, c[i].d) - p;
            c[i].chao = (ll <= rr);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(c[i].chao)
        {
            res++;
            if(c[i].a > 0)
            {
                int tmp = max((mxv * mxv - c[i].v * c[i].v) / (2 * c[i].a), 0);
                if(mxv >= c[i].v)
                    s[res].l = upper_bound(p + 1, p + m + 1, c[i].d + tmp) - p;
                else
                    s[res].l = lower_bound(p + 1, p + m + 1, c[i].d) - p;
                s[res].r = m;
            }
            else if(c[i].a == 0)
            {
                s[res].l = lower_bound(p + 1, p + m + 1, c[i].d) - p;
                s[res].r = m;
            }
            else
            {
                int tmp = Divc(c[i].v * c[i].v - mxv * mxv, -2 * c[i].a);
                s[res].r = lower_bound(p + 1, p + m + 1, c[i].d + tmp) - p - 1;
                s[res].l = lower_bound(p + 1, p + m + 1, c[i].d) - p;
            }
        }
    cout << res << ' ';
    sort(s + 1, s + res + 1);
    int tot = 0;
    for(int i = 1; i <= res; i++)
    {
        tot++;
        int j = i, mir = s[i].r;
        while(j + 1 <= res && s[j + 1].l <= mir)
        {
            j++;
            mir = min(mir, s[j].r);
        }
        i = j;
    }
    cout << m - tot << '\n';
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) Solve();
    return 0;
}
