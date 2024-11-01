#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,cnt,ans;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char mp[10000][10000];
void dfs(int x,int y,int d){
    cnt++;
    if(cnt>=k){
        cout << ans << endl;
        return ;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=n&&ny>0&&ny<=m&&mp[nx][ny]=='.'){
            ans++;
            dfs(nx,ny,d);
            return ;
        }
        else{
            d=(d+1)%4;
            dfs(x,y,d);
            return ;
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
                cin >> mp[j][k];
        dfs(x,y,d);
        memset(mp,0,sizeof(mp));
    }
    return 0;
}
