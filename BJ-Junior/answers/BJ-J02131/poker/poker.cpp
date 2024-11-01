#include <bits/stdc++.h>

using namespace std;
string c;
int cnt = 52, n, sum, x, y;
bool a[105][15];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    while(n--){
        cin >> c;
        if(c[0] == 'D'){
            x = 1;
        }
        if(c[0] == 'C'){
            x = 2;
        }
        if(c[0] == 'H'){
            x = 3;
        }
        if(c[0] == 'S'){
            x = 4;
        }
        if(c[1] <= '9' && c[1] >= '2'){
            y = c[1] - '0';
        }
        if(c[1] == 'T'){
            y = 10;
        }
        if(c[1] == 'A'){
            y = 11;
        }
        if(c[1] == 'J'){
            y = 12;
        }
        if(c[1] == 'Q'){
            y = 13;
        }
        if(c[1] == 'K'){
            y = 14;
        }
        a[y][x] = 1;
    }
    for(int i = 1;i <= 4;i++){
        for(int j = 2;j <= 14;j++){
            if(a[j][i] == 1){
                cnt--;
            }
        }
    }
    cout << cnt;
    return 0;
}

