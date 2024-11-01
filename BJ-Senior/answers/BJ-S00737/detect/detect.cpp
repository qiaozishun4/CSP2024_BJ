#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+3;

int d[N], v[N], a[N], p[N];
pair<int, int> q[N];

int main()
{
    ios::sync_with_stdio(false);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
    int n, m, L, V;
    cin >> n >> m >> L >> V;
    for(int i = 1; i <= n; i++)
    {
        cin >> d[i] >> v[i] >> a[i];
        if(a[i] >= 0 && v[i] > V)
        {
            q[i] = make_pair(d[i], L);
        }
        else if(a[i] > 0 && v[i] <= V)
        {
            q[i] = make_pair((V*V-v[i]*v[i]+2*a[i]-1)/2*a[i]+d[i], L);
        }
        else if(a[i] < 0 && v[i] > V)
        {
            q[i] = make_pair(d[i], (V*V-v[i]*v[i])/2*a[i]+d[i]);
        }
        else
            q[i] = make_pair(0,0);
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> p[i];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(p[j] >= q[i].first && p[i] <= q[i].second)
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << " ";
    cout << 0 << endl;
    }
    return 0;
}
