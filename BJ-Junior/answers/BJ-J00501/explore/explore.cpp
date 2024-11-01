#include<bits/stdc++.h>
using namespace std;
string s;
char c[1005][1005];
bool vis[1005][1005];
long long n,T,m,k,x,y,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},ans=1;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        scanf("%lld %lld %lld",&n,&m,&k);
        scanf("%lld %lld %lld",&x,&y,&d);
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        vis[x][y]=1;
        while(k--){
            if(x+dx[d]>=1&&y+dy[d]>=1&&x+dx[d]<=n&&y+dy[d]<=m&&c[x+dx[d]][y+dy[d]]=='.'){
                x=x+dx[d];
                y=y+dy[d];
                if(!vis[x][y]){
                    ans++;
                    vis[x][y]=1;
                }
            }else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
        ans=1;
    }
    return 0;
}
