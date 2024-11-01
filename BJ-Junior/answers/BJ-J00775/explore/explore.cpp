#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
int t,mp[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--){
        int n,m,k,x,y,d,ans = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        memset(mp,0,sizeof(mp));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                char s;
                cin >> s;
                if(s == 'x') mp[i][j] = 1;
            }
        }
        for(int i = 1;i <= k;i++){
            int nx = x + dx[d],ny = y + dy[d];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= m && mp[nx][ny] == 0){
                x = nx,y = ny;
                ans++;
            }else{
                d = (d + 1) % 4;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

