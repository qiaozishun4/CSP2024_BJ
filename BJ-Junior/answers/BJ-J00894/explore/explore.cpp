#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,p,q,dr,dx[]={0,1,0,-1},dy[]={1,0,-1,0},a[1005][1005],vis[1005][1005][5],ans;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>p>>q>>dr;
        vis[p][q][dr]=1;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++)if(s[j]=='x')a[i][j+1]=1;
        }
        for(int i=1;i<=k;i++){
            int x=p+dx[dr],y=q+dy[dr];
            if(x<=0||x>n||y<=0||y>m||a[x][y]){
                dr=(dr+1)%4;
                continue;
            }
            //cout<<x<<" "<<y<<'\n';
            p=x,q=y;
            if(vis[p][q][dr])break;
            vis[p][q][dr]=1;
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(vis[i][j][0]||vis[i][j][1]||vis[i][j][2]||vis[i][j][3])ans++;
        cout<<ans<<endl;
    }
    return 0;
}