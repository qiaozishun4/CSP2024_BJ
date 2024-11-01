#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int vis[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main (){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    //cout<<t;
    while(t--){
        memset(vis,0,sizeof(vis));
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }

        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            int nx=dx[d]+x;
            int ny=dy[d]+y;
            if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x'){
                d=(d+1)%4;
            }else{
                x=nx;
                y=ny;
                vis[nx][ny]=1;
            }

        }
    //cout<<"fkl";
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
