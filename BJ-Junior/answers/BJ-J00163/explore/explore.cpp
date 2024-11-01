#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
int T,n,m,k,sx,sy,sd,cnt;
char c[N][N];
bool vis[N][N];
string tmp;
bool Check(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m && c[x][y] == '.';
}
void dfs(int x, int y, int d, int i){
    if(i > k){
        for(int k = 1; k <= n; ++k)
            for(int j = 1; j <= m; ++j)
                if(vis[k][j]) ++cnt;
        cout << cnt << endl;
        return;
    }
    vis[x][y] = true;
    int nx = x + dx[d], ny = y + dy[d];
    if(!Check(nx,ny)) dfs(x,y,(d+1)%4,i+1);
    else dfs(nx,ny,d,i+1);
}
void print(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j)
            printf("%c",c[i][j]);
        printf("\n");
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--){
        cnt = 0;
        memset(vis,false,sizeof vis);
        cin >> n >> m >> k;
        cin >> sx >> sy >> sd;
        for(int i = 1; i <= n; ++i){
            cin >> tmp;
            for(int j = 0; j < m; ++j){
                c[i][j+1] = tmp[j];

            }}

        //print();
        dfs(sx,sy,sd,0);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
