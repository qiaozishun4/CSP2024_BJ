#include <bits/stdc++.h>
using namespace std;

const int N=1e3+5;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int t,n,m,k;
char a[N][N];
bool vis[N][N];

void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i][j]=false;
        }
    }
    return;
}

int solve(int x,int y,int d){
    int tot=1;
    vis[x][y]=true;
    for(int i=1;i<=k;i++){
        int tx=x+dx[d],ty=y+dy[d];
        if(tx<1 || tx>n || ty<1 || ty>m ||a[tx][ty]=='x'){
            d=(d+1)%4;
        }
        else{
            x=tx,y=ty;
            if(!vis[x][y]) tot++;
            vis[x][y]=true;
        }
    }
    return tot;
}

int main(){
    //freopen("explore.in","w",stdout);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int ans=solve(x0,y0,d0);
        cout<<ans<<endl;
        init();
    }
    return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
