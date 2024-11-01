#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int N = 1e5 + 5;
//                 0  1  2  3  4  5  6  7  8  9
const int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n;
namespace Sub1 {
    int cal(lint k) {
        int r = 0;
        while(k) r += a[k % 10], k /= 10;
        return r;
    }
    void solve() {
        cin>>n;
        lint v = 1;
        for(lint i = 1; i <= n / 7 + 2; i++) v *= 10;
        for(lint i = 1; i <= v; i++) if(cal(i) == n) return cout<<i<<endl, void();
        cout<<-1<<endl;
    }
}
namespace Sub2 {
    //                 7   8   9  10  11  12  13
    const int p1[7] = {8, 10, 18, 22, 20, 28, 68};
    //                 14   15   16   17   18   19   20
    const int p2[7] = {88, 108, 188, 200, 208, 288, 688};
    void solve() {
        cin>>n;
        if(n >= 14) {
            cout<<p2[n % 7]; for(int i = 1; i < n / 7 - 1; i++) cout<<8; cout<<endl;
        } else if(n >= 7) cout<<p1[n - 7]<<endl;
        else {
            for(int i = 1; i <= 9; i++) if(a[i] == n) 
                return cout<<i<<endl, void();
            return cout<<-1<<endl, void();
        }
    }
}
signed main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) Sub2::solve();
    return 0;
}