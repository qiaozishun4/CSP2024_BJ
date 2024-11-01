#include <bits/stdc++.h>
using namespace std;
int p[100005];
int l[100005], r[100005];
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++){
            int d, v, a;
            cin >> d >> v >> a;
            if(a == 0)
                if(v > V) l[i] = d;
                else l[i] = -1;
            if(a > 0)
                if(v > V) l[i] = d;
                else l[i] = d + (V * V - v * v) / (2 * a) + 1;
        }
        for(int i = 1; i <= m; i++) cin >> p[i];
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(l[i] != -1 && l[i] <= p[m]) cnt++;
        }
        if(cnt == 0) cout << cnt << " " << m << endl;
        else cout << cnt << " " << m-1 << endl;
    }
    return 0;
}
