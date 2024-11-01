#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
#define N 1005
int n,m,k;
char G[N][N];
bool f[N][N];
void rotate(int &d){
    d=(d+1)%4;
    return;
}
void move(int &x,int &y,int &d){
    int nx,ny;
    nx=x+dx[d];
    ny=y+dy[d];
    if(nx<1||nx>n||ny<1||ny>m){
        rotate(d);
        return;
    }
    if(G[nx][ny]=='x'){
        rotate(d);
        return;
    }
    x=nx,y=ny;
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int cnt=0;
        memset(G,'\0',sizeof(G));
        memset(f,0,sizeof(f));
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>G[i][j];
            }
        }
        f[x][y]=1;
        while(k--){
            move(x,y,d);
            f[x][y]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j]){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}