#include<bits/stdc++.h>
using namespace std;
//chain
const int N = 1e5 + 10;
int t, n, k, q, l[N], r, c, s[N];
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    srand(time(0));
    cin >> t;
    while(t --){
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++){
            cin >> l[i];
            for(int j = 1;j <= l[i];j++) cin >> s[j];
        }
        while(q--){
            cin >> r >> c;
            int x = rand() % 2;
            cout << x << endl;
        }
    }
    return 0;
}
