#include <bits/stdc++.h>
using namespace std;
int n,m,k,xx0,yy0,dd0,t,d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}},ans = 0;
bool mp[1005][1005];
string s[1005];
bool check(int x,int y){
    return x > 0 && x <= n && y > 0 && y <= m && s[x][y] == '.';
}
void dfs(int x,int y,int z,int sum){
    mp[x][y] = 1;
    if (sum == k + 1) return;
    int nx = d[z][0] + x,ny = d[z][1] + y;
    if (check(nx,ny)) dfs(nx,ny,z,sum + 1);
    else dfs(x,y,(z + 1) % 4,sum + 1);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while (t--){
        ans = 0;
        memset(mp,0,sizeof(mp));
        cin >> n >> m >> k;
        cin >> xx0 >> yy0 >> dd0;
        for (int i = 1;i <= n;i++){
            cin >> s[i];
            s[i] = ' ' + s[i];
        }
        dfs(xx0,yy0,dd0,1);
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                ans += mp[i][j];
        cout << ans << endl;
    }
    return 0;
}