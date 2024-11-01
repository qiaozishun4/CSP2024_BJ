# include <bits/stdc++.h>
# define int long long
const int N = 1e5 + 7;
using namespace std;
int T, n, m, L, V;
int d[N], v[N], a[N];
int pos[N];
int l[N], r[N];
int l_[N], r_[N];
bool flag[N];
struct node
{
    int l, r;
}YJH[N];
bool operator < (node a, node b)
{
    return a.l < b.l;
}
int cnt;
void init()
{
    for(int i = 1; i <= n; i++)
    {
        if(a[i] >= 0 && v[i] > V)
        {
            flag[i] = 1;
            l[i] = d[i], r[i] = L;
            continue;
        }
        if(a[i] < 0 && v[i] <= V)
        {
            continue;
        }
        if(a[i] == 0)
        {
            continue;
        }
        int fangcha = V * V - v[i] * v[i];
        int lim;
        if(a[i] > 0)
        {
            lim = d[i] + fangcha / (2 * a[i]) + 1;

            //if(lim < 0) cout << d[i] << " "<<fangcha << " " << a[i] << endl;
            if(lim > L) continue;
            else
            {
                l[i] = lim, r[i] = L;
                flag[i] = 1;
            }
            //if(l[i] < 0 || r[i] < 0) cout << -1 << endl;
        }
        if(a[i] < 0)
        {
            if(fangcha % (2 * a[i]) == 0)
            {
                lim = d[i] + fangcha / (2 * a[i]) - 1;
            }
            else
            {
                lim = d[i] + fangcha / (2 * a[i]);
            }
            lim = min(lim, L);
            l[i] = d[i], r[i] = lim;

            flag[i] = 1;
        }
    }
}
int find_less(int x)
{
    int l = 1, r = m;
    int ret = 0;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(x > pos[mid])
        {
            ret = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    //if(pos[ret - 1] < )
    return ret;
}
int find_much(int x)
{
    //if (x < 0)cout << x << endl;
    int l = 1, r = m;
    int ret = m + 1;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(x < pos[mid])
        {
            ret = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ret;
}
void solve()
{
    cin >> n >> m >> L >> V;
    for(int i = 1; i <= n; i++)
    {
        cin >> d[i] >> v[i] >> a[i];
        flag[i] = 0;
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> pos[i];
    }
    init();

        //cout << upper_bound(pos + 1, pos + m + 1, i) - pos - 1<< endl;

    //for(int i = 0; i <= L + 1; i++)
    //{
     //   cout << find_less(i) << " " << find_much(i) << endl;
    //}
    for(int i = 1; i <= n; i++)
    {
        if(flag[i] == 1)
        {
            //if(l[i] < 0) cout << i << endl;
            int idl = find_much(l[i] - 1);
            int idr = find_less(r[i] + 1);
            if(r[i] == L) idr = m;
            //cout << l[i] <<" "<< r[i] << " " << idl << " " << idr << endl;
            if(idl > idr || idl ==  m + 1 || idr == 0)
            {
                flag[i] = 0;
            }
            l_[i] = idl;
            r_[i] = idr;
        }
    }
    cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(flag[i] == 1)
        {
            YJH[++cnt] = {l_[i], r_[i]};
            //cout << YJH[cnt].l << " " << YJH[cnt].r << endl;
        }
    }
    cout << cnt << " ";
    sort(YJH + 1, YJH + cnt + 1);
    int ans = 0;
    int r = 0;
    for(int i = 1; i <= cnt; i++)
    {
        if(r < YJH[i].l)
        {
            ans++;
            r = YJH[i].r;
            continue;
        }
        else r = min(r, YJH[i].r);
    }
    cout << m - ans << '\n';
    //for(int i = 1; i <= n; i++)
    //{
     //   cout << l[i] << " " << r[i] << endl;
    //}

}
signed main()
{
    ios::sync_with_stdio(0);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while(T--) solve();
    return 0;
}
