#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int tt,n,m,k,x,y,d;
char map1[1000][10000];
int f[10000][10000];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>tt;
    while(tt--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;i++){
                cin>>map1[i][j];
                f[i][j]=0;
            }
        }
        f[x][y]=1;
        for(int i=0;i<n+m;i++){
            map1[i][0]='x';
            map1[0][i]='x';
            map1[n+1][i]='x';
            map1[i][m+1]='x';

        }
        while(k--){
            if(map1[x+dx[d]][y+dy[d]]=='x') d=(d+1)%4;
            else{
                x+=dx[d];
                y+=dy[d];
                f[x][y]=1;

            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
        for(int j=1;i<=m;j++){
        if(f[i][j]==1) ans++;
        }
        }
        cout<<ans<<endl;
    }
    return 0;
}