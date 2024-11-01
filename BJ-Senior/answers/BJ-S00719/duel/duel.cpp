#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll n, ans;
ll a[100010];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    ans = n - 1;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1;i < n;i ++){
        if(a[i] != a[i + 1]){
            ans --;
        }
    }
    cout << ans;
    return 0;
}
