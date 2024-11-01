#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int N = 1e5 + 5, M = 14 + 5;
lint n, m, b[N], c[N], K, x[4], ans, res, lg[N]; char d[M][N];
vector<int> v1, v2;
void run(int k) {
    // cout<<"inner"<<endl;
    // assert(k < N);
    for(int i = 1; i <= lg[k]; i++) {
        v2.clear();
        for(int j = 1; j <= v1.size() / 2; j++) {
            // assert((j - 1) * 2 + 1 < v1.size());
            int x1 = v1[(j - 1) * 2], x2 = v1[(j - 1) * 2 + 1];
            if(d[i][j] == '0') {
                if(x1 > i) v2.push_back(x1);
                else v2.push_back(x2);
            } else {
                if(x2 > i) v2.push_back(x2);
                else v2.push_back(x1);
            }
        }
        v1 = v2;
    }
    // cout<<"done"<<endl;
    // assert(v1.size());
    ans = v1[0];
}
void solve() {
    v1.clear(), res = 0;
    for(int i = 0; i < 4; i++) cin>>x[i];
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= c[i]; j++) v1.push_back(b[j] ^ x[j % 4]);
        run(c[i]), res ^= i * ans;
    }
    cout<<res<<endl;
}  
int work(int q = n) {
    int r = 1;
    while(q) q /= 2, r *= 2;
    return r;
}
signed main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    // cout<<"qwq"<<endl;
    for(int i = 1; i <= n; i++) cin>>b[i];
    for(int i = 1; i <= m; i++) cin>>c[i];
    // cout<<"qwq"<<endl;
    K = work();
    lg[1] = 0; for(int i = 2; i <= K; i++) lg[i] = lg[i / 2] + 1;
    for(int i = 1, G = K / 2; i <= lg[K]; i++, G /= 2) for(int j = 1; j <= G; j++) cin>>d[i][j];
    // cout<<"qwq"<<endl;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}