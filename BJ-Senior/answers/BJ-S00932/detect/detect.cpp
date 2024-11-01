#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

struct xian
{
    int l, r;
};
vector <xian> ve;

int d[N], v[N], a[N];
int p[N];

bool pai_xu(xian x, xian y)
{
    return x.l < y.l;
}

void qing()
{
    int i, j, k;
    for(i=1; i<ve.size(); i++)
    {
        while(i >= 1 && ve[i-1].l <= ve[i].l && ve[i].r <= ve[i-1].r)
        {
            ve.erase(ve.begin() + i - 1, ve.begin() + i);
            i--;
        }
    }
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
    {
        ve.clear();
        int i, j, k;
        int n, m, L, V;
        scanf("%d %d %d %d", &n, &m, &L, &V);
        for(i=1; i<=n; i++)
        {
            scanf("%d %d %d", &d[i], &v[i], &a[i]);
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d", &p[i]);
        }
        sort(p + 1, p + 1 + m);
        int chao, ans;
        chao = ans = 0;
        for(i=1; i<=n; i++)
        {
            if(a[i] == 0)
            {
                if(v[i] > V && d[i] <= p[m])
                {
                    chao++;
                    xian t;
                    t.l = d[i];
                    t.r = p[m];
                    ve.push_back(t);
                }
            }
            else if(a[i] > 0)
            {
                int x = 0;
                if(v[i] > V)
                {
                    x = d[i];
                }
                else
                {
                    x = 1 + d[i] + (V * V - v[i] * v[i]) / (2 * a[i]);
                }
                if(x <= p[m])
                {
                    chao++;
                    xian t;
                    t.l = x;
                    t.r = p[m];
                    ve.push_back(t);
                }
            }
            else
            {
                int x = 0;
                if(v[i] > V)
                {
                    x = (V * V - v[i] * v[i]) / 2 / a[i];
                    if(x * a[i] * 2 == (V * V - v[i] * v[i]))
                    {
                        x--;
                    }
                    int y = upper_bound(p + 1, p + 1 + m, d[i] + x) - p - 1;
                    if(d[i] <= p[y] && p[y] <= d[i] + x)
                    {
                        chao++;
                        xian t;
                        t.l = d[i];
                        t.r = d[i] + x;
                        ve.push_back(t);
                    }
                }
            }
        }
        sort(ve.begin(), ve.end(), pai_xu);
        //qing();
        int zhi = 0;
        for(i=0; i<ve.size(); i++)
        {
            if(zhi >= ve[i].r)
            {
                int x;
                x = upper_bound(p + 1, p + 1 + m, ve[i].r) - p - 1;
                zhi = p[x];
                //ans++;
                continue;
            }
            if(zhi >= ve[i].l)
            {
                continue;
            }
            int x;
            x = upper_bound(p + 1, p + 1 + m, ve[i].r) - p - 1;
            zhi = p[x];
            ans++;
        }
        printf("%d %d\n", chao, m - ans);
    }
	return 0;
}
