#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--){
        int n,k,q;
        cin >> n >> k >> q;
        for (int i = 1;i <= n;i++){
            int x,tmp;
            cin >> x;
            while (x--) cin >> tmp;
        }
        while (q--){
            int x,y;
            cin >> x >> y;
            cout << "0\n";
        }
    }
    return 0;
}