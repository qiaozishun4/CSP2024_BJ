#include<bits/stdc++.h>
using namespace std;
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int s[2010][2010],n,m,k;
bool vis[2010][2010];
void f(int dep,int d,int x,int y){
    for(int i=1;i<=k;i++){
        int newx=x+xx[d],newy=y+yy[d];
         if(s[newx][newy]==1){
            vis[newx][newy]=1;
            x=newx,y=newy;
         }
         else d=(d+1)%4;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(s,-1,sizeof(s));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        int x,y,d,cnt=0;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='.') s[i][j]=1;
            }
        }
        vis[x][y]=1;
        f(1,d,x,y);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]) cnt++;
            }
        }
        if(t==0) cout<<cnt;
        else cout<<cnt<<endl;
    }
    return 0;
}
