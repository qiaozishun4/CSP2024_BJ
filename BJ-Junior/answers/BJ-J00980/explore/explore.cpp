#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char s[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        int vis[1005][1005]={0};
        cin>>n>>m>>k>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) cin>>s[i][j];
        long long ans=1;
     //   cout<<x<<" "<<y<<" "<<d<<endl;
        while(k--){
            if(x+dx[d]>0&&x+dx[d]<=n&&y+dy[d]>0&&y+dy[d]<=m&&s[x+dx[d]][y+dy[d]]=='.'){
                x+=dx[d];
                y+=dy[d];
                if(!vis[x][y]) ans++;
                vis[x][y]=1;
            //    cout<<x<<" "<<y<<" "<<d<<endl;
            }else{
                d++;
                if(d>3) d=0;
            //    cout<<x<<" "<<y<<" "<<d<<endl;
            }
        }
     //   cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
