#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 2000 + 10;
int t, n, a[maxn], f[maxn][maxn];
long long ff[200000 + 10], sum[200000 + 10], gg[200000 + 10];
long long calc(int l, int r) {
    return sum[r] - sum[l-1];
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    
    cin >> t;
    while(t--) {
        memset(f, 0, sizeof(f));
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        if(n <= 2000) {
            for(int x = 1; x < n; x++) {
                for(int y = 0; y < x; y++) {
                    //same
                    f[x+1][y] = max(f[x+1][y], f[x][y] + (a[x+1]==a[x] ? a[x+1] : 0));
                    //diff
                    f[x+1][x] = max(f[x+1][x], f[x][y] + (a[x+1]==a[y] ? a[x+1] : 0));
                }
            }
            int ans = 0;
            for(int y = 0; y < n; y++) ans = max(ans, f[n][y]);
            cout << ans << endl;
        }
        else {
            sum[0] = sum[1] = 0;
            for(int i = 2; i <= n; i++) {
                sum[i] = sum[i-1];
                if(a[i] == a[i-1]) sum[i] += a[i];
            }
            ff[1] = 0;
            gg[1] = 0;
            for(int x = 2; x <= n; x++) {
                gg[x] = max(gg[x-1], ff[x-2] + calc(x-1, x-1));
                ff[x] = max(gg[x], ff[x-1] + (a[x] == a[x-2] ? a[x] : 0));
            }
            long long ans = ff[n];
            for(int i = 1; i < n; i++) {
                ans = max(ans, ff[i] + calc(i + 1, n));
            }
            cout << ans << endl;
        }
    }
    return 0;
}

/*

f[x][y] 
*/