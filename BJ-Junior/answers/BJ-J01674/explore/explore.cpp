#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
}d[10];
int n,m,ans;
int s[1005][1005];
int vis[1005][1005];
/*void check(int x,int y,int flag,int now){
    cout << x << " " << y << " " << flag << " " << now << endl;
    if(!vis[x][y]){
        ans++;
        vis[x][y] = 1;
    }
    if(now <= 0) return;
    int dx = x + d[flag].x,dy = y + d[flag].y;
    if(dx > n || dx < 1 || dy > m || dy < 1 || s[dx][dy]){
        flag = (flag + 1) % 4;
        check(x,y,flag,now - 1);
    }
    else{
        check(dx,dy,flag,now - 1);
    }
}*/
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    d[0].x = 0;
    d[0].y = 1;
    d[1].x = 1;
    d[1].y = 0;
    d[2].x = 0;
    d[2].y = -1;
    d[3].x = -1;
    d[3].y = 0;
    int t;
    cin >> t;
    while(t--){
        int k,x,y,flag;
        cin >> n >> m >> k >> x >> y >> flag;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                char a;
                cin >> a;
                if(a == '.') s[i][j] = 0;
                else s[i][j] = 1;
                vis[i][j] = 0;
            }
        }
        ans = 0;
        //check(x,y,flag,k);
        k++;
        while(k--){
            //cout << x << " " << y << " " << flag << " " << k << endl;
            if(!vis[x][y]){
                ans++;
                vis[x][y] = 1;
            }
            int dx = x + d[flag].x,dy = y + d[flag].y;
            if(dx > n || dx < 1 || dy > m || dy < 1 || s[dx][dy]){
                flag = (flag + 1) % 4;
            }
            else{
                x = dx;
                y = dy;
            }
        }
        cout << ans << endl;
        /*for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cout << vis[i][j] << " ";
            }
            cout << endl;
        }*/
    }
    return 0;
}
