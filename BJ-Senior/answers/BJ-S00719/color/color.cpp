#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll t, n;
ll a[100010];
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    while(t --){
        ll ans = 0;
        cin >> n;
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        for(int i = 1;i < n;i ++){
            if(a[i] == a[i + 1]){
                ans += a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
