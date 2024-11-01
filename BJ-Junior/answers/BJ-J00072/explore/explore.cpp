#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n, m, k, T, sum = 1;
bool vis[maxn][maxn];
char a[maxn][maxn];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin>>T;
    while(T--){
        int x, y, d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        int newx, newy;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin>>a[i][j];
                vis[i][j] = 0;
            }
        }
        for(int i = 1; i <= k; i++){
                vis[x][y] = 1;
                if(d == 0){
                    newx = x;
                    newy = y + 1;
                }
                if(d == 1){
                    newx = x + 1;
                    newy = y;
                }
                if(d == 2){
                    newx = x;
                    newy = y - 1;
                }
                if(d == 3){
                    newx = x - 1;
                    newy = y;
                }
                if((newx >= 1 && newx <= n) && (newy >= 1 && newy <= m) && a[newx][newy] == '.' ){
                    if(vis[newx][newy] != 1){
                        sum++;
                    }
                    x = newx;
                    y = newy;
                }else{
                    d = (d + 1) % 4;

                }
        }
        cout<<sum<<endl;
        sum = 1;
    }
    return 0;
}
