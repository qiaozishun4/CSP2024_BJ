#include<bits/stdc++.h>
using namespace std;
int t, n, tmp1, tmp2, a[10] = {0, 10, 18, 23, 20, 28, 68};
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin >> t;
    for(int i = 1;i <= t;i++){
        cin >> n;
        if(n == 1) cout << -1 << '\n';
        else if(n == 2) cout << 1 << '\n';
        else if(n == 3) cout << 7 << '\n';
        else if(n == 4) cout << 4 << '\n';
        else if(n == 5) cout << 2 << '\n';
        else if(n == 6) cout << 6 << '\n';
        else if(n == 7) cout << 8 << '\n';
        else if(n == 8) cout << 10 << '\n';
        else if(n == 9) cout << 18 << '\n';
        else if(n == 10) cout << 23 << '\n';
        else if(n == 11) cout << 20 << '\n';
        else if(n == 12) cout << 28 << '\n';
        else if(n == 13) cout << 68 << '\n';
        else if(n == 14) cout << 88 << '\n';
        else{
            tmp1 = n / 7, tmp2 = n % 7;
            if(tmp2 == 0){
                for(int i = 1;i <= tmp1;i++){
                    cout << 8;
                }
                cout << '\n';
            }else{
                cout << a[tmp2];
                for(int i = 1;i < tmp1;i++){
                    cout << 8;
                }
                cout << '\n';
            }
        }
    }
    return 0;
}