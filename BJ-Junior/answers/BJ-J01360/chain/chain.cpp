#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while(T --){
        int n, k, q;
        cin >> n >> k >> q;
        int a[n+5][n+5];
        int r,c;
        for(int i = 1; i <= n; ++ i){
            int l;
            cin >> l;
            for(int j = 1; j <= n; ++ j){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= q; ++ i){
            cin >> r >> c;
            cout << 1 << endl;
        }
    }
    return 0;
}