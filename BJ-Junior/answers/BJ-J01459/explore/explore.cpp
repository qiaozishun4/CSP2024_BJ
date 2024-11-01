#include <bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int t, n, m, k;
int x, y, d;
char a[1005][1005];
bool b[1005][1005];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i=1;i<=n;i++){
                string s; cin >> s;
            for(int j=1;j<=m;j++) a[i][j]=s[j-1];
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) b[i][j]=0;
        int ans=1; b[x][y]=1;
        while(k--){
            int nx=x+dx[d], ny=y+dy[d];
            if(nx>=1 and nx<=n and ny>=1 and ny<=m and a[nx][ny]=='.'){
                x=nx,y=ny;
                if(!b[nx][ny]){
                    b[nx][ny]=1;
                    ans++;
                }
            }else{
                d=(d+1)%4;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
