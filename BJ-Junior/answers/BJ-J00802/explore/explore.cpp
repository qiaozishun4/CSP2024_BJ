#include<bits/stdc++.h>
const int N=1e3+114;
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t=1;
    cin>>t;
    while(t--){
        int n,m,k;

        cin>>n>>m>>k;

        int x,y,d;

        cin>>x>>y>>d;

        char mp[N][N];
        bool vis[N][N]={0};
        int cnt=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            int tx=x+dx[d];
            int ty=y+dy[d];
            if(tx<1 || tx>n ||ty<1 || ty>m ||mp[tx][ty]=='x'){
                d=(d+1)%4;
            }else{
                x=tx,y=ty;
                if(!vis[tx][ty]){
                    cnt++;
                    vis[tx][ty]=1;
                }
            }
        }

        cout<<cnt<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
