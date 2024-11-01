#include<bits/stdc++.h>
using namespace std;
long long dp[100005] = {-1, -1, 1, 7, 4, 3, 6, 8};
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        if(n < 2){
            cout << -1 << endl;
            continue;
        }
        if(n % 7 == 0){
            for(int i = 1; i <= n / 7; i++){
                cout << 8;
            }
            cout << endl;
            continue;
        }else if(n % 7 == 1){
            cout << 1;
            for(int i = 1; i <= n / 7; i++){
                cout << 8;
            }
            cout << endl;
            continue;
        }else{


            for(int i = 8; i <= n; i++){
                dp[i] = 9e18;
                for(int j = 2; j<= i / 2 + i % 2; j++){
                    int x = 0, y = 0, z = j;
                    while(z > 0){
                        z /= 10;
                        x++;
                    }
                    z = i - j;
                    while(z > 0){
                        z/= 10;
                        y++;
                    }

                    dp[i] = min(dp[i], (long long)min(dp[j] * pow(10, y) + dp[i - j], dp[i - j] * pow(10, x) + dp[j]));
                }
                
            }
            cout << dp[n] << endl;
        }
    }
    return 0;
}
