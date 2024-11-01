#include <bits/stdc++.h>
#define int long long
bool vis[10][1005];
using namespace std;
signed main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        char x, y;
        cin >> x >> y;
        int nx;
        if(x == 'D') nx = 1;
        if(x == 'C') nx = 2;
        if(x == 'H') nx = 3;
        if(x == 'S') nx = 4;
        int ny;
        if(y == 'A') ny = 1;
        else if(y == 'T') ny = 10;
        else if(y == 'J') ny = 11;
        else if(y == 'Q') ny = 12;
        else if(y == 'K') ny = 13;
        else ny = y - '0';
        vis[nx][ny] = true;
    }
    int ans = 52;
    int cnt = 0;
    for(int i = 1;i <= 4;i++){
        for(int j = 1;j <= 20;j++){
            if(vis[i][j]) cnt++;
        }
    }
    ans -= cnt;
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
