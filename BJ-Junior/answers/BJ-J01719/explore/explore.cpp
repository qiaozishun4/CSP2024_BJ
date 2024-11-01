#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool vis[1001][1001];
int cnt=0,nx,ny,n,m,k,X[]={0,1,0,-1},Y[]={1,0,-1,0};
char gch(){ char h=getchar();if(h!='\n')return h;h=getchar();return h; }
void DFS(int x,int y,int d,int csx){
    //cout<<x<<" "<<y<<" "<<d;
    if(csx>k)return ;
    if(!vis[x][y])cnt++,vis[x][y]=true;
    nx=x+X[d],ny=y+Y[d];
    if(nx<1||nx>n||ny<1||ny>m)DFS(x,y,(d+1)%4,csx+1);
    else if(a[nx][ny]=='x')DFS(x,y,(d+1)%4,csx+1);
    else if(a[nx][ny]=='.'&&nx>=1&&nx<=n&&ny<=1&&ny>=m)DFS(nx,ny,d,csx+1);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,x,y,d;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=gch();
        if(x==1&&y==1){ cout<<"1";continue; }
        cnt=0;
        DFS(x,y,d,1);
        cout<<cnt<<endl;
    }
    return 0;
}
