#include <bits/stdc++.h>
using namespace std;
char mp[1050][1050];
int n,m,k;
int x,y,d;
int di[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
int is[1050][1050];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while (T--){
        memset(mp,0,sizeof(mp));
        memset(is,0,sizeof(is));
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) cin >> mp[i][j];
        is[x][y]++;
        for (int i = 1;i <= k;i++){
            x += di[d][0],y += di[d][1];
            if (x <= 0 || x > n || y <= 0 || y > m || mp[x][y] == 'x') x -= di[d][0],y -= di[d][1],d = (d + 1) % 4;
            is[x][y]++;
        }
        int cnt = 0;
        for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) if (is[i][j] > 0) cnt++;
        cout << cnt << endl;
    }
	return 0;
}