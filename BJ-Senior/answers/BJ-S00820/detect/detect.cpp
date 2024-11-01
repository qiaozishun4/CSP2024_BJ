#include<bits/stdc++.h>

using namespace std;
long long n, m, L, V;
const int N = 1e5 + 10;
struct Car{
    long long d, v, a;
};
Car d[N];
long long p[N];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T -- )
    {
        memset(p, 0, sizeof p);

        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i ++ )
        {
            cin >> d[i].d >> d[i].v >> d[i].a;
        }
        for(int i = 1; i <= m; i ++ )
        {
            cin >> p[i];
        }
        long long tl = p[m];
        long long ans = 0;
        for(int i = 1; i <= n; i ++ )
        {
            if(d[i].v > V && d[i].d <= tl)
            {
                ans ++ ;
            }
        }
        cout << ans << " ";
        if(ans == 0) cout << m << endl;
        else cout << m - 1 << endl;
    }
	return 0;
}
