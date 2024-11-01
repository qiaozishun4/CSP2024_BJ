#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char a[1010][1010];
bool v[1010][1010];
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(v,0,sizeof(v));
        int n,m,k;
        cin >> n >> m >> k;
        int x,y,d;
        cin >> x >> y >> d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        v[x][y]=1;
        while(k--){
            int xx=x+dx[d],yy=y+dy[d];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
                v[xx][yy]=1;
                x=xx;
                y=yy;
            }
            else{
                d=(d+1)%4;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(v[i][j]){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
