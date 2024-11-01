#include <bits/stdc++.h>
using namespace std;
int d[100005], v[100005], a[100005];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, l, V;
        cin >> n >> m >> l >> V;
        for(int i = 1; i <= n;i++)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        int p;
        for(int i = 1; i <= m;i++)
        {
            cin >> p;
        }
        int cnt = 0;
        for(int i = 1; i <= n;i++)
        {
            if(d[i] <= p && v[i] > V)
            {
                cnt++;
            }
        }
        if(cnt == 0) cout << cnt << " " << m << endl;
        else cout << cnt << " " << m - 1 << endl;
    }
    return 0;
}
