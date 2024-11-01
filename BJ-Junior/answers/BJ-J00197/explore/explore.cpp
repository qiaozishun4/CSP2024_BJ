#include<bits/stdc++.h>
using namespace std;
int n,m,k,d,x,y,ans;
char mp[1145][1145];
bool vis[1145][1145];
const int fx[]={0,1,0,-1};
const int fy[]={1,0,-1,0};
void dfs(int x,int y,int d){
    k++;
    while(k--){
        vis[x][y]=true;
        
        int nx=x+fx[d],ny=y+fy[d];
        if(nx<=n&&nx&&ny<=m&&ny&&mp[nx][ny]=='.')x=nx,y=ny;//dfs(x+fx[d],y+fy[d],d,s+1);
        else{
            while(!(nx<=n&&nx&&ny<=m&&ny&&mp[nx][ny]=='.')&&k){
                k--;
                d=(d+1)%4;
                nx=x+fx[d],ny=y+fy[d];
                //printf("(%d,%d,no)->",nx,ny);
           }
        //dfs(x+fx[d],y+fy[d],d,news);
        }
        if(!vis[x][y])ans++;
        //printf("(%d,%d)->",x,y);
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        ans=1;
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               cin >> mp[i][j];
            }
        }
        dfs(x,y,d);
        cout << ans << endl;
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cout << vis[i][j];
            cout << endl;
        }*/
    }
    
    return 0;
}
