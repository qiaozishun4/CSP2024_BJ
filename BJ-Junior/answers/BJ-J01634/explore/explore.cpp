#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char g[1001][1001];
int gg[1001][1001];
int n,m,k;
int x,y,d;
int sum=0;
void dfs(int x,int y){
    if(gg[x][y]==0){
        gg[x][y]=1;
        sum++;
    }
    if(k==0){
        cout<<sum<<endl;
        sum=0;
        return ;
    }
    k--;
    int xx=x+dx[d];
    int yy=y+dy[d];
    if(xx>0&&xx<=n&&yy>0&&yy<=m&&g[xx][yy]=='.'){
        dfs(xx,yy);
    }else{
        d=(d+1)%4;
        dfs(x,y);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int al;
    cin>>al;
    for(int i=0;i<al;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
                gg[i][j]=0;
            }
        }
        dfs(x,y);
    }
    return 0;
}

