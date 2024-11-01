#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
int T,n,m,k,x,y,d,ans;
char mp[N][N];
int vis[N][N];
bool ok(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m){
        if(mp[x][y]=='.'){
            if(vis[x][y]==0)
                {ans++;vis[x][y]=1;}
            return true;
        }
    }
    d=(d+1)%4;
    return false;
}
void move_(int x_,int y_){
    if(d==0){if(ok(x_,y_+1)==true)y=y_+1;return;}
    if(d==1){if(ok(x_+1,y_)==true)x=x_+1;return;}
    if(d==2){if(ok(x_,y_-1)==true)y=y_-1;return;}
    if(d==3){if(ok(x_-1,y_)==true)x=x_-1;return;}
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        ans=1;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        for(int i=1;i<N;i++)
            for(int j=1;j<N;j++)
                mp[i][j]=' ';
        cin>>x>>y>>d;
        vis[x][y]=1;
        //cout<<d<<'\n';
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>mp[i][j];
        for(int i=1;i<=k;i++){
            move_(x,y);
            //cout<<i<<" "<<x<<" "<<y<<" "<<d<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}

    return 0;
}
