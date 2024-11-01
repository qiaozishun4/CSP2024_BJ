#include<bits/stdc++.h>
using namespace std;
int a[1050][1050];
int vis[1050][1050];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        int ans=0;
        int n,m,q;cin>>n>>m>>q;
        int px,py,pd;
        cin>>px>>py>>pd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char x;cin>>x;
                if(x=='x') a[i][j]=1;
            }
        }
        vis[px][py]=1;
        for(int i=1;i<=q;i++){
            int px2=px+dx[pd],py2=py+dy[pd];
            //cout<<px2<<" "<<py2<<endl;
            if(0>=px2||px2>n||0>=py2||py2>m||a[px2][py2]==1){
                pd=(pd+1)%4;continue;
            }else px=px2,py=py2;
            vis[px][py]=1;
            //cout<<pd<<endl;
            //for(int i=1;i<=n;i++){
            //    for(int j=1;j<=m;j++){
            //        cout<<vis[i][j]<<" ";
            //    }
            //    cout<<endl;
            //}cout<<endl;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=vis[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
