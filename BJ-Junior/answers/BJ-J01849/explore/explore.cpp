#include<bits/stdc++.h>

using namespace std;

bool flag[1007][1007];
int n, m, k, t, x, y, d;
char a[1007][1007];

int dx[4] = {0, 1,  0, -1};
int dy[4] = {1, 0, -1,  0};

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        memset(flag, false, sizeof(flag));
        int cnt = 1;
        flag[x][y] = true;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> a[i][j];
        while(k--){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx > n || nx < 1 || ny > m || ny < 1 || a[nx][ny] == 'x'){
                d++;
                d%=4;
            }
            else{
                x = nx;
                y = ny;
                if(!flag[x][y]) cnt++, flag[x][y] = true;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
