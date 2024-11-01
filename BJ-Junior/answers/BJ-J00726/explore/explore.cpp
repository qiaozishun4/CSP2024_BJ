#include<bits/stdc++.h>
using namespace std;
int dis[4][2]={0,1 ,1,0,0,-1,-1,0};
char a[1005][1005];

bool vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        long long ans=1;
        int n,m,k;
        cin>>n>>m>>k;
        int sx,sy,d;
        cin>>sx>>sy>>d;
        vis[sx][sy]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k--){
            int nx=sx+dis[d][0];int ny=sy+dis[d][1];
            if(nx>=1&&ny>=1&&nx<=n&&ny<=m&&a[nx][ny]=='.'){
                if(vis[nx][ny]==0){
                    ans++;
                }
                vis[nx][ny]=1;
                //cout<<"x\y:"<<nx<<" "<<ny<<endl;
                sx=nx;sy=ny;
            }
            else{
                d=(d+1)%4;
                //cout<<"转向于：x\y:"<<sx<<" "<<sy<<endl;
            }

        }
        cout<<ans<<endl;
        memset(vis,0,sizeof(vis));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
