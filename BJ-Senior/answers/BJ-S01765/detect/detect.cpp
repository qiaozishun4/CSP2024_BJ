#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 100005;
const int MAXM = 2050;
const int MAXK = 2050 * 2050;
const int MAXL = 1000005;

struct node
{
    int l, r;
}  arr[MAXN];

int t;
int n, m, L, V, ans1, ans2;
int p[MAXN], fl[MAXN], f[200][MAXM], f1[MAXK];
vector<int> h[MAXL];
bool fla, flb, flc;

void cal(int d, int v, int a, int i)
{
    fl[i] = false;

    if(a == 0)
    {
        if(v > V)
        {
            fl[i] = true;
            arr[i].l = d, arr[i].r = L;
        }
        else
        {
            fl[i] = false;
        }

        return;
    }

    if(a < 0)
    {
        if(v <= V)
        {
            fl[i] = false;
            return;
        }

        fl[i] = true;
        int t1 = abs(V * V - v * v), t2 = abs(2 * a);
        int s = t1 / t2;
        if((t2 * s) == t1)  s --;

        arr[i].l = d, arr[i].r = min(L, d + s);
    }
    else
    {
        fl[i] = true;
        if(v > V)
        {
            arr[i].l = d, arr[i].r = L;
            return;
        }

        int t1 = abs(V * V - v * v), t2 = abs(2 * a);
        int s = t1 / t2;
        s ++;

        arr[i].l = min(L, d + s), arr[i].r = L;
        if(d + s > L)  fl[i] = false;
    }

    return;
}

void clear()
{
    if(!fla && !flb)
    {
        if(n <= 10)
        {
            for(int i = 0; i <= 10; i ++)
                for(int j = 0; j <= 2048; j ++)
                    f[i][j] = 1000000;
        }
        else
        {
            for(int i = 0; i <= 2048 * 2048; i ++)
                f1[i] = 1000000;
        }
    }
    fla = flb = flc = true;
    for(int i = 1; i <= n; i ++)  arr[i].l = arr[i].r = 0;
    ans1 = ans2 = 0;
}

void solve()
{
    clear();

    cin >> n >> m >> L >> V;

    fla = true, flb = true, flc = true;
    for(int i = 1; i <= n; i ++)
    {
        int d, v, a;
        cin >> d >> v >> a;
        if(a != 0)  fla = false;
        if(a < 0)  flb = false;
        if(a > 0)  flc = false;
        cal(d, v, a, i);
    }

    for(int i = 1; i <= m; i ++)
        cin >> p[i];

    if(fla || flb)
    {
        int mx = p[m];
        ans2 = m - 1;
        for(int i = 1; i <= n; i ++)
        {
            if(fl[i] && arr[i].l <= mx)  ans1 ++;
        }

        if(!ans1)  ans2 = m;
    }
    else if(n <= 10)
    {
        int tar = 0;
        for(int i = 1; i <= n; i ++)
        {
            bool fll = false;
            for(int j = 1; j <= m; j ++)
                if(p[j] >= arr[i].l && p[j] <= arr[i].r)  h[p[j]].push_back(i), fll = true;
            if(fll)
            {
                tar |= 1 << (i - 1);
                ans1 ++;
            }
        }

        f[0][0] = 0;
        for(int i = 1; i <= m; i ++)
        {
            for(int j = 0; j < (1 << n); j ++)
            {
                int j1 = j;
                for(int k = 0; k < h[p[i]].size(); k ++)
                {
                    int w = h[p[i]][k];
                    j1 = j1 | (1 << (w - 1));
                }

                f[i][j] = min(f[i][j], f[i - 1][j]);
                f[i][j1] = min(f[i][j1], f[i - 1][j] + 1);
            }
        }

        ans2 = m - f[m][tar];
    }
    else
    {
        int tar = 0;
        for(int i = 1; i <= n; i ++)
        {
            bool fll = false;
            for(int j = 1; j <= m; j ++)
                if(p[j] >= arr[i].l && p[j] <= arr[i].r)  h[p[j]].push_back(i), fll = true;
            if(fll)
            {
                tar |= 1 << (i - 1);
                ans1 ++;
            }
        }

        f1[0] = 0;
        for(int i = 1; i <= m; i ++)
        {
            for(int j = (1 << n) - 1; j >= 0; j --)
            {
                int j1 = j;

                for(int k = 0; k < h[p[i]].size(); k ++)
                {

                    int w = h[p[i]][k];
                    j1 |= (1 << (w - 1));
                }

                f1[j1] = min(f1[j1], f1[j] + 1);
            }
        }

        ans2 = m - f1[tar];
    }

    cout << ans1 << " " << ans2 << endl;
    return;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin >> t;
    while(t --)
    {
        solve();
    }
    return 0;
}
