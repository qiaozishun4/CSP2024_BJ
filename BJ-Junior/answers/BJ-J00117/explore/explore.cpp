#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
int k;
int x,y,d,ans;
char ch[1005][1005];
bool vis[1005][1005];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int x0,y0,d0;
        cin>>n>>m>>k>>x0>>y0>>d0;
        x=x0,y=y0,d=d0;
        ans=0;
        memset(vis,0,sizeof(vis));
        vis[x][y]=1;
        for(int j=1;j<=n;j++){
            for(int j2=1;j2<=m;j2++){
                cin>>ch[j][j2];
            }
        }
        for(int j=1;j<=k;j++){
            //cout<<x<<' '<<y<<' '<<d<<' '<<endl;
            if(d==0 && y+1<=m && ch[x][y+1]=='.'){
                y=y+1;
                vis[x][y]=1;
            }
            else if(d==1 && x+1<=n && ch[x+1][y]=='.'){
                x=x+1;
                vis[x][y]=1;
            }
            else if(d==2 && y-1>=1 && ch[x][y-1]=='.'){
                y=y-1;
                vis[x][y]=1;
            }
            else if(d==3 && x-1>=1 && ch[x-1][y]=='.'){
                x=x-1;
                vis[x][y]=1;
            }
            else{
                //cout<<d<<endl;
                d=(d+1)%4;
                //cout<<d<<endl;
            }
        }
        for(int j=1;j<=n;j++){
            for(int j2=1;j2<=m;j2++){
                if(vis[j][j2]==1){
                    //cout<<j<<" "<<j2<<endl;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
