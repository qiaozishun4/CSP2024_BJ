#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[1003][1003];
char mp[1003][1003];
int n,m,t;
bool check(int x,int y){
    //if(vis[x][y]) return 0;
    if(mp[x][y]=='x'){
        //cout<<"no way\n";
        return 0;
    }
    if(x<=0||x>n||y<=0||y>m){
        //cout<<x<<' '<<y<<' ';
        //cout<<"out\n";
        return 0;
    }
    return 1;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int q;
    cin>>q;
    while(q--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>t;
        int x,y,cnt,ans=1;
        cin>>x>>y>>cnt;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>mp[i][j];
        while(t--){
            int nx=x+dx[cnt],ny=y+dy[cnt];
            if(check(nx,ny)){
                if(!vis[nx][ny]) ans++;
                x=nx;
                y=ny;
                vis[x][y]=1;
            }
            else {
                cnt++;
                cnt%=4;
            }
            //cout<<x<<' '<<y<<' '<<cnt<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
