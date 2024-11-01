#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,k;
int x,y,d;
char s[N][N];
int v[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int ans=1;
        memset(v,0,sizeof(v));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s[i][j];
                if(s[i][j]=='x'){
                    v[i][j]=2;
                }
            }
        }
        v[x][y]=1;
        for(int i=1;i<=k;i++){
            int nx=x+dis[d][0];
            int ny=y+dis[d][1];
            if(nx<1||nx>n||ny<1||ny>m||v[nx][ny]==2){
                d=(d+1)%4;
                continue;
            }
            if(v[nx][ny]==0){
                v[nx][ny]=1;
                ans++;
            }
            x=nx;
            y=ny;
        }
        cout<<ans<<endl;
    }
    return 0;
}
