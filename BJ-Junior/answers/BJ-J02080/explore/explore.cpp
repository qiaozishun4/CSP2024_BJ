#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
int vis[1005][1005];
struct node{
    int x, y, d;
};
void bfs(int stx, int sty, int ssd, int n, int m, int k){
    queue<node> q;
    int cnt = 1, slo = 0;
    q.push({stx, sty, ssd});
    while(!q.empty()){
        node now = q.front();
        q.pop();
        if(slo == k){
            cout << cnt << endl;
            return;
        }
        int nx = now.x, ny = now.y;
        if(now.d == 0) ny++;
        else if(now.d == 1) nx++;
        else if(now.d == 2) ny--;
        else nx--;
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&vis[nx][ny]==0){
            q.push({nx, ny, now.d});
            cnt++;
        }else{
            q.push({now.x, now.y, (now.d+1)%4});
        }
        slo++;
    }
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++){
        int n, m, k;
        cin >> n >> m >> k;
        int sx, sy, sd;
        cin >> sx >> sy >> sd;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> s[i][j];
                if(s[i][j]=='x') vis[i][j] = 1;
            }
        }
        bfs(sx, sy, sd, n, m, k);
    }
    return 0;
}
