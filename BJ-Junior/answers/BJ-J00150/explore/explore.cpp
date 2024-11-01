#include<cstdio>
#include<iostream>
using namespace std;
bool vis[1005][1005],za[1005][1005];
int dr[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x0,y0,d0,step=1;
        cin>>n>>m>>k>>x0>>y0>>d0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                vis[i][j]=za[i][j]=0;
            }
        }
        vis[x0][y0]=1;
        char a;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a;
                if(a=='x') za[i][j]=1;
            }
        }
        for(int i=0;i<k;i++){
            int dx=x0+dr[d0][0],dy=y0+dr[d0][1];
            if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&!za[dx][dy]){
                x0=dx;
                y0=dy;
                if(!vis[x0][y0]){
                    vis[x0][y0]=1;
                    step++;
                }
            }
            else{
                d0=(d0+1)%4;
            }
        }
        cout<<step<<'\n';
    }
    return 0;
}
