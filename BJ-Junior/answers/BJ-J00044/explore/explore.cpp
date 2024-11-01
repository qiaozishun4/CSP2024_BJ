#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
string s[N];
bool vis[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){

        int n,m,k,cnt=1,x,y,d,dx,dy;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
        cin>>n>>m>>k>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        for(int i=1;i<=k;i++){
            dx=x;
            dy=y;
            if(d==0){
                dy++;
            }else if(d==1){
                dx++;
            }else if(d==2){
                dy--;
            }else if(d==3){
                dx--;
            }
            if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&s[dx][dy-1]=='.'){
                //cout<<vis[dx][dy]<<endl;
                if(!vis[dx][dy])cnt++;
                //cout<<dx<<' '<<dy<<endl;
                vis[dx][dy]=1;
                x=dx;
                y=dy;
            }else{
                d=(d+1)%4;
                //cout<<'|'<<d<<endl;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}