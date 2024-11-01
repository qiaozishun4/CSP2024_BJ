#include<bits/stdc++.h>
using namespace std;
const int N=1e3+15;
long long n,m,k,l,r,d,ans;
char mp[N][N];
long long vis[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long T;
    cin>>T;
    while(T--){
        n=0,m=0,k=0,l=0,r=0,d=0;
        cin>>n>>m>>k>>l>>r>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];

            }
        }
        vis[l][r]=1;
        int x=l,y=r;
        for(int i=1;i<=k;i++){
            long long xx=x,yy=y;
            if(d==0)yy++;
            if(d==1)xx++;
            if(d==2)yy--;
            if(d==3)xx--;
            if(mp[xx][yy]=='.'&&xx>=1&&xx<=n&&yy>=1&&yy<=m){
                vis[xx][yy]=1;
                x=xx,y=yy;
            }
            else {
                d++;
                d%=4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1)ans++;

            }
        }
        cout<<ans<<endl;
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
