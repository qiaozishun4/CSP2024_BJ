#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define int long long
const int maxn=1010,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int t,n,m,k,stx,sty,sd,vis[maxn][maxn];
string s[maxn];
bool inb(int x,int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}
void dfs(int x,int y,int d,int cnt){
    if(cnt>k)return;
    vis[x][y]=1;
    int nx=x+dx[d],ny=y+dy[d];
    if(inb(nx,ny)&&s[nx][ny]!='x')dfs(nx,ny,d,cnt+1);
    else dfs(x,y,(d+1)%4,cnt+1);
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        memset(vis,0,sizeof(vis));
        cin>>stx>>sty>>sd;
        for(int i=0;i<n;i++){
            s[i]="";
            cin>>s[i];
        }
        dfs(stx-1,sty-1,sd,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)ans+=vis[i][j];
        }
        cout<<ans<<'\n';
    }
}