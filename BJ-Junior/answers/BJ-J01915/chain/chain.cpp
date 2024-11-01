#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n, k, q;
        cin >> n >> k >> q;
        int l;
        cin >> l;
        int data[2005];
        for(int i = 0;i < l;i++) cin >> data[i];
        for(int i = 1;i < n;i++){
            int tm;
            cin >> tm;
            int s;
            for(int i = 0;i < tm;i++) cin >> s;
        }
        while(q--){
            int r, c;
            cin >> r >> c;
            int len = 1;
            for(int i = 0;i < l;i++){
                if(data[i] == c) break;
                else len++;
            }
            if(len > k) cout << 0 << endl;
            else cout << 1 << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
