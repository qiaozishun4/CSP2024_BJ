#include<bits/stdc++.h>
using namespace std;

int T;
int n, m, le, xs;
int cs[100005];
struct lxm
{
    int jr, cs, js;
}a[100005];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> le >> xs;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].jr >> a[i].cs >> a[i].js;
        }
        int maxn = 0;
        for(int i = 1; i <= m; i++)
        {
            cin >> cs[i];
            maxn = max(maxn, cs[i]);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i].jr <= maxn && a[i].cs > xs)
            {
                cnt++;
            }
        }
        cout << cnt << " ";
        if(cnt == 0)
        {
            cout << n << endl;
        }
        else
        {
            cout << n - 1 << endl;
        }
    }
    return 0;
}
