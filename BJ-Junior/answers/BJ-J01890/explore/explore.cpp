#include <bits/stdc++.h>
using namespace std;

int nxt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[1010][1010];
char c[1010][1010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        int n,m,k,x,y,d,ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        int sx=x,sy=y,rm=k;
        bool flag=true,fir=true;
        vis[x][y]=true;
        for(int j=d;;j=(j+1)%4){
            sx+=nxt[j][0],sy+=nxt[j][1];
            while(sx>=1 && sx<=n && sy>=1 && sy<=m && c[sx][sy]=='.'){
                if(!vis[sx][sy]) ans++,vis[sx][sy]=true;
                rm--;
                if(!rm){flag=false;break;}
                sx+=nxt[j][0],sy+=nxt[j][1];
            }
            sx-=nxt[j][0],sy-=nxt[j][1];
            if(!flag) break;
            rm--;
            if(rm==0) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
