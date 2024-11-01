#include<bits/stdc++.h>
using namespace std;
char a[1201][1201];
bool vis[1201][1201];
int dx[]={0,1,0,-1};
int t,n,m,k,x,y,d;
int dy[]={1,0,-1,0};
int sum=0;
bool check(int x,int y,int k){
    int tx=x+dx[k];
    int ty=y+dy[k];
    if(tx>=1&&tx<=n&&ty>=1&&ty<=m){
        if(a[tx][ty]=='.')
            return 1;
        else
            return 0;
    }else{
        return 0;
    }
}
int bk=0;
void dfs(int x,int y,int d,int k){
    if(d<=0)return;
    while(!check(x,y,k)){
        k=(k+1)%4;
        d--;
    }
    while(check(x,y,k)&&d>0){
        x=x+dx[k];
        y=y+dy[k];
        if(vis[x][y]==0)sum++;
        vis[x][y]=1;
        d--;
    }
    if(sum==bk)return;
    dfs(x,y,d,k);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        sum=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>d;
        bk=n*m;
        cin>>x>>y>>k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]=='X')bk-=1;
            }
        }
        sum=1;
        vis[x][y]=1;
        dfs(x,y,d,k);
        cout<<sum<<endl;
    }
    return 0;
}
