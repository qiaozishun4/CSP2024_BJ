#include <bits/stdc++.h>

using namespace std;

struct rbt{
    int x;
    int y;
    int d;
};
struct rbt crbt;
char mapn[1005][1005];
bool visit[1005][1005];
int main()
{

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,cnt=1;
    cin>> t;
    for (int i=1;i<=t; i++){
        cin >> n >> m >> k;
        cin >> crbt.x >> crbt.y >> crbt.d;
        memset(visit,0, sizeof(visit));
        cnt=1;int cnt2=1;visit[crbt.x][crbt.y]=true;
        for (int j=1; j<=n; j++)
            for (int l=1; l<=m; l++)
               cin >> mapn[j][l];
        for (int o=1; o<=k; o++){
            int nx;int ny;
            if (crbt.d==0) {
                nx=crbt.x;ny=crbt.y+1;
            }
            if (crbt.d==1) {
                nx=crbt.x+1;ny=crbt.y;
            }
            if (crbt.d==2) {
                nx=crbt.x;ny=crbt.y-1;
            }
            if (crbt.d==3) {
                nx=crbt.x-1;ny=crbt.y;
            }
            if (nx>=1 && nx<=n && ny>=1 && ny<=m && mapn[nx][ny]=='.' ){
                crbt.x=nx;crbt.y=ny; cnt2++;
                if (!visit[nx][ny]) {
                    cnt++;
                    visit[nx][ny]=true;
                }
            }
            else {
                crbt.d= (crbt.d+1)%4;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}