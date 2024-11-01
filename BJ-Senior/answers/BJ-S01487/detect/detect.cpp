#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int d[N] , v[N] , a[N] , p[N];

int main()
{
    freopen("detect.in" , "r" , stdin);
    freopen("detect.out" , "w" , stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n , m , L , V , maxn = -1e9;
        cin >> n >> m >> L >> V;
        for (int i = 1;i <= n;i++) cin >> d[i] >> v[i] >> a[i];
        for (int i = 1;i <= m;i++) 
        {
            cin >> p[i];
            maxn = max(maxn , p[i]);
        }
        int ans = 0;
        for (int i = 1;i <= n;i++)
            if (d[i] <= maxn && v[i] > V)
                ans++;
        cout << ans << " ";
        if (ans == 0) cout << m << endl;
        else cout << m - 1 << endl;
    }
    return  0;
}