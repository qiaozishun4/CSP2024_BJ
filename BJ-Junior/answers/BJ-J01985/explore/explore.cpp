#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
long long t,n,m,k,x,y,d;
char e[1015][1015];
int f[1015][1015];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>e[i][j];
                f[i][j]=0;
            }
        }
        f[x][y]=1;
        for(int i=0;i<n+m;i++){
            e[i][0]='x';
            e[0][i]='x';
            e[n+1][i]='x';
            e[i][m+1]='x';
        }
        while(k--){
            if(e[x+dx[d]][y+dy[d]]=='x') d=(d+1)%4;
            else{
                x+=dx[d];
                y+=dy[d];
                f[x][y]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j]==1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
