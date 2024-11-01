#include<iostream>
using namespace std;
int T;
int n,m,k;
char c[1005][1005];
int vis[1005][1005];
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int ans=0;
void dfs(int x,int y,int d,int deep){
    if(deep==k){
        cout<<ans<<endl;
        return ;
    }
    int xx=x+dirx[d];
    int yy=y+diry[d];

    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&c[xx][yy]=='.'){
//        cout<<xx<<" "<<yy<<" "<<d<<" "<<deep<<" "<<ans<<endl;
//        cout<<"Move"<<endl;
        if(!vis[xx][yy])
            ans++,vis[xx][yy]=1;
        dfs(xx,yy,d,deep+1);
    }else{
//        cout<<"Turn"<<endl;
        dfs(x,y,(d+1)%4,deep+1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int x,y,d0;
        cin>>n>>m>>k;
        cin>>x>>y>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
                vis[i][j]=0;
            }
        }
        ans=0;
        ans++;
        vis[x][y]=1;
        dfs(x,y,d0,0);

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
