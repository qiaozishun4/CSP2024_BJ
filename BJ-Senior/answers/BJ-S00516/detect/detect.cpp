#include<bits/stdc++.h>
using namespace std;
struct p
{
    int d , l , r;
    double v , a , rl;
    bool done;
}a[100005];
bool cmp(p l , p r)
{
    return l.rl < r.rl;
}
int t , n , m , ans1 , ans2 , dtmp , qzh[100005];
double l , v , p[100005];
bool vis[100005];
inline int minp(int q)
{
    int l = 1 , r = m , mid , ans;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(p[mid] >= q)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
inline double calc(double st , double en , double v , double a)
{
    if(v * v + 2 * a * (en - st) < 0)
    {
        return -1;
    }
    return sqrt(v * v + 2 * a * (en - st));
}
inline int maxp(int l , int q , double v , double a , double xs)
{
    int r = m , mid , ans;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(calc(q , p[mid] , v , a) > xs)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    freopen("detect.in" , "r" , stdin);
    freopen("detect.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> l >> v;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i].d >> a[i].v >> a[i].a;
            a[i].l = a[i].r = a[i].rl = -1;
            a[i].done = 0;
        }
        for(int i = 1 ; i <= m ; i++)
        {
            cin >> p[i];
        }
        sort(p + 1 , p + m + 1);
        for(int i = 1 ; i <= n ; i++)
        {
            if(a[i].d > p[m])
            {
                continue;
            }
            int tmp = minp(a[i].d);
            if(calc(a[i].d , p[tmp] , a[i].v , a[i].a) > v)
            {
                a[i].l = tmp;
            }
            else
            {
                a[i].l = -1;
            }
            if(calc(a[i].d , p[m] , a[i].v , a[i].a) > v)
            {
                a[i].r = m;
            }
            else
            {
                a[i].r = -1;
            }
            if(a[i].a < 0)
            {
                a[i].rl = maxp(tmp , a[i].d , a[i].v , a[i].a , v);
            }
            else
            {
                a[i].rl = -1;
            }
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(a[i].l == -1 && a[i].r == -1)
            {
                a[i].done = 1;
            }
        }
        sort(a + 1 , a + n + 1 , cmp);
        for(int i = 1 ; i <= n ; i++)
        {
            if(a[i].l == -1 && a[i].r != -1 && !a[i].done)
            {
                ans1++;
                a[i].done = 1;
                vis[a[i].r] = 1;
            }
        }
        dtmp = -1;
        for(int i = 1 ; i <= n ; i++)
        {
            if(a[i].rl == -1 || a[i].done || (a[i].l == -1 && a[i].r != -1))
            {
                continue;
            }
            if(a[i].l <= dtmp && dtmp <= a[i].rl)
            {
                ans1++;
                a[i].done = 1;
            }
            else
            {
                ans1++;
                dtmp = a[i].rl;
                vis[dtmp] = 1;
                a[i].done = 1;
            }
        }
        for(int i = 1 ; i <= m ; i++)
        {
            qzh[i] = qzh[i - 1] + vis[i];
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(a[i].l != -1 && a[i].r != -1 && !a[i].done)
            {
                ans1++;
                if(qzh[a[i].r] - qzh[a[i].l - 1] == 0)
                {
                    vis[a[i].r] = 1;
                }
            }
        }
        for(int i = 1 ; i <= m ; i++)
        {
            if(vis[i])
            {
                ans2++;
                vis[i] = 0;
            }
        }
        for(int i = 1 ; i <= m ; i++)
        {
            qzh[i] = 0;
        }
        cout << ans1 << ' ' << m - ans2 << '\n';
        ans1 = ans2 = 0;
    }
    return 0;
}