#include<bits/stdc++.h>
using namespace std;
bool vis[1001][1001],mp[1001][1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n,m;
int ans;

bool check(int x,int y){
    if(x < 1 || x > n || y < 1 || y > m || mp[x][y])
        return false;
    return true;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        memset(vis,false,sizeof(vis));
        memset(mp,false,sizeof(mp));
        ans = 1;
        int k,x,y,d;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        vis[x][y] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char c;
                cin >> c;
                if(c == 'x')
                    mp[i][j] = true;
            }
        }
        while(k--){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(check(nx,ny)){
                x = nx;
                y = ny;
                if(!vis[x][y]){
                    vis[x][y] = true;
                    ans++;
                }
            }else{
                d = (d+1)%4;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
