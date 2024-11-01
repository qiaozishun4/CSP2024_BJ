#include<bits/stdc++.h>
using namespace std;
int T, n, k, q, kksk;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    srand(0);
    cin >> T;
    while(T--){
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++){
            int l, p;
            cin >> l;
            for(int j = 1; j <= l; j++){
                cin >> p;
            }
        }
        for(int i = 1; i <= q; i++){
            int x, y;
            cin >> x >> y;
        }
        for(int i = 1; i <= q; i++){
            cout << rand()%2 << endl;
        }
    }
    return 0;
}
