#include <bits/stdc++.h>
using namespace std;

int t;
bool a[1145][1145];
bool vis[1145][1145];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        int n,m,k,x,y,p;
        cin>>n>>m>>k;
        cin>>x>>y>>p;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='.')a[i][j]=1;
                else a[i][j]=0;
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        for(int kk=1;kk<=k;kk++){
            if(a[x+dx[p]][y+dy[p]]){
                x+=dx[p],y+=dy[p];
                vis[x][y]=1;
            }
            else p=(p+1)%4;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(vis[i][j])cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
