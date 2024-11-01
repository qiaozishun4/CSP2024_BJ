#include<bits/stdc++.h>
using namespace std;
int t,bhx[4]={0,1,0,-1},bhy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    for(cin>>t;t;t--){
        int n=0,m=0,k=0,d=0,x=0,y=0,ans=0,vis[1005][1005]={};
        char a[1005][1005];
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
        for(int i=1;i<=k;i++){
            x=x+bhx[d];
            y=y+bhy[d];
            if(x>=1&&y>=1&&x<=n&&y<=m&&a[x][y]=='.'){
                if(!vis[x][y]){
                    ans++;
                    vis[x][y]=1;
                }
            }
            else{
                x=x-bhx[d];
                y=y-bhy[d];
                d=(d+1)%4;
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
