#include <bits/stdc++.h>
using namespace std;
int xyf[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int sx,sy,d;
int T;
int ansn;
int m,n,k;
char aw[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--){
        ansn = 1;
        cin >> n >> m >> k;
        cin >> sx >> sy >> d;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin >> aw[i][j];
            }
        }
        while(k--){
            int nx = sx + xyf[d%4][0];
            int ny = sy + xyf[d%4][1];
            ansn++;
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && aw[nx][ny]=='.'){

                aw[sx][sy] = '1';
                sx = nx;
                sy = ny;
            }else if(aw[sx][sy]=='1'){
                aw[sx][sy] = '1';
                sx = nx;
                sy = ny;
                ansn--;
            }else{
                d++;
                ansn--;
            }
        }
        cout << ansn << endl;
    }
    return 0;
}