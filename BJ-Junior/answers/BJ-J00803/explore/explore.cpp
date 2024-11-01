#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1010
using namespace std;
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
int t,n,m,k,x,y,d,cnt;
char _map[maxn][maxn];
bool vis[maxn][maxn];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int cnt=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>_map[j][k];
                vis[j][k]=0;
            }
        }
        for(int i=1;i<=k;i++){
            if(vis[x][y]==0){
                cnt++;
                vis[x][y]=1;
            }
            int xx=x+dx[d],yy=y+dy[d];
            if(xx<1||yy<1||xx>n||yy>m||_map[xx][yy]=='x'){
                d=(d+1)%4;
                continue;
            }
            else{
                x=xx,y=yy;
            }
            if(vis[xx][yy]==0){
                cnt++;
                vis[xx][yy]=1;
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}