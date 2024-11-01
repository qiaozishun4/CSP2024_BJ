#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,nowx,nowy,nowd;
char c[1005][1005];
int vis[1005][1005],ans;
void work(int x,int y,int d,int step){
    if(!vis[x][y]){
        ++ans;
        vis[x][y]=1;
    }
    if(step>k){
        cout<<ans<<endl;
        return ;
    }
    int newx=x,newy=y;
    if(d==0) newy++;
    if(d==1) newx++;
    if(d==2) newy--;
    if(d==3) newx--;
    if(newx>=1&&newx<=n&&newy>=1&&newy<=m&&c[newx][newy]=='.') work(newx,newy,d,step+1);
    else work(x,y,(d+1)%4,step+1);

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>nowx>>nowy>>nowd;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cin>>c[i][j];
        work(nowx,nowy,nowd,1);
    }
    return 0;
}
