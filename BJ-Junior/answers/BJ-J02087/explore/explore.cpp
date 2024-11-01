#include <bits/stdc++.h>
using namespace std;
int n,m,k,T,d,x,y;
char a[114][114];
int vis[114][114];
struct nd
{
    int x,y;
};
int bfs(){
    memset(vis,0,sizeof vis);
    int cnt=0;
    nd u,p;
    p.x=x,p.y=y;
    vis[p.x][p.y]++;
    for(int i=1;i<=k;i++){
        u.x=p.x,u.y=p.y;
        if(d==0)    u.y+=1;
        if(d==1)    u.x+=1;
        if(d==2)    u.y-=1;
        if(d==3)    u.x-=1;
        if(u.x<=n&&u.y<=m&&u.x>0&&u.y>0&&a[u.x][u.y]=='.'){
            p.x=u.x,p.y=u.y;
            vis[p.x][p.y]++;
        }
        else{
            d=(d+1)%4;
        }
    }
    for(int i=1;i<=110;i++){
        for(int j=1;j<=110;j++){
            if(vis[i][j])   cnt++;
        }
    }
    return cnt;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        cout<<bfs()<<endl;
    }
    return 0;
}
