#include <bits/stdc++.h>

using namespace std;
int a[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, x, n, t[10], in, cnt;
bool fl;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> x;
    while(x--){
        cin >> n;
        for(int i = 1;i <= 100000;i++){
            fl = 0;
            cnt = 0;in = 0;
            for(int j = 1;j <= 100000;j *= 10){
                t[in++] = i / j % 10;
            }

            for(int j = 5;j >= 0;j--){
                if(t[j] != 0){
                    in = j;
                    break;
                }
            }

            for(int j = 0;j <= in;j++){
                cnt += a[t[j]];
            }
            if(cnt == n){
                cout << i << '\n';
                fl = 1;
                break;
            }
        }
        if(fl == 0){
            cout << "-1\n";
        }
    }
    return 0;
}


