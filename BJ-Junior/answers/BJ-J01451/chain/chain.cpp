#include <bits/stdc++.h>
using namespace std;
int T,n,r[100005],c[100005];
long long li[200005],a[200005][200005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> T;
    int n, k, q;
    for (int p = 1;p <= T;p++){
        cin >> n >> k >> q;
        for (int i = 1;i <= n;i++){
            cin >> li[i];
            for (int l = 1;l <= li[i];l++) cin >> a[li[i]][l];
        }
        for (int j = 1;j <= q;j++){
            cin >> r[j] >> c[j];
        }
        for (int j = 1;j <= q;j++){
            int ans = r[j] * 3 + c[j] * 2;
            bool righta = (ans % 2 == 1);
            bool rightb = (T % 2 == 0);
            if ((righta && rightb) || (!righta && !rightb)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}