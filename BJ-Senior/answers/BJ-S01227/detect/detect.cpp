#include <bits/stdc++.h>
using namespace std;
int a[3005], b[2005], c[3005];
int d[100005];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, j, k;
        cin >> n >> m >> j >> k;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
        }
        if(c[1] == 0)
        {
            for(int i = 1; i <= m; i++)
            {
                cin >> d[i];
            }
            sort(d + 1, d + m + 1);
            int ans = 0;
            for(int i = 1; i <= n; i++)
            {
                if(a[i] > d[m])
                {
                    continue;
                }else if(a[i] <= d[m] && b[i] > k)
                {
                    ans++;
                }else if(a[i] <= d[m] && b[i] <= k)
                {
                    continue;
                }
            }
            cout << ans << " " << m - 1 << endl;

        }else if(c[1] < 0)
        {
            int ans = 0;
            for(int i = 1; i <= m; i++)
            {
                cin >> d[i];
            }
            sort(d + 1, d + m + 1);
            for(int i = 1; i <= n; i++)
            {
                if(a[i] < d[1])
                {
                    continue;
                }else if(a[i] >= d[1] && b[i] >= k)
                {
                    ans++;
                    continue;
                }else if(a[i] >= d[1] && b[i] < k)
                {
                    int v = b[i];
                    int s = b[i];
                    int sz;
                    sz = a[i] - d[1];
                    while(s < sz)
                    {
                        if(v > k)
                        {
                            ans++;
                            break;
                        }
                        v += abs(c[i]);
                        s += v;
                    }
                }
            }
            cout << ans << " " << m - 1;
        }else
        {
            int ans = 0;
            for(int i = 1; i <= m; i++)
            {
                cin >> d[i];
            }
            sort(d + 1, d + m + 1);
            for(int i = 1; i <= n; i++)
            {
                if(a[i] > d[m])
                {
                    continue;
                }else if(a[i] <= d[m] && b[i] >= k)
                {
                    ans++;
                    continue;
                }else if(a[i] <= d[m] && b[i] < k)
                {
                    int v = b[i];
                    int s = b[i];
                    int sz;
                    sz = d[m] - a[i];
                    while(s < sz)
                    {
                        if(v > k)
                        {
                            ans++;
                            break;
                        }
                        v += abs(c[i]);
                        s += v;
                    }
                }
            }
            cout << ans << " " << m - 1 << endl;
        }
    }

    return 0;
}
