#include<bits/stdc++.h>
using namespace std;
int t;
int d[100005], v[100005], a[100005], p[100005];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        int n, m, L, V, cnt = 0, d_min = 1e9, p_max = -1e9;
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++)
        {
            cin >> d[i] >> v[i] >> a[i];
            d_min = min(d_min, d[i]);
        }
        for(int i = 1;i <= m;i++)
        {
            cin >> p[i];
            p_max = max(p_max, p[i]);
        }
        for(int i = 1;i <= n;i++)
        {
            if(v[i]>V&&d[i]<=p_max)
            {
                cnt++;
            }
        }
        cout << cnt << " ";
        if(d_min>p_max||cnt==0) cout << m << "\n";
        else cout << m-1 << "\n";
    }
    return 0;
}
