#include<bits/stdc++.h>
using namespace std;
const int NR = 1e3;
char s[NR + 10][NR + 10];
bool vis[NR + 10][NR + 10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        int x, y, dir;
        scanf("%d%d%d" ,&x, &y, &dir);
        for(int i = 1;i <= n;i++){
            scanf("%s", s[i] + 1);
        }
        for(int i = 0;i <= n + 1;i++){
            for(int j = 0;j <= m + 1;j++){
                vis[i][j] = false;
            }
        }
        vis[x][y] = true;
        while(k--){
            // printf("(%d, %d) dir=%d\n", x, y, dir);
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > m){
                dir++;
                dir %= 4;
                continue;
            }
            if(s[nx][ny] == 'x'){
                dir++;
                dir %= 4;
                continue;
            }
            x = nx;
            y = ny;
            vis[x][y] = true;
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(vis[i][j]) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
/*
cd ~/GJH/explore && g++ explore.cpp && ./a.out


2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/