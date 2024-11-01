#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000+10;
const int dx[4]={0,+1,0,-1};
const int dy[4]={+1,0,-1,0};
int T,n,m,k,x,y,d,ans;
bool vis[N][N];
char c[N][N];
string s;
bool isin(int i,int j){
    return 1<=i&&i<=n&&1<=j&&j<=m;
}
void dfs(int x,int y,int d,int dep){
    //cout<<x<<" "<<y<<endl;
    if(dep>k) return ;
    //cout<<x<<" "<<y<<endl;
    while(c[x+dx[d]][y+dy[d]]=='x'||!isin(x+dx[d],y+dy[d])&&dep<=k){
        //cout<<d<<" ";
        d=(d+1)%4,dep++;
    }
    vis[x][y]=1,dfs(x+dx[d],y+dy[d],d,dep+1);
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        scanf("%lld%lld%lld",&x,&y,&d);
        for(int i=1;i<=n;i++){
            /*
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
            */
            cin>>s;
            int len=s.size();
            for(int j=0;j<len;j++) c[i][j+1]=s[j];
        }

        dfs(x,y,d,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j])
                    ans++;
            }
        }
        cout<<ans<<endl;
        ans=0;
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
