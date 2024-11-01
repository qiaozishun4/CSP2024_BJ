#include<bits/stdc++.h>
using namespace std;
char mp[1010][1010];
int dx[4]{0,1,0,-1};
int dy[4]{1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y;
        int d;
        cin>>x>>y>>d;
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        mp[x][y]='1';
        for(int i=1;i<=k;i++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&mp[nx][ny]!='x'){
                mp[nx][ny]='1';
                x=nx;
                y=ny;
            }
            else{
                d++;
                if(d==4)d=0;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]=='1'){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

