#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,vis[1005][1005],ans;
int fx[10] = {0,1,0,-1};
int fy[10] = {1,0,-1,0};
string s[1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1;i <= n;i++){
            cin >> s[i];
            s[i] = ' ' + s[i];
            for(int j = 1;j <= m;j++){
                vis[i][j] = 0;
            }
        }
        vis[x][y] = 1;
        ans++;
        while(k--){
            int x2 = x + fx[d];
            int y2 = y + fy[d];
            if(x2 < 1 || x2 > n || y2 < 1 || y2 > m || s[x2][y2] == 'x'){
                d = (d + 1) % 4;
            }else{
                x = x2;
                y = y2;
                if(!vis[x][y]){
                    vis[x][y] = 1;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
