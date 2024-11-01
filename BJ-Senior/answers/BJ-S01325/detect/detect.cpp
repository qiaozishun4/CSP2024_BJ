#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
int d[N], v[N], a[N], p[N];
vector<ll> vi[N];
set<ll> st;
ll sqr(int a) { return a * a; }
signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        memset(vi, 0, sizeof(vi));
        st.clear();
        ll n, m, L, V;
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++) cin >> d[i] >> v[i] >> a[i];
        for(int i = 1;i <= m;i++) cin >> p[i];
        int cnt = 0, ans = 0;
        for(int i = 1;i <= n;i++)
        {
            int x, y;
            double s = ((sqr(V) - sqr(v[i])) / (2.00 * a[i]));
            ll s1 = ceil(s);
            if(a[i] == 0 && v[i] <= V) continue;
            else if(a[i] == 0 && v[i] > V)
            {
                x = d[i], y = L;
            }
            else if(a[i] > 0)
            {
                if(s1 + d[i] > L) continue;
                x = s1 + d[i] + 1;
                y = L;
            }
            else if(a[i] < 0)
            {
                x = d[i];
                y = min(s1 + d[i], L + 1) - 1;
            }
            bool f = 1;
            for(int j = 1;j <= m;j++)
            {
                if(x <= p[j] && y >= p[j])
                {
                    cnt += f;
                    f = 0;
                    vi[j].push_back(i);
                }
            }
        }

        for(int i = 1;i <= m;i++)
        {
            int op = st.size();
            for(int j = 0;j < vi[i].size();j++) st.insert(vi[i][j]);
            if(st.size() == op) ans++;
        }
        cout << cnt << " " << ans;
    }
    return 0;
}
