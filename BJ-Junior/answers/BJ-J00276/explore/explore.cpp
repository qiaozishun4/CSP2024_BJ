#include <iostream>
#include <cstring>
using namespace std;
char p[1005][1005];
int n,m,T,k;
bool vis[1005][1005];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        memset(p,' ',sizeof(p));
        memset(vis,false,sizeof(vis));
        cin>>n>>m>>k;
        int x,y,d;
        long long ans=1;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>p[i][j];
            }
        }
        vis[x][y]=1;
        while(k--){
            if(d==0){
                if(y+1<=m&&p[x][y+1]=='.') y++;
                else d++;
            }else if(d==1){
                if(x+1<=n&&p[x+1][y]=='.') x++;
                else d++;
            }else if(d==2){
                if(y-1>=1&&p[x][y-1]=='.') y--;
                else d++;
            }else{
                if(x-1>=1&&p[x-1][y]=='.') x--;
                else d=0;
            }
            if(!vis[x][y]){
                vis[x][y]=1;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
