#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int vis[1001][1001];//1 no    2 visited
char mapofr[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i = 1;i<=t;i++){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>x>>y>>d;
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=m;k++){
                cin>>mapofr[j][k];
                if(mapofr[j][k]=='x')
                    vis[j][k]=1;
            }
        }
        int v=x,u=y,d1=d;
        vis[x][y] = 2;
        for(int j = 1;j<=k;j++){
            if(v+dx[d1]>=1&&v+dx[d1]<=n&&u+dy[d1]>=1&&u+dy[d1]<=m&&vis[v+dx[d1]][u+dy[d1]]!=1){
                v+=dx[d1];
                u+=dy[d1];
                vis[v][u]=2;
            }
            else{
                d1=(d1+1)%4;
            }
        }
        int ans = 0;
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=m;k++){
                if(vis[j][k]==2)
                    ans++;
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}
