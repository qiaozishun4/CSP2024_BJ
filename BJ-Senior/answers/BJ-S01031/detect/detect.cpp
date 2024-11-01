#include<bits/stdc++.h>
using namespace std;

struct car
{
    int d;
    int v;
    int a;
};

vector<struct car> a0, az, af;

int p[100010];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        a0.clear();
        az.clear();
        af.clear();
        int n, m, l, V;
        cin >> n >> m >> l >> V;
        for(int i=0;i<n;i++)
        {
            int td, tv, ta;
            scanf("%d%d%d", &td, &tv, &ta);
            if(ta == 0)
            {
                a0.push_back({td, tv, ta});
            }
            else if(ta > 0)
            {
                az.push_back({td, tv, ta});
            }
            else
            {
                af.push_back({td, tv, ta});
            }
        }
        for(int i=0;i<m;i++) scanf("%d", &p[i]);
        if(a0.size() == n)
        {
            int ans = 0, maxp = 0;
            for(int i=0;i<m;i++) maxp = max(maxp, p[i]);
            for(int i=0;i<a0.size();i++)
            {
                if(a0[i].d <= maxp && a0[i].v > V) ans++;
            }
            cout << ans << ' ';
            if(ans == 0) cout << m << endl;
            else cout << m - 1 << endl;
        }
        else if(az.size() == n)
        {
            int ans = 0, maxp = 0;
            for(int i=0;i<m;i++) maxp = max(maxp, p[i]);
            for(int i=0;i<az.size();i++)
            {
                if(az[i].d <= maxp && az[i].v*az[i].v+2*az[i].a*(maxp-az[i].d) > V*V) ans++;
            }
            cout << ans << ' ';
            if(ans == 0) cout << m << endl;
            else cout << m - 1 << endl;
        }
    }
    return 0;
}
