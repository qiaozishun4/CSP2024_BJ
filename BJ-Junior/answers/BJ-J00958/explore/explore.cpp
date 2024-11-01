#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char a[1010][1010];
bool v[1010][1010];
long long ans;
int n,m;
void dfs(int x,int y,int k,int d){
    if(k==0)return;
    int nx=x+dx[d];
    int ny=y+dy[d];
    if(nx>n||ny>m||nx<1||ny<1){
        d=(d+1)%4;
        dfs(x,y,k-1,d);
    }else if(a[nx][ny]=='x'){
        d=(d+1)%4;
        dfs(x,y,k-1,d);
    }else{
        if(v[nx][ny]==0){
            ans++;
        }
        v[nx][ny]=1;
        dfs(nx,ny,k-1,d);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        d%=4;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        memset(v,0,sizeof(v));
        v[x][y]=1;
        ans=1;
        dfs(x,y,k,d);
        cout<<ans<<endl;
    }
    return 0;
}

