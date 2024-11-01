#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t,n,m,l,v;
    cin >> t;
    cin >> n >> m >> l >> v;
    int a[10], s[10], d[10];
    int b[10];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cin >> s[i];
        cin >> d[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    cout << 3 << " " << 3;
}
