#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,fa,ans;
char s[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool f[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>fa;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s[i][j];
            }
        }
        memset(f,0,sizeof(f));
        ans=1;
        f[x][y]=1;
        while(k--){
            int vx=x+dx[fa],vy=y+dy[fa];
            if(vx<1||vx>n||vy<1||vy>m||s[vx][vy]=='x'){
                fa=(fa+1)%4;
                continue;
            }
            x=x+dx[fa],y=y+dy[fa];
            if(f[x][y]==0)ans++;
            f[x][y]=1;

        }
        cout<<ans<<endl;
    }

    return 0;
}
