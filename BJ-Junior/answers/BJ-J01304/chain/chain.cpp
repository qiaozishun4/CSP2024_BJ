#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
int a[200005], maxn = -1;
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        int n, k, q; cin >> n >> k >> q;
        for(int i = 1; i <= n; i++){
            int l; cin >> l;
            for(int j = 1; j <= l; j++){
                int x; cin >> x;
                v[i].push_back(x);
                a[i] = max(a[i], x);
                maxn = max(x, maxn);
            }
        }
        while(q--){
            int r, c; cin >> r >> c;
            if(maxn < c || r > 4) cout << 0 << endl;
            else cout << 1 << endl;
        }
    }

    return 0;
}
