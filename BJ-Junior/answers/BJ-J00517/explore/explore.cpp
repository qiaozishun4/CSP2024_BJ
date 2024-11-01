#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,d,cnt = 0;
int dx[5] = {0,1,0,-1},dy[5] = {1,0,-1,0};
char a[1010][1010];
int b[1010][1010];
void dfs(int sx,int sy,int nd,int tk){
    if(tk == 0){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(b[i][j] == 1) cnt++;
            }
        }
        cout << cnt << endl;
        cnt = 0;
    }
    int nx = sx + dx[nd-1];
    int ny = sy + dy[nd-1];
    if(nx >= 1 && nx <= n && ny >= 1 && ny <= m){
        if(a[nx][ny] == '.'){
            b[nx][ny] = 1;
            dfs(nx,ny,nd,tk-1);
        }
    }else{
        dfs(sx,sy,(nd+1)%4,tk-1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    for(int i = 1;i <= T;i++){
            b[x][y] = 1;
        cin >> n >> m >> k >> x >> y >> d;
        for(int j = 1;j <= n;j++){
            for(int z = 1;z <= m;z++){
                cin >> a[j][z];
            }
        }
        dfs(x,y,d,k);
        for(int j = 1;j <= 1005;j++){
            for(int z = 1;z <= 1005;z++){
                a[j][z] = ' ';
                b[j][z] = 0;
            }
        }
    }
    return 0;
}