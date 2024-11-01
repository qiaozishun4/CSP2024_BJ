#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, l, v;
struct car
{
    ll d, v, a;
}a[100005];
ll p[100005];
bool vis[100005];
ll t;
double sum_dist(ll v, ll a, ll t)
{
    return v * t + 0.5 * a * t * t;
}
double calc(ll v, ll a, ll t)
{
    // return sqrt(v * v + 2 * a * sum_dist(v, a, t));
    return sqrt(v * v + 2 * a * t);
}
// ll find(ll v, ll a)
// {
    
// }
void work()
{
    ll cnt = 0;
    cin >> n >> m >> l >> v;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].d >> a[i].v >> a[i].a;
    }
    for(int i = 1; i <= m; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= 1; j--)
        {
            if(p[j] < a[i].d)
                break;
            if(calc(a[i].v, a[i].a, p[j] - a[i].d) > v)
            {
                vis[j] = 1;
                // cout << i << ":" << j << "\n";
                cnt++;
                break;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++)
    {
        ans += !vis[i];
        // cout << vis[i] << " ";
        vis[i] = 0;
    }
    // cout << "\n";
    cout << cnt << " " << ans << "\n";
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ll t;
    cin >> t;
    // t = 10;
    while(t--)
        work();
    return 0;
}