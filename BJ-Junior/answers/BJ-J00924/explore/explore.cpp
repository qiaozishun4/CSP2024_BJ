#include<bits/stdc++.h>
using namespace std;
int startx,starty;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int T;
bool vis[1001][1001];
char a[1001][1001];
int n,m,k,d,cnt;
void dfs(int x,int y,int step){
    if (step>=k)
        return ;
    for (int i=0;i<4;i++){
        int tx,ty;
        tx=x+dx[i];
        ty=y+dy[i];
        if (tx>0&&tx<=n&&ty>0&&ty<=m){
            if (a[tx][ty]=='.'){
                cnt++;
                a[tx][ty]='x';
                dfs(tx,ty,step+1+i);
            }
        }
    }
}
//rp++
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while (T--){
        memset(vis,1,sizeof(vis));
        cin>>n>>m>>k>>startx>>starty>>d;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        cnt=0;
        if (k<d){
            cout<<1<<endl;
            continue;
        }
        a[startx][starty]='x';
        dfs(startx,starty,d);
        cout<<cnt<<endl;
    }
    return 0;
}
