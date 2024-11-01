#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
bool vis[N][N],mp[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        int n,m,k,x,y,d,cnt=0;
        cin>>n>>m>>k>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='x') mp[i][j]=1;
            }
        }
        for(int i=1;i<=k;i++){
            int dx=x,dy=y;
            if(d==0) dy=y+1;
            if(d==1) dx=x+1;
            if(d==2) dy=y-1;
            if(d==3) dx=x-1;
            if(1<=dx&&dx<=n&&1<=dy&&dy<=m&&mp[dx][dy]==0){
                x=dx;y=dy;
                vis[x][y]=1;
            }
            else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
