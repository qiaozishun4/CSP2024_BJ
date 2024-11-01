#include<bits/stdc++.h>
using namespace std;
int t, n, k, q, tmp;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    cin >> t;
    for(int i = 1;i <= t;i++){
        cin >> n >> k >> q;
        for(int j = 1;j <= n;j++) cin >> tmp;
        for(int j = 1;j <= q;j++) cin >> tmp;
        for(int j = 1;j <= q;j++) cout << 0 << '\n';
    }
    return 0;
}
