#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,cnt=1;
char c[1005][1005];
bool b[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cnt=0;
        memset(b,0,sizeof(b));
        cin>>n>>m>>k>>x>>y>>d;
        b[x][y]=1;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>c[i][j];
        for(int i=1;i<=k;i++){
            if(d==0&&y+1<=m&&c[x][y+1]=='.'){
                y++;
                b[x][y]=1;
            }else if(d==1&&x+1<=n&&c[x+1][y]=='.'){
                x++;
                b[x][y]=1;
            }else if(d==2&&y-1>0&&c[x][y-1]=='.'){
                y--;
                b[x][y]=1;
            }else if(d==3&&x-1>0&&c[x-1][y]=='.'){
                x--;
                b[x][y]=1;
            }else d=(d+1)%4;
        }for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(b[i][j])cnt++;
        cout<<cnt<<"\n";
    }return 0;
}
