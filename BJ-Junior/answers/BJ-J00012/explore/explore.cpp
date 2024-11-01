#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, M = 1e4 + 5;
char adj[N][M];
bool vis[N][M];
int  n, m, k;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int cnt;

struct Robot{
        int x;
        int y;
        int d;
}r;

int explore(){
        int t = k;
        for(int i = 0; i < k; i++){
                int xx = r.x + dx[r.d];
                int yy = r.y + dy[r.d];
                if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && adj[xx][yy] == '.'){
                        if(vis[xx][yy] == 0){
                                cnt++;
                                vis[xx][yy] = 1;
                        }
                        r.x = xx;
                        r.y = yy;
                }else{
                        r.d = (r.d + 1) % 4;
                }
        }
        return cnt;
}

int main(){
        freopen("explore.in", "w", stdin);
        freopen("explore.out", "r", stdout);
        int t;
        cin >> t;
        while(t--){
                memset(adj, 0, sizeof(adj));
                memset(vis, 0, sizeof(vis));
                cin >> n >> m >> k;
                cin >> r.x >> r.y >> r.d;
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= m; j++){
                                cin >> adj[i][j];
                        }
                }
                cnt = 1;
                cout << explore() << endl;
        }
        fclose(stdin);
        fclose(stdout);
        return 0;
}
