#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
char b[1010][1010];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n, m, k, t, x, y, d, cnt;
    cin>>t;
    while(t--){
        cnt = 1;
        memset(a,0,sizeof(a));
        cin>>n>>m>>k>>x>>y>>d;
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=m;j++){
                cin>>b[i][j];
            }
        }
        a[x][y] = 1;
        while(k--){
            int xx = x+dir[d][0], yy = y+dir[d][1];
            if (xx>0&&xx<=n&&yy>0&&yy<=m&&b[xx][yy]=='.'){
                x = xx;
                y = yy;
                if (a[x][y]==0) cnt++;
                a[x][y] = 1;
            }else d = (d+1)%4;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
