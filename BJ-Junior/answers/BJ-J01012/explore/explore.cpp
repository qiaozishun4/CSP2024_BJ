#include<bits/stdc++.h>
using namespace std;
char ma[1010][1010];
bool vis[1010][1010];
int n,m,k;
int x,y,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>ma[i][j];
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            if(d==0){
                y++;
                if(x<=n&&x>=1&&y<=m&&y>=1&&ma[x][y]=='.')vis[x][y]=1;
                else d=(d+1)%4,y--;
            }else if(d==1){
                x++;
                if(x<=n&&x>=1&&y<=m&&y>=1&&ma[x][y]=='.')vis[x][y]=1;
                else d=(d+1)%4,x--;
            }else if(d==2){
                y--;
                if(x<=n&&x>=1&&y<=m&&y>=1&&ma[x][y]=='.')vis[x][y]=1;
                else d=(d+1)%4,y++;
            }else if(d==3){
                x--;
                if(x<=n&&x>=1&&y<=m&&y>=1&&ma[x][y]=='.')vis[x][y]=1;
                else d=(d+1)%4,x++;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(vis[i][j])ans++;
        cout<<ans<<endl;
    }
    return 0;
}
