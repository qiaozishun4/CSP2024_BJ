#include <bits/stdc++.h>
using namespace std;
int a[200005];
int cnt[1000005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out", "w", stdout);
    int q;
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        for (int i = 0; i <= 1000000; i++){
            cnt[i] = 0;
        }

        for (int i = 0; i < n; i++){
            cin >> a[i];
            cnt[a[i]] ++;
        }
        sort(a,a+n);
        long long ans = 0;
        for (int i = 0; i < n; i++){
            if (a[i] != a[i-1]){
                ans += (cnt[a[i]]-1)*a[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
