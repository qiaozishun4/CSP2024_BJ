#include <iostream>
#include <cstring>
using namespace std;
#define ll unsigned long long
ll T;
ll n;
ll a[15] = {0,2,3,4,5,6,7};
ll b[15] = {0,1,7,4,2,6,8};
ll dp[15][100010];
ll num[15][100010];
ll pin(ll x,ll y)
{
    ll tmp = y;
    while(y){
        y /= 10;
        x *= 10;
    }
    return x + tmp;
}
ll s[100010];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    while(T --){
        memset(num,0x3f,sizeof(num));
        cin >> n;
        for(ll i = 1;i <= 6;i ++){
            for(ll j = 0;j <= n;j ++){
                dp[i][j] = dp[i - 1][j];
                num[i][j] = num[i - 1][j];
                if(j == a[i]){
                    dp[i][j] ++;
                    num[i][j] = b[i];
                }
                if(j >= a[i]){
                    for(ll k = 1;k <= j / 2;k ++){
                        if(dp[i][k] == 0 || dp[i][j - k] == 0){
                            continue;
                        }
                        dp[i][j] += dp[i][k] + dp[i][j - k];
                        dp[i][j] %= 1000007;
                        num[i][j] = min(num[i][j],min(pin(num[i][k],num[i][j - k]),pin(num[i][j - k],num[i][j - k])));
                    }
                }
            }
        }
        /*
        for(ll i = 1;i <= 6;i ++){
            for(ll j = 1;j <= n;j ++){
                cout << (num[i][j] > 1000 ? 0 : num[i][j]) << ' ';
            }
            cout << endl;
        }
        */
        for(ll i = 1;i <= 6;i ++){
            for(ll j = 1;j <= n;j ++){
                if(num[i][j] > 1e18){
                    num[i][j] = 0;
                }
            }
        }
        ll res = num[6][n];
        ll len = 0;
        while(res){
            len ++;
            s[len] = res % 10;
            res /= 10;
        }
        ll ans = 0;
        bool f = 0;
        for(ll i = len;i >= 1;i --){
            if(s[i] != 6){
                f = 1;
            }
            if(f && s[i] == 6){
                ans *= 10;
                ans += 0;
            }
            else{
                ans *= 10;
                ans += s[i];
            }
        }
        if(ans == 0){
            cout << -1 << endl;
        }
        else{
            cout << ans << endl;
        }
    }
    return 0;
}
