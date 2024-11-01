#include <bits/stdc++.h>
using namespace std;
const int N=2000;
int T,n,m,k,x0,y,d0;
char s[N][N];
int vis[N][N];
void init(int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s[i][j]='k';
        }
    }
}
int dfs(int x0,int y0,int k,int d,int ans){
    if(k==0) return ans;
    if(d==0){
        if(s[x0][y0+1]=='.'){
            ans++;
            dfs(x0,y0+1,k-1,d,ans);
        }
        if(s[x0][y0+1]=='k' || s[x0][y0+1]=='x'){
            d=1;
        }
    }
    if(d==1){
        if(s[x0+1][y0]=='.'){
            if(!vis[x0+1][y0]){
                ans++;
                vis[x0+1][y0]=1;
                dfs(x0+1,y0,k-1,d,ans);
            }
        }
        if(s[x0+1][y0]=='k'|| s[x0+1][y0]=='x'){
            d=2;
        }
    }
    if(d==2){
        if(s[x0][y0-1]=='.'){
            if(!vis[x0][y0-1]){
                ans++;
                vis[x0][y0-1]=1;
                dfs(x0,y0-1,k-1,d,ans);
            }
        }
        if(s[x0][y0-1]=='k' || s[x0][y0-1]=='x'){
            d=3;
        }
    }
    if(d==3){
        if(s[x0-1][y0]=='.'){
            if(!vis[x0-1][y0]){
                ans++;
                vis[x0-1][y0]=1;
                dfs(x0-1,y0,k-1,d,ans);
            }
        }
        if(s[x0-1][y0]=='k' || s[x0-1][y0]=='x'){
            d=0;
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x0>>y>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s[i][j];
            }
        }
        int ans=dfs(x0,y,k,d0,1);
        cout<<ans<<endl;
        init(n,m);
    }
    return 0;
}
