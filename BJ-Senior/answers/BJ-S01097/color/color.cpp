#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2e3 + 5;
ll dp[N] , a[N] , b[N] , n;
ll sum(int x , int y){
    return b[y] - b[x - 1];
}
int main(){
    freopen("color.in" , "r" , stdin);
    freopen("color.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int cases;
    cin >> cases;
    while (cases--){
        memset(dp , 0 , sizeof dp);
        cin >> n;
        for (int i = 1;i <= n;i++) cin >> a[i];
        for (int i = 2;i <= n;i++){
            if (a[i] != a[i - 1]) b[i] = b[i - 1];
            else b[i] = b[i - 1] + a[i];
        }
        for (int i = 2;i <= n;i++){
            for (int j = 0;j < i;j++){
                dp[i] = max(dp[i] , dp[j + 1] + sum(j + 2 , i - 1) + (a[j] == a[i] ? a[i] : 0));
            }
        }
        long long ans = 0;
        for (int i = 1;i <= n;i++) ans = max(ans , dp[i] + sum(i + 1 , n));
        cout << ans << '\n';
    }
    return 0;
}