#include <iostream>
using namespace std;

int a[1005][1005], l[1005];
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T; cin >> T;
    int n, k, q; cin >> n >> k >> q;
    while (T--){

        for (int i = 1; i <= n; i++){
            cin >> l[i];
            for (int j = 1; j <= l[i]; j++){
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= q; i++){
            int r, c; cin >> r >> c;
            bool f = false;
            int d = 0, t = 0, ans = 0x3f3f3f3f;
            //cout << "--" << endl;
            for (int x = 1; x <= n; x++){
                for (int y = 1; y <= l[x]; y++){
                    if (a[x][y] == 1) d = y;
                    if (a[x][y] == c) t = y;
                    if (d < t && d != 0 && t != 0) ans = min(ans, t-d+1);
                }
                if (!f && ans <= k) {cout << 1 << endl; f = true;}
            }
            if (!f) cout << 0 << endl;
        }
    }
return 0;}
