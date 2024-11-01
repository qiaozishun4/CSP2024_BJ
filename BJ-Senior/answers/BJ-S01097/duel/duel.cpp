#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int a[N] , n , m;
int main(){
    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    int x;
    for (int i = 1;i <= n;i++){
        cin >> x;
        m = max(x , m);
        a[x]++;
    }
    int ans = 0 , cnt = 0;
    for (int i = m;i >= 1;i--){
        if (cnt < a[i]){
            ans += a[i] - cnt;
            cnt = a[i];
        }
    }
    cout << ans << '\n';
    return 0;
}