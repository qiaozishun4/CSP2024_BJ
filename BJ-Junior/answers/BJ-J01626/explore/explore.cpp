#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int T,n,m,k,sx,sy,d,t,mx[10]={0,1,0,-1},my[10]={1,0,-1,0};
long long ans;
char mp[maxn][maxn];
bool f[maxn][maxn];
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&sx,&sy,&d);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                cin>>mp[i][j];
        t=ans=0;
        memset(f,false,sizeof(f));
        f[sx][sy]=true;
        ans++;
        while (t<k) {
            t++;
            int nx=sx+mx[d],ny=sy+my[d];
            if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.') {
                if (!f[nx][ny]) {
                    ans++;
                    f[nx][ny]=true;
                }
                sx=nx,sy=ny;
            }
            else
                d=(d+1)%4;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
