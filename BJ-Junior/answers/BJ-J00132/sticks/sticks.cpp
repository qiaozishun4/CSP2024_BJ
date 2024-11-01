#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long f[maxn], n, ans;
bool flag = 0;
int num[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        if(n % 7 == 0){
            n /= 7;
            for(int i = 1; i <= n; i++) cout << 8;
            cout << '\n';
        }else if((n - 1) % 7 == 0 && n != 1){
            cout << 1;
            n -= 8;
            n /= 7;
            for(int i = 1; i <= n; i++) cout << 8;
            cout << 0 << '\n';
        }else{
            f[1] = -1, f[2] = 1, f[3] = 7, f[4] = 4, f[5] = 2, f[6] = 6;
            f[9] = 18, f[10] = 23, f[11] = 20;
            for(int i = 12; i <= n; i++) f[i] = f[i - 7] * 10 + 8;
            cout << f[n] << '\n';
        }
    }
    return 0;
}