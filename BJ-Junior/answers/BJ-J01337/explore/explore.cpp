#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t,n,m,k,x,y,d,ans,fx[10]={0,1,0,-1},fy[10]={1,0,-1,0};
    char sr;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        ans=1;
        bool mp[1050][1050]={},gdd[1050][1050]={};
        gdd[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>sr;
                if(sr=='x'){
                    mp[i][j]=1;
                }
            }
        }
        for(int i=1;i<=k;i++){
            long long xx=x+fx[d],yy=y+fy[d];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mp[xx][yy]==0){
                x=xx;
                y=yy;
                if(!gdd[xx][yy]){
                    gdd[xx][yy]=1;
                    ans++;
                }
            }else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
}
