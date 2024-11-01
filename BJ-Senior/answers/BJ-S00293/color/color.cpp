#include <iostream>
using namespace std;
int t, n, a[200005], cnt[1000005], flag;
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= 1000005; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        for (int i = 1; i <= 1000005; i++) if (cnt[i] > 1) flag = 1;
        if (!flag) cout << 0 << "\n";
    }
    return 0;
}