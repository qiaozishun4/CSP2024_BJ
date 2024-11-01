#include <bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int T;
char mp[N][N];
bool vis[N][N];
bool check(int n,int m,int x,int y){
    return 1<=x&&x<=n&&1<=y&&y<=m&&mp[x][y]!='x';
}
int main()
{
    freopen("explore.in","r",stdin);//记得换成explore.in
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,k;
        long long ans=0;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        vis[x][y]=1;ans++;
        while(k--){
            if(d==0){
                if(check(n,m,x,y+1)){
                    ans+=!vis[x][++y];
                    vis[x][y]=1;
                }
                else d=(d+1)%4;
            }
            else if(d==1){
                if(check(n,m,x+1,y)){
                    ans+=!vis[++x][y];
                    vis[x][y]=1;
                }
                else d=(d+1)%4;
            }
            else if(d==2){
                if(check(n,m,x,y-1)){
                    ans+=!vis[x][--y];
                    vis[x][y]=1;
                }
                else d=(d+1)%4;
            }
            else if(d==3){
                if(check(n,m,x-1,y)){
                    ans+=!vis[--x][y];
                    vis[x][y]=1;
                }
                else d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
    }
    return 0;//0->east 1->south 2->west 3->north
}

