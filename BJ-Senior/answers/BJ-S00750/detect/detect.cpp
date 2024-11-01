#include<bits/stdc++.h>
using namespace std;
int d[3010], v[3010], a[3010], p[3010];
bool vis[3010][3010];
bool w[3010];
double velo(int v, int a, int s)
{
    if(!a)return v;
    else return sqrt(v * v + 2 *a * s);
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int TT;
    cin >>TT;
    while(TT--)
    {
        memset(w, 1, sizeof(w));
        memset(vis, 0, sizeof(vis));
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++)cin >> d[i] >> v[i] >> a[i];
        for(int i = 1; i <= m; i++)cin >> p[i];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(d[i] <p[j])continue;
                else if(velo(v[i], a[i], p[j] - d[i]) - V > 1e-10)
                {
                    w[j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(vis[i][j])
                {
                    ++cnt;
                    break;
                }
        cout <<cnt << " ";
        int maxn = 0, minn = INT_MAX;
        for(int i = 1; i <= n; i++)
        {
            int x = lower_bound(vis[i] + 1, vis[i] + m + 1, 1) - vis[i];
            maxn = max(maxn, x);
            minn = min(minn, x);
        }
        cout << maxn - minn + 1 <<"\n";
    }

    return 0;
}
