#include<bits/stdc++.h>
using namespace std;
int n, a[200001];
namespace Sol1{
    bool color[20];
    inline int calc(){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i - 1; j >= 1; j--){
                if(color[j] == color[i]){
                    if(a[i] == a[j]){
                        cnt += a[i];
                    }
                    break;
                }
            }
        }
        return cnt;
    }
    inline void Solve(){
        int ans = 0;
        for(int i = 0; i < (1<<n); i++){
            memset(color, false, sizeof(color));
            for(int j = 0; j < n; j++){
                if((1<<j) & i){
                    color[j+1] = true;
                }
            }
            ans = max(ans, calc());
        }
        cout << ans << endl;
        return;
    }
}
inline void Solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n <= 15){
        Sol1::Solve();
        return;
    }
    return;
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        Solve();
    }
    return 0;
}