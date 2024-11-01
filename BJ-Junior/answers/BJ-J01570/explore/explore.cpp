#include<bits/stdc++.h>
using namespace std;
const int N=1007;
char a[N][N];
bool vis[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
        int sum=1;
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            if(d==0){
                if(y+1<=m&&a[x][y+1]=='.'){
                    y++;
                    if(!vis[x][y]){
                        sum++;
                        vis[x][y]=1;
                    }
                }
                else d=(d+1)%4;
            }
            else if(d==1){
                if(x+1<=m&&a[x+1][y]=='.'){
                    x++;
                    if(!vis[x][y]){
                        sum++;
                        vis[x][y]=1;
                    }
                }
                else d=(d+1)%4;
            }
            else if(d==2){
                if(y-1>=1&&a[x][y-1]=='.'){
                    y--;
                    if(!vis[x][y]){
                        sum++;
                        vis[x][y]=1;
                    }
                }
                else d=(d+1)%4;
            }
            else{
                if(x-1>=1&&a[x-1][y]=='.'){
                    x--;
                    if(!vis[x][y]){
                        sum++;
                        vis[x][y]=1;
                    }
                }
                else d=(d+1)%4;
            }
        }
        cout<<sum<<endl;
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
