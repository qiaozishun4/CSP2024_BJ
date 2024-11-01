#include <bits/stdc++.h>

using namespace std;
int n,m,T,a[10005][10005];
char p;
int k;
int x,y;
int f;
int dd[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int s;
int main()
{

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n>>m >>k;
        cin >>x >>y >> f;
        s = 1;
        for(int i = 1;i <=n;i++){
            for(int j = 1;j <=m;j++){
                cin >>p;
                if(p == '.') a[i][j] = 0;
                else a[i][j] = 1;
            }
        }
        a[x][y] = -1;
        for(int i = 1;i <=k;i++){
            int x1 = x + dd[f][0],y1 = y + dd[f][1];
            if(a[x1][y1] != 1 and x1 >= 1 and x1 <= n and y1 >= 1 and y1 <= m){
                if(a[x1][y1] == 0) s++;
                a[x1][y1] = -1;
                x = x1;
                y = y1;
            }else{
                f++;
                f = f % 4;
            }
            //cout << x << ' ' << y << endl;
        }
        cout <<s << endl;
    }
    return 0;
}
