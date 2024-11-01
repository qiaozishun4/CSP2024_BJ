#include <bits/stdc++.h>
using namespace std;
int t, n, k, q, r, c;
int l, s;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++){
            cin >> l;
            for(int j=1;j<=l;j++) cin >> s;
        }
        while(q--){
            cin >> r >> c;
            if(r%2==0 and c%2==0 or r%2==1 and c%2==1){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}
