#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
bool mp[N][N],vis[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                vis[i][j]=1;
                char TMP;
                cin>>TMP;
                mp[i][j]= TMP=='.' ? 0 : 1;
            }
        }
        int cnt=1;
        vis[x][y]=0;
        for (int i=1;i<=k;i++) {
            if (mp[x+dx[d]][y+dy[d]] || x+dx[d]<=0 || x+dx[d]>n || y+dy[d]<=0 || y+dy[d]>m) {
                d=(d+1)%4;
            }
            else {
                x+=dx[d];
                y+=dy[d];
                cnt+=vis[x][y];
                vis[x][y]=0;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
