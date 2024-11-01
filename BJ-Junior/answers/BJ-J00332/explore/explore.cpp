#include <iostream>
#include <cstdio>
using namespace std;
char c[1005][1005];
bool b[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        for(int i=1;i<=1000;i++){
            for(int j=1;j<=1000;j++){
                b[i][j]=false;
            }
        }
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        b[x][y]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        while(k--){
            if(d==0&&y+1<=m&&c[x][y+1]=='.'){
                y++;
                b[x][y]=true;
            }else if(d==1&&x+1<=n&&c[x+1][y]=='.'){
                x++;
                b[x][y]=true;
            }else if(d==2&&y-1>=1&&c[x][y-1]=='.'){
                y--;
                b[x][y]=true;
            }else if(d==3&&x-1>=1&&c[x-1][y]=='.'){
                x--;
                b[x][y]=true;
            }else{
                d=(d+1)%4;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==true){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
