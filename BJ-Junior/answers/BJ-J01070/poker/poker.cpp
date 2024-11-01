#include <bits/stdc++.h>

using namespace std;

bool u[10][55];

int go_int(char x){
    if(x == 'A') return 1;
    if(x == 'T') return 10;
    if(x == 'J') return 11;
    if(x == 'Q') return 12;
    if(x == 'K') return 13;
    return (x - '0');
}

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string a;
        cin >> a;
        int x = go_int(a[1]);
        if(a[0] == 'D'){
            u[1][x] = 1;
        }
        if(a[0] == 'C'){
            u[2][x] = 1;
        }
        if(a[0] == 'H'){
            u[3][x] = 1;
        }
        if(a[0] == 'S'){
            u[4][x] = 1;
        }
    }
    int ans = 0;
    for(int i = 1; i<=4; i++){
        for(int j = 1; j <= 13; j++){
            if(u[i][j]) ans++;
        }
    }
    cout << (52-ans) << endl;
    return 0;
}
