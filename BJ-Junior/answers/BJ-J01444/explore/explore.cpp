#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e3+7;
int a[MAX][MAX] = {};
int f[MAX][MAX] = {};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    int n,m,k,x,y,d;
    while(T--) {
        cin>>n>>m>>k>>x>>y>>d;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                char c;
                cin>>c;
                f[i][j] = 0;
                if(c == '.') a[i][j] = 0;

                else a[i][j] = 1;
            }
        }
        f[x][y] = 1;
        for(int i = 1;i <= k;i++) {
            if(d == 0 && y+1 <= m && a[x][y+1] == 0) {
                f[x][++y] = 1;
            }
            else if(d == 1 && x+1 <= n && a[x+1][y] == 0) {
                f[++x][y] = 1;
            }
            else if(d == 2 && y-1 > 0 && a[x][y-1] == 0) {
                f[x][--y] = 1;
            }
            else if(d == 3 && x-1 > 0 && a[x-1][y] == 0) {
                f[--x][y] = 1;
            }
            else {
                d++;
                d %= 4;
                f[x][y] = 1;
            }
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(f[i][j] == 1) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
