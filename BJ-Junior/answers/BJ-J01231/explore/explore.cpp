#include<bits/stdc++.h>
using namespace std;
int T=1;
const int N=1005;
char Map[N][N];
bool vis[N][N];
int ny[4]={1,0,-1,0};
int nx[4]={0,1,0,-1};
int n,m,k;
int ans;
void dfs(int x,int y,int d,int step){
    if(step>k)return ;
    int fx=x+nx[d];
    int fy=y+ny[d];
    if(fx>0&&fx<=n&&fy>0&&fy<=m&&Map[fx][fy]=='.'){
        if(!vis[fx][fy]){
            ans++;
            vis[fx][fy]=1;
        }
        dfs(fx,fy,d,step+1);
        vis[fx][fy]=0;
    }
    else{
        if(!vis[x][y]){
            ans++;
            vis[x][y]=1;
            vis[x][y]=0;
        }
        dfs(x,y,(d+1)%4,step+1);
    }

}
int main(){

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>T;

    while(T--){
        ans=1;
        int x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>Map[i][j];
            }
        }
        vis[x][y]=1;
        dfs(x,y,d,1);

        cout<<ans<<endl;

    }

    fclose(stdin);
    fclose(stdout);
}
