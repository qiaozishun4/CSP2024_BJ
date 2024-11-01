#include<bits/stdc++.h>
using namespace std;

int T;
int n, m, k;
int x, y, d;
string mapp[1005][1005];
int vis[1005][1005];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void explore(){
    int cnt = 1;
    for(int i=1; i<=k; i++){
        int tx = x+dx[d], ty = y+dy[d];
        if(mapp[tx][ty] == "." && (1 <= tx && tx <= n) && (1 <= ty && ty <= m)){
            if(vis[tx][ty] == 0){
                vis[tx][ty] = 1;
                cnt++;
            }
            x= tx, y = ty;
        }
        else{
            d = (d+1)%4;
        }
    }
    cout << cnt <<endl;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> T;

    while(T--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i=1; i<=n; i++){
            string tmp;
            cin >> tmp;
            for(int j=1; j<=m; j++){
                mapp[i][j] = tmp[j-1];
                vis[i][j] = 0;
            }
        }

        vis[x][y] = 1;
        explore();
    }
    return 0;
}
