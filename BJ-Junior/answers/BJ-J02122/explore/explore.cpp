#include<bits/stdc++.h>
using namespace std;
char nmap[1005][1005];
bool vis[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int t,n,m,k,cnt=0;
bool chk(int a,int b){
    if(a>0&&a<=n&&b>0&&b<=m&&nmap[a][b]=='.')return true;
    return false;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(vis,0,1010025);
        cnt=0;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>nmap[i][j];
        }
        for(int i=1;i<=k;i++){
            if(chk(x+dx[d],y+dy[d])){
                x+=dx[d];
                y+=dy[d];
                vis[x][y]=1;
            }
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j])cnt++;
            }
        }
    cout<<cnt<<endl;
    }
    return 0;
}
