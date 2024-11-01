#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    while(t--){
            int n,m,k,cnt=1;
        cin>>n>>m>>k;
        char ls[1011][1011];
       int x,y,d;

        cin>>x>>y>>d;
        int vis[1011][1011]={0};
        vis[x][y]=1;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>ls[i][j];
        for(int i=1;i<=k;i++){
            if(d==0){int t=0;
                if(1<=x&&x<=n&&1<=y+1&&y+1<=m&&ls[x][y+1]=='.'){
                        y++;
                        cnt++;
                        t=1;
                        if(vis[x][y]==0)vis[x][y]=1;
                }
                else {
                    d=(d+1)%4;
                }
                //if(i==k&&t)cnt++;
                //cout<<i<<' '<<x<<' '<<y<<' '<<d<<' '<<cnt<<endl;
            }else if(d==1){
                int t=0;
                if(1<=x+1&&x+1<=n&&1<=y&&y<=m&&ls[x+1][y]=='.'){
                        x++;
                        if(vis[x][y]==0)cnt++;t=1;vis[x][y]=1;
                }
                else {
                    d=(d+1)%4;
                }
                //if(i==k&&t)cnt++;
                 //cout<<i<<' '<<x<<' '<<y<<' '<<d<<' '<<cnt<<endl;
            }else if(d==2){int t=0;
                if(1<=x&&x<=n&&1<=y-1&&y-1<=m&&ls[x][y-1]=='.'){
                        y--;
                        if(vis[x][y]==0)cnt++;t=1;vis[x][y]=1;
                }
                else {
                    d=(d+1)%4;
                }//if(i==k&&t)cnt++;
                 //cout<<i<<' '<<x<<' '<<y<<' '<<d<<' '<<cnt<<endl;
            }else if(d==3){int t=0;
                if(1<=x-1&&x-1<=n&&1<=y&&y<=m&&ls[x-1][y]=='.'){
                        x--;
                        if(vis[x][y]==0)cnt++;t=1;vis[x][y]=1;

                }
                else {
                    d=(d+1)%4;
                }//if(i==k&&t)cnt++;
                 //cout<<i<<' '<<x<<' '<<y<<' '<<d<<' '<<cnt<<endl;
            }
        }
        cout<<endl;
cout<<cnt;
    }

return 0;
}

