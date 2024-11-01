#include<bits/stdc++.h>
using namespace std;
int cmp;
int m,n,k;
int x,y,d;
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
char f[1001][1001];
int vis[1001][1001];
int u,v,sum=0;
void dfs(){
    cin>>m>>n>>k;
    cin>>x>>y>>d;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>f[i][j];
            vis[i][j]=1;
        }
    }
    sum=1;
    vis[x][y]=0;
    while(k>0){
        u=x+xx[d];
        v=y+yy[d];
        if(u<1 || u>m || v<1 || v>n ||f[u][v]=='x'){
            d=(d+1)%4;
            k--;
        }else{
            x=u;
            y=v;
            k--;
            sum+=vis[x][y];
            vis[x][y]=0;
        }
    }
    cout<<sum<<endl;

}
int main(){
    cin>>cmp;
    for(int i=0;i<cmp;i++){
        dfs();
}
    return 0;
}
