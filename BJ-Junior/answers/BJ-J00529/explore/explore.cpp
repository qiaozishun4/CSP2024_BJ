#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
bool v[1009][1009];
char a[1009][1009];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(v,0,sizeof(v));
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        v[x][y]=1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for (int i=1;i<=k;i++){
            int nx=x+dx[d],ny=y+dy[d];
            if (nx>n||nx<1||ny>m||ny<1||a[nx][ny]=='x'){
                d=(d+1)%4;
            }
            else{
                v[nx][ny]=1;
                x=nx;
                y=ny;
            }
        }
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (v[i][j]){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}