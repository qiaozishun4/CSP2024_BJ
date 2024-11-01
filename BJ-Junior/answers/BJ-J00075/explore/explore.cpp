#include<iostream>
using namespace std;
int t,n,m,k,x,y,d,go[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char a[3001][3001];
bool b[3001][3001];
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--) {
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>a[i][j];
                b[i][j]=false;
            }
        }
        b[x][y]=true;
        while(k--) {
            int nx=x+go[d][0],ny=y+go[d][1];
            if(nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]!='x') {
                x=nx;
                y=ny;
                b[x][y]=true;
            }
            else d=(d+1)%4;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(b[i][j])
                    ans++;
        cout<<ans<<endl;
    }
    return 0;
}