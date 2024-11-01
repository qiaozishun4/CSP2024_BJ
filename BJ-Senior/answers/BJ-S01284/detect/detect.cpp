#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 11;
int d[MAXN], v[MAXN], a[MAXN];
int p[MAXN];
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            cin >> d[i] >> v[i] >> a[i];
        }
        int maxx = 0;
        for(int i = 1; i <= m; ++i){
            cin >> p[i];
            maxx = max(maxx, p[i]);
        }
        for(int i = 1; i <= n; ++i){
            if(d[i] > maxx){
                continue;
            }
            if(v[i] > V){
                cnt++;
            }
        }
        cout << cnt << " " << (cnt == 0 ? m : m - 1) << endl;
    }
    return 0;
}
