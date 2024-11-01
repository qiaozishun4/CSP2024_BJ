#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
int d,xn,y;
int k,n,m,t;
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        for(int i=0;i<=1004;i++){
            for(int j=0;j<=1004;j++){
                vis[i][j]=0;
            }
        }
        cin>>n>>m>>k;
        cin>>xn>>y>>d;
        vis[xn][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[j][i];
            }
        }
        int num=1;
        while(k--){
            int nx=xn,ny=y;
            vis[xn][y]=1;
            if(d==0){
                ny++;
            }
            if(d==1){
                nx++;
            }
            if(d==2){
                ny--;
            }
            if(d==3){
                nx--;
            }
            if(ny>m||ny<1||nx>n||nx<1||a[ny][nx]=='x'){
                d=(d+1)%4;
                continue;
            }
            xn=nx;
            y=ny;
            if(vis[xn][y]==0){

                num++;
            }
        }
        cout<<num<<endl;
    }

    return 0;
}
