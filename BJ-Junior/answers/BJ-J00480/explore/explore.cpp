#include<bits/stdc++.h>//long long
using namespace std;
int s[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int a[1100][1100];
bool vis[1100][1100];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    int n,m,k,x,y,d;
    char c;
    cin>>T;
    for(int t=1;t<=T;t++){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                if(c=='.')a[i][j]=1;
                else a[i][j]=0;
                //cout<<a[i][j];
            }//cout<<endl;
        }

        vis[x][y]=1;
        int ans=1;
        for(int tmp=0;tmp<k;tmp++){
            int nx=x+s[d][0];
            int ny=y+s[d][1];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]){
                x=nx;
                y=ny;
                if(vis[x][y]==0){
                    ans++;
                    vis[x][y]=1;
                }
                continue;
            }
            d=(d+1)%4;
        }
        cout<<ans<<endl;
    }
    return 0;
}
