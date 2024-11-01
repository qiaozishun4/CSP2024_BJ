#include <bits/stdc++.h>
using namespace std;
int a[4][14];
int n,ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    while (n--){
        string c;
        int x,y;
        cin >> c;
        if (c[0] == 'D') x = 0;
        if (c[0] == 'C') x = 1;
        if (c[0] == 'H') x = 2;
        if (c[0] == 'S') x = 3;
        if (c[1] == 'A') y = 1;
        else if (c[1] == 'T') y = 10;
        else if (c[1] == 'J') y = 11;
        else if (c[1] == 'Q') y = 12;
        else if (c[1] == 'K') y = 13;
        else y = c[1] - '0';
        a[x][y]++;
    }
    for (int i = 0;i <= 3;i++){
        for (int j = 1;j <= 13;j++){
            if (a[i][j] == 0) ans++;
        }
    }
    cout << ans;
}
