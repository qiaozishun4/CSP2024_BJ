#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool vis[3000][3000];
bool jz[3000][3000];
int n,m,mcs,cs=0,cnt=0,cx=0;
void dfs(int x,int y){
    if(cs>mcs){
        exit(0);
    }
    for(int i=0;i<4;i++){
        if(cx==4){
            cx=0;
        }
        int nx=x+dx[cx],ny=y+dy[cx];
        cs++;
       // cout<<" 第： "<<cs<<" 次 "<<nx<<" "<<ny<<" "<<cx<<endl;


        if(nx>n||ny>m||nx<1||ny<1||cs>mcs||jz[nx][ny]==1){
            cx++;
            continue;
        }
        if(vis[nx][ny]==0){
            cnt++;

        }
        vis[nx][ny]=1;
        //cout<<cs<<" "<<nx<<" "<<ny<<endl;

        dfs(nx,ny);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cnt=0;
        cs=0;
        memset(vis,0,sizeof(vis));
        memset(jz,0,sizeof(jz));
        cin>>n>>m>>mcs;
        int sx,sy;
        cin>>sx>>sy>>cx;
        for(int i=1;i<=n;i++){
            string a;
            cin>>a;
            for(int j=0;j<m;j++){
                if(a[j]=='x'){
                    jz[i][j+1]=1;
                }
            }

        }
        dfs(sx,sy);
        if(vis[sx][sy]==0){
            cnt++;
        }
        cout<<cnt<<endl;

       /* for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<vis[i][j];
            }
            cout<<endl;
        }*/

    }











    return 0;
}
