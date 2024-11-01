#include <bits/stdc++.h>
using namespace std;

const int cnt[10] = {6,2,5,5,4,5,6,3,7};

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            cout << "-1\n";
            continue;
        }
        if(n % 7 == 0){
            for(int i = 1;i <= n / 7;i++) cout << 1;
            for(int i = 1;i <= n / 7;i++) cout << 2;
            cout << '\n';
            continue;
        }
        if(n % 7 == 1){
            cout << 10;
            for(int i = 1;i < n / 7;i++) cout << 1;
            for(int i = 1;i < n / 7;i++) cout << 2;
            cout << '\n';
            continue;
        }
        for(long long i = 1;i <= LONG_MAX;i++){
            string s = to_string(i);
            long long ans = 0;
            for(int i = 0;i < s.size();i++) ans += cnt[s[i] ^ 48];
            if(ans == n){
                cout << i << '\n';
                goto end;
            }
        }
        cout << "-1\n";
end:;
    }
    return 0;
}
