#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll d[100005], v[100005], a[100005];
ll p[100005];
int n, m;
ll L, V;
vector<pair<int,int>> vec;
void solve()
{
    vec.clear();
    cin >> n >> m >> L >> V;
    for(int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
    for(int i = 1; i <= m; i++) cin >> p[i];
    p[m+1] = 1e9;
    int ans1 = 0;
    for(int i = 1; i <= n; i++)
    {
        ll l = d[i], r;
        if(a[i] == 0)
        {
            if(v[i] <= V) continue;
            r = L;
        }
        else if(a[i] < 0)
        {
            if(v[i] <= V) continue;
            r = min(L, d[i]+(v[i]*v[i]-V*V-1)/(-2*a[i]));
        }
        else {
            if(v[i] <= V)
            {
                l = d[i]+(V*V-v[i]*v[i])/(2*a[i])+1;
            }
            r = L;
        }
        l = lower_bound(p+1, p+m+1, l)-p;
        r = upper_bound(p+1, p+m+1, r)-p-1;
        if(l > r) continue;
        ans1++;
        vec.emplace_back(r, l);
    }
    int lst = -1, ans2 = 0;
    sort(vec.begin(), vec.end());
    for(auto [r, l]: vec)
    {
        if(lst >= l) continue;
        ans2++; lst = r;
    }
    cout << ans1 << " " << m-ans2 << endl;
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}