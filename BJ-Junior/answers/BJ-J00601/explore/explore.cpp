#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 +5;
int T,n,m,k,d,x00,y00;
int mymap[N][N];
bool vis[N][N];
bool check(int x,int y){
    if(x < 1 || x > n || y < 1 || y > m) return false;
    if(mymap[x][y]) return true;
    else return false;
}
int dfs(int x,int y,int s,int cnt,int ans){ // x,y表示当前坐标, s表示当前方向， cnt表示当前操作次数,ans记录走过格子个数
    if(!vis[x][y]){
        vis[x][y] = 1;
        ans ++;
    }
    if(cnt == k) return ans;
    if(s == 0){
        if(check(x,y+1)) dfs(x,y+1,s,cnt + 1,ans);
        else{
            s = 1;
            dfs(x,y,s,cnt + 1,ans);
        }
    }
    else if(s == 1){
        if(check(x+1,y)) dfs(x+1,y,s,cnt + 1,ans);
        else{
            s = 2;
            dfs(x,y,s,cnt+1,ans);
        }
    }
    else if(s == 2){
        if(check(x,y-1)) dfs(x,y-1,s,cnt+1,ans);
        else{
            s = 3;
            dfs(x,y,s,cnt+1,ans);
        }
    }

    else if(s == 3){
        if(check(x-1,y)) dfs(x-1,y,s,cnt+1,ans);
        else{
            s = 0;
            dfs(x,y,s,cnt+1,ans);
        }
    }
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T --){
        memset(vis,0,sizeof(vis));
        cin >> n >> m >> k;
        //cout << n << m << k << endl;
        cin >> x00 >> y00 >> d;
        for(int i = 1; i <= n; i ++)
            for(int j = 1;j <= m;j ++){
                char x;
                cin >>x;
                if(x == '.') mymap[i][j] = 1;
                else mymap[i][j] = 0;
            }
        cout << dfs(x00,y00,d,0,0) << endl;
    }
    return 0;
}
