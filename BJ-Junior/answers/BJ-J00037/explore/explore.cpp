
#include<iostream>
#include <cstring>
using namespace std;
long long ans;
int q,m,n,bu,xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
bool t[1005][1005],vis[1005][1005];
void dfs(int x,int y,int f,int g){
    if(g>bu)return;
    int run=1;
    for(int i=0;i<4;i++){
            if(g>bu)return;
        if(t[x+xx[f]][y+yy[f]] && x+xx[f]<=m && x+xx[f]>=1 && y+yy[f]<=n && y+yy[f]>=1){
            if(!vis[x+xx[f]][y+yy[f]]){
                ans++;
                vis[x+xx[f]][y+yy[f]]=1;
            }
            dfs(x+xx[f],y+yy[f],f,g+1);
            return ;
        }
        f=(f+1)%4;
        g++;
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>q;
    for(int k=0;k<q;k++){
        memset(vis,0,sizeof(vis));
        memset(t,0,sizeof(t));
        ans=0;
        int x0,y0,f0;
        cin>>m>>n>>bu;
        cin>>x0>>y0>>f0;
        vis[x0][y0]=1;
        long long pian=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                char tt;
                cin>>tt;
            if(tt=='.'){
                t[i][j]=1;
            }
            else {
                t[i][j]=0;
                pian++;
            }
        }}
        if(pian==0){
            cout<<bu;
            return 0;
        }
        dfs(x0,y0,f0,1);
        cout<<ans+1<<endl;
    }
    return 0;
}
