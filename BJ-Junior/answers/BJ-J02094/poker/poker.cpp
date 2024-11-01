#include<bits/stdc++.h>
using namespace std;
int a[5][20];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        char c, b; cin >> c >> b;
        if(c == 'D'){
            if(b == 'A') a[1][1]++;
            else if(b == 'T') a[1][10]++;
            else if(b == 'J') a[1][11]++;
            else if(b == 'Q') a[1][12]++;
            else if(b == 'K') a[1][13]++;
        else{
                a[1][b - '0']++;
            }
        }
        if(c == 'C'){
            if(b == 'A') a[2][1]++;
            else if(b == 'T') a[2][10]++;
            else if(b == 'J') a[2][11]++;
            else if(b == 'Q') a[2][12]++;
            else if(b == 'K') a[2][13]++;
            else{
                a[2][b - '0']++;
            }
        }
        if(c == 'H'){
            if(b == 'A') a[3][1]++;
            else if(b == 'T') a[3][10]++;
            else if(b == 'J') a[3][11]++;
            else if(b == 'Q') a[3][12]++;
            else if(b == 'K') a[3][13]++;
            else{
                a[3][b - '0']++;
            }
        }
        if(c == 'S'){
            if(b == 'A') a[4][1]++;
            else if(b == 'T') a[4][10]++;
            else if(b == 'J') a[4][11]++;
            else if(b == 'Q') a[4][12]++;
            else if(b == 'K') a[4][13]++;
            else{
                a[4][b - '0']++;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 13; j++){
            if(a[i][j] == 0) ans++;
        }
    }
    cout << ans;
    return 0;
}
