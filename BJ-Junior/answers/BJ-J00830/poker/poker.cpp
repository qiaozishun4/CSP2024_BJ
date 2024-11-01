#include <bits/stdc++.h>
using namespace std;
int a[8][18]/*DCHS*/, n, x, y, cnt;
char lf, rt;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> lf >> rt;
        if(lf == 'D') x = 1;
        else if(lf == 'C') x = 2;
        else if(lf == 'H') x = 3;
        else if(lf == 'S') x = 4;
        if(rt == 'A') y = 1;
        else if(rt == 'T') y = 10;
        else if(rt == 'J') y = 11;
        else if(rt == 'Q') y = 12;
        else if(rt == 'K') y = 13;
        else y = rt - '0';
        a[x][y]++;
    }
    for(int i = 1; i <= 4; i++){
        for(inr j = 1; i <= 13; j++){
            if(a[i][j] == 0) cnt++;
        }
    }
    cout << cnt;
    return 0;
}