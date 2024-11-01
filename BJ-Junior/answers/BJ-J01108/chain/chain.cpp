#include <iostream>
using namespace std;

const int maxn = 100005;

int T, n, k, q, arr[maxn], len[maxn];

void solve(){
    int tp[10005];
    cin >> n >> k >> q;
    int s = 0;
    for (int i = 1; i <= n; i++){
        cin >> len[i];
        for (int j = 1; j <= len[i]; j++){
            cin >> arr[s+j];
            if (!tp[arr[s+j]]){
                tp[arr[s+j]] = j;
            }
        }
        s += len[i];
    }
    for (int i = 1; i <= q; i++){
        int r, c;
        cin >> r >> c;
        if (!tp[c]) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
    return;
}

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
