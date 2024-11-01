#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d,cnt;
char a[1010][1010];
int s[4][2]={{0,1},{1,0},{0,-1},{-1,0}},vis[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cnt=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++){
                cin>>a[j][p];
            }
        }
        vis[x][y]=1;
        for(int j=1;j<=k;j++){
            int nx,ny;
            nx=x+s[d][0];
            ny=y+s[d][1];
            if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x'){
                d=(d+1)%4;
            }
            else{
                x=nx;
                y=ny;
                vis[x][y]=1;
            }
        }
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++){
                if(vis[j][p]){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}