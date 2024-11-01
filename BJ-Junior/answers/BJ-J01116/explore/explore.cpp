#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct Node{
    int x,y,d;
}s;
int n,m,k;
char c[N][N];
bool f[N][N];
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
void DFS(int x,int y,int d,int cnt){
    f[x][y]=true;
    if (cnt==k) return ;
    int nx=x+dx[d],ny=y+dy[d],nd=d;
    if (nx<1 || ny<1 || nx>n || ny>m || c[nx][ny]!='.'){
        nd=(d+1)%4;
        DFS(x,y,nd,cnt+1);
    }
    else{
        DFS(nx,ny,d,cnt+1);
    }
}
void MAIN(){
    memset(f,false,sizeof f);
    cin>>n>>m>>k;
    cin>>s.x>>s.y>>s.d;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>c[i][j];
        }
    }
    DFS(s.x,s.y,s.d,0);
    int ans=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ans+=f[i][j];
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--) MAIN();
    return 0;
}
