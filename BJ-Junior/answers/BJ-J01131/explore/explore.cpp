#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x0,y0,d0,x,y,d;
        cin>>x0>>y0>>d0;
        x=x0,y=y0,d=d0,vis[x0][y0]==true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k--){
            x=dx[d]+x,y=dy[d]+y;
            if(x<1 || x>n || y<1 || y>m || a[x][y]=='x'){
                    d=(d+1)%4;
                    continue;
            }
            vis[x][y]=true;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j])cnt++;
                vis[i][j]=false;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
