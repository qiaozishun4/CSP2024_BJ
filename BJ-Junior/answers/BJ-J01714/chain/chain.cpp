#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
bool c[N];
int a[N];
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        int n, k, q;
        cin >> n >> k >> q;
        memset(c, 0, sizeof (c));
        for (int i = 1;i <= n;i++){
            int l;
            cin >> l;
            for (int j = 1;j <= l;j++){
                cin >> a[j];
            }
            for (int j = 1;j <= l;j++){
                if (a[j] == 1){
                    for (int m = j + 1;m <= min(j + k - 1, l);m++){
                        c[a[m]] = 1;
                    }
                }
            }
        }
        while (q--){
            int r, d;
            cin >> r >> d;
            cout << c[d] << "\n";
        }
    }
    return 0;
}
