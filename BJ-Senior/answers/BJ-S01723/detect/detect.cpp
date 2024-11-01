#include<bits/stdc++.h>
using namespace std;
struct seg
{
    double l;
    int idr;
};
int n, m, L, V;
int a[100005], v[100005], sc[100005], st[100005];
vector<seg> carout;

bool cmp(seg x, seg y)
{
    return x.idr == y.idr ? x.l - y.l > 1e-7 : x.idr > y.idr;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(st, 0, sizeof(st));
        memset(a, 0, sizeof(a));
        memset(v, 0, sizeof(v));
        memset(sc, 0, sizeof(sc));
        carout.clear();
        cin >> n >> m >> L >> V;
        int cntover = 0, cntclose = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> st[i] >> v[i] >> a[i];
        }
        for(int i = 1; i <= m; i++) cin >> sc[i];
        sort(sc + 1, sc + 1 + m);
        double flag = -1;
        int delta = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] < 0)
            {
                int scanner = lower_bound(sc + 1, sc + 1 + m, st[i]) - sc;
                if(scanner > m) continue;
                double vt = sqrt(2.0 * a[i] * (sc[scanner] - st[i]) + 1.0 * v[i] * v[i]);
                // cout << st[i] << ',' << scanner << ',' << sc[scanner] << ',' << vt << ' ';
                if(vt - V > 1e-7)
                {
                    carout.push_back({((1.0 * V * V - 1.0 * v[i] * v[i]) / (2.00 * a[i])) + 1.0 * st[i], scanner});
                    cntover++;
                }
            }
            else
            {
                double vt = sqrt(2.0 * a[i] * (sc[m] - st[i]) + 1.0 * v[i] * v[i]);
                if(sc[m] >= st[i] && vt - V > 1e-7) 
                {
                    delta = 1;
                    flag = max(flag, max(((1.0 * V * V - 1.0 * v[i] * v[i]) / (2.00 * a[i])) + 1.0 * st[i], 1.0 * v[i]));
                    cntover++;
                }
            }
        }
        sort(carout.begin(), carout.end(), cmp);
        int cnt = 0, now = INT_MAX;
        for(auto i : carout)
        {
            // cout << i.l << ',' << sc[i.idr] << ';' << now << ' ';
            if(now - i.l > 1e-7)
            {
                cnt++;
                now = sc[i.idr];
                if(now - flag > 1e-7) delta = 0;
            }
        }
        // cout << endl;
        cout << cntover << ' ' << (m - cnt - delta) << endl;
    }
    return 0;
}
