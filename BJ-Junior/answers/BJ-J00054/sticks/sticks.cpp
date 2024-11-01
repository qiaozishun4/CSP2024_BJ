#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 100005;
int T, n;
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        if(n == 1){
            cout << "-1\n";
                continue;
        }
        if(n % 7 == 0){
            for(int i = 0, maxx = n / 7; i < maxx; i ++)
                cout << '8';
            cout << '\n';
        }
        if(n % 7 == 1){
            int a = n - 36;
            a = a / 7;
            cout << "8000000";
            for(int i = 1; i < a; i ++)
                cout << '8';
            cout << '\n';
        }
    }
    return 0;
}

