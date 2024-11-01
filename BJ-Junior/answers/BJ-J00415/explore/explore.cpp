#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int t,n,m,k;
char a[1005][1005];
bool b[1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(int x, int y, int d){
    for(int i = 1;i<=k;i++){
        b[x][y] = 1;
        int tx = x+dx[d];
        int ty = y+dy[d];
        if(a[tx][ty]=='.'&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
           x+=dx[d];
           y+=dy[d];
        }else{
            d = (d+1)%4;
        }
    }
    b[x][y] = 1;
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int l = 1;l<=t;l++){
        int ans;
        int x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        memset(b,0,sizeof(0));
        dfs(x,y,d);
        ans = 0;
        for(int i  = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(b[i][j] == 1) ans++;
                cout<<b[i][j];
            }
            cout<<endl;
        }
        cout<<ans;
    }

    return 0;
}
