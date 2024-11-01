#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char mp[1010][1010];
int vmp[1010][1010];
bool inmap(int x,int y){
    return x>0&&y>0&&x<=n&&y<=m;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){
        int x,y,d,ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        memset(vmp,0,sizeof(vmp));
        vmp[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>mp[i][j];
        }
        for(int i=1;i<=k;i++){
            int xx=x+dx[d],yy=y+dy[d];
            if(inmap(xx,yy)&&mp[xx][yy]!='x'){
                x=xx;y=yy;
                vmp[x][y]=1;
            }
            else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)ans+=vmp[i][j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
