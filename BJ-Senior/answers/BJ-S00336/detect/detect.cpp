#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = (int)1e5 + 10;
const double eps = 1e-8;
double T, n, m, L, V, d[N], v[N], a[N], p[N], w, cnt, cont[N], bg[N], nd[N], st[1000005][55], ans;
bool vis[N];

struct rode
{
    double s, t;
} b[N];

int ST(int l, int r)
{
    int k = log2(r - l + 1);
    if(cont[(int)st[l][k]] < cont[(int)st[r - (1 << k) + 1][k]] || (cont[(int)st[l][k]] == cont[(int)st[r - (1 << k) + 1][k]] && (st[l][k] < st[r - (1 << k) + 1][k])))
        return st[r - (1 << k) + 1][k];
    return st[l][k];
}

bool cmp(rode x, rode y)
{
    if(x.s != y.s) return x.s < y.s;
    return x.t < y.t;
}

int main()
{
    freopen("detect2.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin >> T;
    while(T --)
    {
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i ++)
            cin >> d[i] >> v[i] >> a[i];
        for(int j = 1; j <= m; j ++)
            cin >> p[j];

        for(int i = 1; i <= n; i ++)
        {
            bool flag = false;

            if(a[i] == 0)
                if(V < v[i])
                {
                    b[(int)++ cnt] = rode{d[i], L};
                    flag = true;
                }
            if(a[i] != 0)
            {
                double num = (V * V - v[i] * v[i]) / (2 * a[i]);
                if(L > num + d[i] && a[i] > 0)
                {
                    b[(int)++ cnt] = rode{d[i] + eps + num, L};
                    flag = true;
                }
                else
                    if(a[i] < 0)
                        if(V < v[i])
                        {
                            b[(int)++ cnt] = rode{d[i], d[i] + num - eps};
                            flag = true;
                        }
            }

            if(flag)
            {
                int begining = lower_bound(p + 1, p + (int)m + 1, b[(int)cnt].s) - p;
                int ending = upper_bound(p + 1, p + (int)m + 1, b[(int)cnt].t) - p - 1;
                bool check = false;
                for(int i = begining; i <= ending; i ++)
                {
                    cont[i] ++;
                    check = true;
                }
                if(!check) cnt --;
            }
        }

        sort(b + 1, b + (int)cnt + 1, cmp);

        for(int i = 1; i <= cnt; i ++)
            bg[i] = b[i].s, nd[i] = b[i].t;

        for(int i = 1; i <= L; i ++)
            if(lower_bound(p + 1, p + (int)m + 1, i) - p != upper_bound(p + 1, p + (int)m + 1, i) - p)
                st[i][0] = i;
            else
                st[i][0] = 100001;

        cont[100001] = 2e9;

        for(int j = 1; (1 << j) <= L; j ++)
            for(int i = 1; i + (1 << j) - 1 <= L; j ++)
                if(cont[(int)st[i][j - 1]] < cont[(int)st[i + (1 << j - 1)][j - 1]] || (cont[(int)st[i][j - 1]] == cont[(int)st[i + (1 << j - 1)][j - 1]] && (st[i][j - 1] < st[i + (1 << j - 1)][j - 1])))
                    st[i][j] = st[i + (1 << j - 1)][j - 1];
                else
                    st[i][j] = st[i][j - 1];

        for(int i = 1; i <= cnt; i ++)
            if(!vis[i])
            {
                int begining = lower_bound(p + 1, p + (int)m + 1, b[(int)cnt].s) - p;
                int ending = upper_bound(p + 1, p + (int)m + 1, b[(int)cnt].t) - p - 1;
                int num = ST(p[begining], p[ending]);
                begining = upper_bound(nd + 1, nd + (int)cnt + 1, p[(int)num]) - nd - 1;
                ending = upper_bound(bg + 1, bg + (int)cnt + 1, p[(int)num]) - bg - 1;
                for(int j = begining; j <= ending; j ++)
                    vis[j] = true;
                ans ++;
            }

        cout << cnt << ' ' << m - ans << endl;

        cnt = ans = 0;
    }

}
