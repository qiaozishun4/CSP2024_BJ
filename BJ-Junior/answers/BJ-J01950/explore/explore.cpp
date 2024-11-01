#include<bits/stdc++.h>
using namespace std;
const int mod=4;
int t,n,m,d,k,x,y,now,kk,ans,px,py,cnt,l;
int f[1005][1005];
char mp[1005][1005];
bool v[1005][1005];
int xx[5]={0,1,0,-1};
int yy[5]={1,0,-1,0};
void bfs(){
    while(1){
        //cout<<px<<' '<<py<<' '<<now<<'\n';
        v[px][py]=1;
        if(now==k||(d==f[px][py]&&l)) return;
        l++;
        for(kk=0;kk<4;kk++){
            if(now==k) return;
            if(mp[px+xx[d]][py+yy[d]]=='x'){
                d++;
                d%=mod;
                now++;
                if(now==k) return;
                continue;
            }
            now++;
            f[px][py]=d;
            px=px+xx[d];
            py=py+yy[d];
            break;
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        ans=0;
        now=0;
        l=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        int i,j;
        for(i=0;i<=n+1;i++){
            for(j=0;j<=m+1;j++) mp[i][j]='x';
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                cin>>mp[i][j];
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++) v[i][j]=0;
        for(i=1;i<=n;i++) for(j=1;j<=m;j++) f[i][j]=-1;
        px=x;
        py=y;
        f[x][y]=d;
        bfs();
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            ans+=v[i][j];
        cout<<ans<<'\n';
    }
    return 0;
}
