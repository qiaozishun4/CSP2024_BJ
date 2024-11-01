#include <bits/stdc++.h>
using namespace std;

int n,m,k,x,y,d;
char a[1005][1005];

inline bool init(int x,int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                cin >> a[i][j];
        a[x][y] = '*';
        while(k--){
            if(d == 0){
                if(init(x,y + 1) && a[x][y + 1] != 'x') a[x][++y] = '*';
                else d = (d + 1) % 4;
            }else if(d == 1){
                if(init(x + 1,y) && a[x + 1][y] != 'x') a[++x][y] = '*';
                else d = (d + 1) % 4;
            }else if(d == 2){
                if(init(x,y - 1) && a[x][y - 1] != 'x') a[x][--y] = '*';
                else d = (d + 1) % 4;
            }else{
                if(init(x - 1,y) && a[x - 1][y] != 'x') a[--x][y] = '*';
                else d = (d + 1) % 4;
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++) if(a[i][j] == '*') ans++;
        cout << ans << '\n';
    }
    return 0;
}
