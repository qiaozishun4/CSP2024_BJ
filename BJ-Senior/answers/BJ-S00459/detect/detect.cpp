#include <bits/stdc++.h>

using namespace std;
int T, n, m, L, V, d[100005], v[100005], ans, a[100005], p[100005], maxn;
double chao_l[100005], chao_r[1000005];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    while(T--){
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++)
            cin >> d[i] >> v[i] >> a[i];
        for(int i = 1;i <= m;i++){
            cin >> p[i];
            maxn = max(p[i], maxn);
        }
        for(int i = 1;i <= n;i++){
            if(v[i] > V && d[i] <= maxn) ans++;
        }

        cout << ans << " " << m-1 << endl;
    }
    return 0;
}
