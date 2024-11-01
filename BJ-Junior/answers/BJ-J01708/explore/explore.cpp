#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,cnt;
int dir[6][4]={{0,1},{1,0},{0,-1},{-1,0}};
char mapp[1005][1005];
int vis[1005][1005];
void dfs(int nn,int mm,int d,int kk){
    if(kk==0){
        cout<<cnt<<endl;
        return ;
    }
    int xx=nn+dir[d][0];
    int yy=mm+dir[d][1];
    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mapp[xx][yy]=='.'){
        if(vis[xx][yy]==0){
            cnt++;
            vis[xx][yy]=1;
        }
        dfs(xx,yy,d,kk-1);
    }
    else{
        d=(d+1)%4;
        dfs(nn,mm,d,kk-1);
    }

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    int sn,sm,sd;
    while(t--){
        cin>>n>>m>>k;
        cin>>sn>>sm>>sd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mapp[i][j];
            }
        }
        if(k==1){
            int snn,smm;
            snn=sn+dir[sd][0];
            smm=sm+dir[sd][1];
            if(snn<=n&&snn>=1&&smm<=m&&smm>=1&&mapp[snn][smm]=='.'){
                cout<<2<<endl;
                continue;
            }
            else{
                cout<<1<<endl;
                continue;
            }
        }
        else{
            cnt=1;
            vis[sn][sm]=1;
            dfs(sn,sm,sd,k);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
    }
    return 0;
}
