#include<bits/stdc++.h>
using namespace std;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
short vis[1111][1111];
bool ch(int x,int y,int n,int m){
    if(x>n||x<1||y>m||y<1||vis[x][y]==-1)return 0;
    return 1;
}
void Main(){
    for(int i=1;i<=1000;i++)for(int j=1;j<=1000;j++)vis[i][j]=-1;
    int n,m,k,x,y,d;
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='.')vis[i][j]=0;
        }
    }
    vis[x][y]=1;
    while(k--){
        x+=dir[d][0],y+=dir[d][1];
        if(ch(x,y,n,m)){vis[x][y]=1;}
        else {
            x-=dir[d][0],y-=dir[d][1];
            d=(d+1)%4;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                if(vis[i][j]==1)ans++;
        }
    }
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)Main();
    return 0;
}
